#include "JsonParser.hpp"
#include <fstream>
#include <iostream>

JsonParser::JsonParser(const std::string& filePath) : Parser(), filePath(filePath) {
    loadFile();
}

void JsonParser::loadFile() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return;
    }

    file >> jsonData;
}

int JsonParser::parseTotalPrbs() const {
    return jsonData["total_prbs"];
}

int JsonParser::parseTotalSlots() const {
    return jsonData["total_slots"];
}
