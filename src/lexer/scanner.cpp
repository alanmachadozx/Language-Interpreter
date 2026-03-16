#include "include/lexer/scanner.hpp"

Scanner::Scanner(std::string source) : source(source) {}

bool Scanner::finished(){
    return current >= source.size();
}

char Scanner::advance(){
    return source[current++];
}

void Scanner::addToken(TokenType type){
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token{type, text, line});
}

std::vector<Token> Scanner::scanToken(){
    while(!finished()){
        start = current;

        scanToken();
    }
}