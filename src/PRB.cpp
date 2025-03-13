#include "PRB.hpp"
#include "ChannelManager.hpp"

PRB::PRB(int id, int slot) : id(id), slot(slot) {
    int prbOffsetInTime = 20 * 14 * slot;
    int prbOffsetInFrequency = 20 * 12 * id;
    // Create ResourceElements
    for (int i = 0; i < 14*12 ; ++i) {
        resourceElements.emplace_back(i,
                i % 14 * 20 + prbOffsetInTime, 
                i / 14 * 20 + prbOffsetInFrequency,
                Channel::PDSCH);
    }
    resourceElements[50].setChannel(Channel::PBCH);
    resourceElements[40].setChannel(Channel::PDCCH);
    //printf("ID=%d : %s\n", resourceElements[50].getId(), resourceElements[50].getChannelName().c_str());
}

void PRB::draw(sf::RenderWindow& window, sf::View& view) {


    // Load font
    sf::Font font;
    if (!font.loadFromFile("Aloevera.ttf")) {
        printf("Font not available");
    } 
    // Current view bounderies 
    sf::FloatRect viewBounds(view.getCenter() - view.getSize() / 2.f, view.getSize());

    for ( auto& resourceElement : resourceElements) {
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

int PRB::getSlot() const {
    return this->slot;
}

sf::Vector2f PRB::getPosition() const {
    return sf::Vector2f(0, 0);
}

sf::FloatRect PRB::getBounds() const {
    sf::Vector2f position = this->resourceElements[0].getPosition(); 
    sf::Vector2f size = {this->resourceElements[0].getSize() * 14.0f, 
        this->resourceElements[0].getSize() * 12.0f};
    return sf::FloatRect(position, size);
}
