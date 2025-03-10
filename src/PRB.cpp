#include "PRB.hpp"
#include "ChannelManager.hpp"

PRB::PRB(int id, int slot) : id(id), slot(slot) {
    int prbOffsetInTime = 20 * 14 * slot;
    int prbOffsetInFrequency = 20 * 12 * id;
    // Create ResourceElements
    for (int i = 0; i < 14*12 ; ++i) {
        prb.emplace_back(i, 
                i % 14 * 20 + prbOffsetInTime, 
                i / 14 * 20 + prbOffsetInFrequency,
                Channel::PDSCH);
    }
}

void PRB::draw(sf::RenderWindow& window) {


    // Load font
    sf::Font font;
    if (!font.loadFromFile("Aloevera.ttf")) {
        printf("Font not available");
    } 
    sf::View view = window.getDefaultView();
    // Current view bounderies 
    sf::FloatRect viewBounds(view.getCenter() - view.getSize() / 2.f, view.getSize());

    for ( auto& resourceElement : prb) {
        // Check if ResourceElement is inside the view
        sf::FloatRect resourceElementBounds = resourceElement.getBounds();
        if (viewBounds.intersects(resourceElementBounds)) {
            resourceElement.draw(window);

            // Draw ResourceElement ID
            sf::Text idText(std::to_string(resourceElement.getId()), font, 12);

            idText.setFillColor(sf::Color::Black);
            idText.setPosition(resourceElement.getPosition());
            window.draw(idText);
        }
    }
}

int PRB::getId() const {
    return this->id;
}

sf::Vector2f PRB::getPosition() const {
    return sf::Vector2f(0, 0);
}

sf::FloatRect PRB::getBounds() const {
    return sf::FloatRect();
}
