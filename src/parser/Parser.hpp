#ifndef PARSER_HPP
#define PARSER_HPP


class Parser {
    public:
        //Parser(const std::string& filePath);
        virtual ~Parser() = default;
        virtual int parseTotalPrbs() const = 0;
        virtual int parseTotalSlots() const = 0;
};

#endif // PARSER_HPP
