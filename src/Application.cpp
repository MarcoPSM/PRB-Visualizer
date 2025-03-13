#include "Application.hpp"
#include "parser/ParserFactory.hpp"

Application::Application() : window(sf::VideoMode(800, 600), "PRB Visualizer") {
    // Resource initialization 
    if (!font.loadFromFile("Aloevera.ttf")) {
        // Error handling
    }
    // Create PRBs
    //PRB prb(0, 0);
    /*
       prbs.emplace_back(0,0);
       prbs.emplace_back(1,0);
       prbs.emplace_back(0,1);
       */
}

void Application::run() {

    // Create PRBs
    if (parser) {
        int totalPrbs = parser->parseTotalPrbs();
        int totalSlots = parser->parseTotalSlots();
        printf( "Total PRBs: %d\n", totalPrbs);
        for (int i = 0; i < totalPrbs; i++) {
            for (int j = 0; j < totalSlots; j++) {
                prbs.emplace_back(i,j);
            }
        }
    } else {
        printf( "Failed to create parser.");
        return ;
    }

    // UPDATE PRBS
    // ...

    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Application::setParser(std::string filePath) {
    this->parser = ParserFactory::createParser(filePath); 
}

void Application::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        eventManager.handleEvent(event, window, view, zoomLevel, isDragging, lastMousePosition);
    }
}

void Application::update() {
    eventManager.updateView(window, view, isDragging, lastMousePosition, moveThreshold);
}

void Application::render() {
    
    sf::Vector2f pos =  view.getCenter() - view.getSize() / 2.f;
    
    window.clear();
    sf::FloatRect viewBounds(view.getCenter() - view.getSize() / 2.f, view.getSize());
    for (auto& prb : prbs) {

        if (viewBounds.intersects(prb.getBounds())) {
            prb.draw(window, view);
            /*
               sf::Text idText(std::to_string(prb.getId()), font, 12);
               idText.setFillColor(sf::Color::Black);
               idText.setPosition(prb.getPosition());
               window.draw(idText);
               */
        }
    }
    window.display();
}

