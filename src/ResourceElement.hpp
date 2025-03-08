#ifndef RESOURCEELEMENT_HPP
#define RESOURCEELEMENT_HPP

#include <SFML/Graphics.hpp>

class ResourceElement {
public:
    ResourceElement(int id, int x, int y);
    void draw(sf::RenderWindow& window);
    int getId();
    sf::Vector2f getPosition() const;
    sf::FloatRect getBounds() const;

private:
    int id;
    int x, y;
    int const size = 20;
    sf::Color color = sf::Color::Green;
    float iqdata[2] = {0};
    sf::RectangleShape shape;
};

#endif // RESOURCEELEMENT_HPP
