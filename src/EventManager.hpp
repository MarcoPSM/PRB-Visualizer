#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <SFML/Graphics.hpp>

class EventManager {
    public:
        void handleEvent(sf::Event& event, sf::RenderWindow& window, sf::View& view, float& zoomLevel, bool& isDragging, sf::Vector2f& lastMousePosition); 

        void updateView(sf::RenderWindow& window, sf::View& view, bool& isDragging, sf::Vector2f& lastMousePosition, float moveThreshold);

    private:
        void handleMouseWheelScroll(const sf::Event& event, sf::RenderWindow& window, sf::View& view, float& zoomLevel);
        void handleKeyPress(const sf::Event& event, sf::View& view);
};

#endif //EVENTMANAGER_HPP
