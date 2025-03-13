#include "ParserFactory.hpp"
#include "JsonParser.hpp"
#include <iostream>

std::unique_ptr<Parser> ParserFactory::createParser(const std::string& filePath) {
    std::string extension = filePath.substr(filePath.find_last_of('.') + 1);

    if (extension == "json") {
        return std::make_unique<JsonParser>(filePath);
    }

    std::cerr << "Unsupported file extension: " << extension << std::endl;
    return nullptr;
}
