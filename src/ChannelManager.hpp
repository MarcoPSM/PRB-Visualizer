#ifndef CHANNELMANAGER_HPP
#define CHANNELMANAGER_HPP

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>

enum class Channel {
        NO_CHANNEL,
        INVALID,
        PBCH,
        PDCCH,
        PDSCH,
        PSS,
        SSS,
        PBCH_DMRS,
        PDCCH_DMRS,
        PDSCH_DMRS,
        PDSCH_PTRS,
        PRS,
        CSIRS,
        RIMRS
};

struct ChannelInfo {
    sf::Color color;
    std::string name;
};

class ChannelManager {
    public:
        static sf::Color getColor(Channel channel);
        static std::string getName(Channel channel);

    private:
        static const std::unordered_map<Channel, ChannelInfo> channelInfo;

};

#endif // CHANNELMANAGER_HPP
