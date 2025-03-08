#include "ResourceElement.hpp"

ResourceElement::ResourceElement(int id, int x, int y) : id(id), x(x), y(y) {
    shape.setSize(sf::Vector2f(size-1, size-1));
    shape.setPosition(x, y);
    shape.setFillColor(color);
}

void ResourceElement::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

int ResourceElement::getId() {
    return this->id;
}

sf::Vector2f ResourceElement::getPosition() const {
    return shape.getPosition();
    // return sf::Vector2f(this->x, this->y);
}

sf::FloatRect ResourceElement::getBounds() const {
    return shape.getGlobalBounds();
}
