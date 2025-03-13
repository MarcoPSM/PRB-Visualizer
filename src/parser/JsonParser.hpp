#ifndef JSONPARSER_HPP
#define JSONPARSER_HPP

#include "Parser.hpp"
#include "json.hpp"
#include <string>

class JsonParser : public Parser {
    public:
        JsonParser(const std::string& filePath);
        int parseTotalPrbs() const override;
        int parseTotalSlots() const override;

    private:
        std::string filePath;
        nlohmann::json jsonData;

        void loadFile();
};

#endif // JSONPARSER_HPP
