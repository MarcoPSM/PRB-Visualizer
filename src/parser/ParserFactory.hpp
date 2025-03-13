#ifndef PARSERFACTORY_HPP
#define PARSERFACTORY_HPP

#include <string>
#include <memory>
#include "Parser.hpp"

class ParserFactory {
public:
    static std::unique_ptr<Parser> createParser(const std::string& filePath);
};

#endif // PARSERFACTORY_HPP
