#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum class TokenType{
    PLUS,
    NUMBER,
    STAR,
    SLASH,
    SUB,
    EQ,
    LPAREN,
    RPAREN,
    LT,
    LTEQ,
    GT,
    GTEQ,
    EQEQ,
    PLUSEQ,
    SUBEQ,
    STAREQ,
    SLASHEQ,
    DOT,
    LBRACE,
    RBRACE,
};

struct Token{
    TokenType type;
    std::string lexeme; //std::string It's the data type (the tool that allows you to store text).
    int line;
};

#endif