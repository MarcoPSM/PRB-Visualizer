#include "ChannelManager.hpp"

const std::unordered_map<Channel, ChannelInfo> ChannelManager::channelInfo = {
    {Channel::NO_CHANNEL, {sf::Color(25, 25, 25), "No channel"}},
    {Channel::INVALID, {sf::Color(125, 125, 125), "No channel"}},
    {Channel::PBCH, {sf::Color::Yellow, "PBCH"}},
    {Channel::PDCCH, {sf::Color::Green, "PDCCH"}},
    {Channel::PDSCH, {sf::Color::Blue, "PDSCH"}},
    {Channel::PSS, {sf::Color(173, 216, 230), "PSS"}},
    {Channel::SSS, {sf::Color(255, 192, 203), "SSS"}},
    {Channel::PBCH_DMRS, {sf::Color(242, 33, 79), "PBCH_DMRS"}},
    {Channel::PDCCH_DMRS, {sf::Color(242, 82, 33), "PDCCH_DMRS"}},
    {Channel::PDSCH_DMRS, {sf::Color(242, 33, 33), "PDSCH_DMRS"}},
    {Channel::PDSCH_PTRS, {sf::Color(242, 160, 33), "PDSCH_PTRS"}},
    {Channel::PRS, {sf::Color(255, 255, 255), "PRS"}},
    {Channel::CSIRS, {sf::Color(173, 216, 230), "CSIRS"}},
    {Channel::RIMRS, {sf::Color(0, 158, 24), "RIMRS"}}
};

sf::Color ChannelManager::getColor(Channel channel) {
    return channelInfo.at(channel).color;
}

std::string ChannelManager::getName(Channel channel) {
    return channelInfo.at(channel).name;
}

