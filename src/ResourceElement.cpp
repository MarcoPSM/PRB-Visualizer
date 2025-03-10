#include "ResourceElement.hpp"
/*
ResourceElement::ResourceElement(int id, int x, int y) : id(id), x(x), y(y) {
    shape.setSize(sf::Vector2f(size-1, size-1));
    shape.setPosition(x, y);
    shape.setFillColor(color);
}
*/

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

int ResourceElement::getSymbol() const {
    return id % 14;
}

int ResourceElement::getSubCarrier() const {
    return id / 14;
}

/*
sf::Color ResourceElement::getColor(common::DL_Phy_Channel channel) const {
    switch (channel) {
        case common::DL_Phy_Channel::PBCH:
            return sf::Color::Yellow;
        case common::DL_Phy_Channel::PDCCH:
            return sf::Color::Green;
        case common::DL_Phy_Channel::PDSCH:
            return sf::Color::Blue;
        case common::DL_Phy_Channel::PSS:
            return sf::Color(173, 216, 230);
        case common::DL_Phy_Channel::SSS:
            return sf::Color(255, 192, 203);
        case common::DL_Phy_Channel::PBCH_DMRS:
            return sf::Color(242, 33, 79);
        case common::DL_Phy_Channel::PDCCH_DMRS:
            return sf::Color(242, 82, 33);
        case common::DL_Phy_Channel::PDSCH_DMRS:
            return sf::Color(242, 33, 33);
        case common::DL_Phy_Channel::PDSCH_PTRS:
            return sf::Color(242, 160, 33);
        case common::DL_Phy_Channel::PRS:
            return sf::Color(255, 255, 255);
        case common::DL_Phy_Channel::CSIRS:
            return sf::Color(173, 216, 230);
        case common::DL_Phy_Channel::RIMRS:
            return sf::Color(0, 158, 24);
        case common::DL_Phy_Channel::INVALID:
            return sf::Color(125, 125, 125);
        case common::DL_Phy_Channel::NO_CHANNEL: 
            return sf::Color(25, 25, 25);
        default:
            return sf::Color::Black;
    }
}
*/

void ResourceElement::setChannel(Channel channel) {
    this->channel = channel;
}

void ResourceElement::setIQData(float i, float q) {
    this->iqData[0] = i;
    this->iqData[1] = q;
}

