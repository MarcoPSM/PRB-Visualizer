#include "ResourceElement.hpp"

ResourceElement::ResourceElement(int id, 
        int x,
        int y,
        Channel channel,
        float i,
        float q): id(id), x(x), y(y), channel(channel) {
    iqData[0] = i;
    iqData[1] = q;

    shape.setSize(sf::Vector2f(size-1, size-1));
    shape.setPosition(x, y);
    shape.setFillColor(ChannelManager::getColor(channel));

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

int ResourceElement::getSymbol() const {
    return id % 14;
}

int ResourceElement::getSubCarrier() const {
    return id / 14;
}

void ResourceElement::setChannel(Channel channel) {
    this->channel = channel;
    shape.setFillColor(ChannelManager::getColor(channel));
}

void ResourceElement::setIQData(float i, float q) {
    this->iqData[0] = i;
    this->iqData[1] = q;
}

std::string ResourceElement::getChannelName() const {
    return ChannelManager::getName(this->channel);
}
