#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <variant>
#include <string>

using LiteralType = std::variant<double, std::string, bool, std::nullptr_t>;

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
    ENDL,
};

struct Token{
    TokenType type;
    std::string lexeme; //std::string It's the data type (the tool that allows you to store text).
    int line;
    LiteralType literal;
};

#endif