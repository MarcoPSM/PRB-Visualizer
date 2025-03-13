#ifndef PRB_HPP
#define PRB_HPP

#include <SFML/Graphics.hpp>
#include "ResourceElement.hpp"

class PRB {
    public:
        PRB(int id, int slot);
        void draw(sf::RenderWindow& window, sf::View& view);
        int getId() const;
        int getSlot() const;
        sf::Vector2f getPosition() const;
        sf::FloatRect getBounds() const;

    private:
        int id;
        int slot;
        int subCarrierSpacing;
        int const timeSize = 14*20;
        int const freqSize = 12*20;
        std::vector<ResourceElement> resourceElements;
};

#endif // PRB_HPP
