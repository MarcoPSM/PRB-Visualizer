#ifndef RESOURCEELEMENT_HPP
#define RESOURCEELEMENT_HPP

#include <SFML/Graphics.hpp>
#include "ChannelManager.hpp"

class ResourceElement {
    public:
        ResourceElement(int id, 
                int x, 
                int y, 
                Channel channel = Channel::NO_CHANNEL, 
                float i = 0, 
                float q = 0);
        void draw(sf::RenderWindow& window);
        int getId();
        sf::Vector2f getPosition() const;
        sf::FloatRect getBounds() const;
        int getSymbol() const;
        int getSubCarrier() const;
        void setChannel(Channel channel);
        void setIQData(float i, float q);

    private:
        int id;
        int x, y;
        int const size = 20;
        Channel channel = Channel::NO_CHANNEL;
        sf::Color color = ChannelManager::getColor(channel);
        float iqData[2] = {0};
        sf::RectangleShape shape;
};

#endif // RESOURCEELEMENT_HPP
