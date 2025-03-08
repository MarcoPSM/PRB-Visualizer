#include "EventManager.hpp"


void EventManager::handleEvent(sf::Event& event, sf::RenderWindow& window, sf::View& view, float& zoomLevel, bool& isDragging, sf::Vector2f& lastMousePosition) {
    switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;

        case sf::Event::MouseWheelScrolled:
            handleMouseWheelScroll(event, window, view, zoomLevel);
            break;

        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Middle) {
                isDragging = true;
                lastMousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            }
            break;

        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Middle) {
                isDragging = false;
            }
            break;

        case sf::Event::KeyPressed:
            handleKeyPress(event, view);
            break;

        default:
            break;
    }
}

void EventManager::updateView(sf::RenderWindow& window, sf::View& view, bool& isDragging, sf::Vector2f& lastMousePosition, float moveThreshold) {
    if (isDragging) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f newMousePosition = window.mapPixelToCoords(mousePosition);
        sf::Vector2f delta = lastMousePosition - newMousePosition;

        if (std::abs(delta.x) > moveThreshold || std::abs(delta.y) > moveThreshold) {
            view.move(delta);
            lastMousePosition = newMousePosition;
            window.setView(view);
        }
    }
}

void EventManager::handleMouseWheelScroll(const sf::Event& event, sf::RenderWindow& window, sf::View& view, float& zoomLevel) {
    const float minZoom = 0.5f;
    const float maxZoom = 2.0f;

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f mouseWorldPosition = window.mapPixelToCoords(mousePosition);

    if (event.mouseWheelScroll.delta > 0)
        zoomLevel *= 0.9f;
    else
        zoomLevel *= 1.1f;

    if (zoomLevel < minZoom)
        zoomLevel = minZoom;
    if (zoomLevel > maxZoom)
        zoomLevel = maxZoom;

    view.setSize(window.getDefaultView().getSize());
    view.zoom(zoomLevel);
    view.setCenter(mouseWorldPosition);
    window.setView(view);
}

void EventManager::handleKeyPress(const sf::Event& event, sf::View& view) {
    float moveSpeed = 10.0f;
    if (event.key.code == sf::Keyboard::Up)
        view.move(0, -moveSpeed);
    if (event.key.code == sf::Keyboard::Down)
        view.move(0, moveSpeed);
    if (event.key.code == sf::Keyboard::Left)
        view.move(-moveSpeed, 0);
    if (event.key.code == sf::Keyboard::Right)
        view.move(moveSpeed, 0);
}

