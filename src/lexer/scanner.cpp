#include "lexer/scanner.hpp"
#include "lexer/token.hpp"
#include <cctype>


Scanner::Scanner(std::string source) : source(source) {}

bool Scanner::finished(){
    return current >= source.size();
}
//advances to the next character
char Scanner::advance(){
    return source[current++];
}
//Adds a type to a token.
void Scanner::addToken(TokenType type, std::variant<double, std::string, bool, std::nullptr_t> literal){
    std::string text = source.substr(start, current - start);
    tokens.push_back(Token{type, text, line, literal});
}
void Scanner::addToken(TokenType type) {
    addToken(type, nullptr); 
}

void Scanner::isNumber(){
    while(std::isdigit(source[current])){    
        current++;
    }
    if(source[current] == '.' && std::isdigit(source[current + 1])){
        current++;
        while (std::isdigit(source[current])) {
            current++;
        }
    }
    std::string text = source.substr(start, current - start);
    double value = std::stod(text);
    addToken(TokenType::NUMBER, value);
}

std::vector<Token>Scanner::scanTokens(){
    while(!finished()){
        start = current;

        scanSingleToken();      
    }
    addToken(TokenType::ENDL);
    return tokens;
}

void Scanner::scanSingleToken(){
    char c = advance();
    
    if(c == '+'){
        if(source[current++] == '='){
            addToken(TokenType::PLUSEQ);
        } else{
            current--;
            addToken(TokenType::PLUS);
        }
    }
    if(std::isdigit(c)) isNumber();
    if(c == '*'){
        if(source[current++] == '='){
            addToken(TokenType::STAREQ);
        } else{
            current--;
            addToken(TokenType::STAR);
        }
    };
    if(c == '/'){
        if(source[current++] == '='){
            addToken(TokenType::SLASHEQ);
        } else{
            current--;
            addToken(TokenType::SLASH);
        }
    
    }
    if(c == '-'){
        if(source[current++] == '='){
            addToken(TokenType::SUBEQ);
        } else{
            current--;
            addToken(TokenType::SUB);
        }
    }
    if(c == '=') {
        if(source[current++] == '='){
            addToken(TokenType::EQEQ);
        } else{
            current--;
            addToken(TokenType::EQ);
        }
    }
    if(c == '(') addToken(TokenType::LPAREN);
    if(c == ')') addToken(TokenType::RPAREN);
    if(c == '{') addToken(TokenType::LBRACE);
    if(c == '}') addToken(TokenType::RBRACE);
    if(c == '>') {
        if(source[current++] == '='){
            addToken(TokenType::GTEQ);
        } else{
            current--;
            addToken(TokenType::GT);
        }
    }
    
    if(c == '<'){
        if(source[current++] == '='){
            addToken(TokenType::LTEQ);
        } else{
            current--;
            addToken(TokenType::LT);
        }
    }
    if(c == '.') addToken(TokenType::DOT);
}