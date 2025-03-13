#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include "PRB.hpp"
#include "EventManager.hpp"
#include <vector>
#include "parser/Parser.hpp"
#include <memory>

class Application {
    public:
        Application();
        void setParser(std::string filePath);
        void run();
    private:
        void handleEvents();
        void update();
        void render();

        sf::RenderWindow window;
        std::vector<PRB> prbs;
        sf::Font font;
        sf::View view = window.getDefaultView();
        EventManager eventManager;
        float zoomLevel = 1.0f;
        bool isDragging = false;
        sf::Vector2f lastMousePosition;
        const float moveThreshold = 5.0f;
        std::unique_ptr<Parser> parser;
};

#endif // APPLICATION_HPP
