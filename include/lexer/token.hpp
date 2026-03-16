#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum class TokenType{
    PLUS
};

struct Token{
    TokenType type;
    std::string lexeme; //std::string It's the data type (the tool that allows you to store text).
    int line;
};

#endif