#include "Application.hpp"

Application::Application() : window(sf::VideoMode(800, 600), "PRB Visualizer") {
        // Inicialização de recursos
        if (!font.loadFromFile("Aloevera.ttf")) {
            // Tratar erro de carregamento da fonte
        }
        // Gerar PRBs
        //PRB prb(0, 0);
        prbs.emplace_back(0,0);
        prbs.emplace_back(1,0);
        prbs.emplace_back(0,1);
    }

    void Application::run() {
        while (window.isOpen()) {
            handleEvents();
            update();
            render();
        }
    }

    void Application::handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            eventManager.handleEvent(event, window, view, zoomLevel, isDragging, lastMousePosition);
        }
    }

    void Application::update() {
        // Lógica de atualização
        eventManager.updateView(window, view, isDragging, lastMousePosition, moveThreshold);
    }

    void Application::render() {
        window.clear();
        sf::FloatRect viewBounds(view.getCenter() - view.getSize() / 2.f, view.getSize());
        for (auto& prb : prbs) {
            /*
            if (viewBounds.intersects(prb.getBounds())) {
                prb.draw(window);
                sf::Text idText(std::to_string(prb.getId()), font, 12);
                idText.setFillColor(sf::Color::Black);
                idText.setPosition(prb.getPosition());
                window.draw(idText);
            }
            */
            prb.draw(window);
        }
        window.display();
    }

