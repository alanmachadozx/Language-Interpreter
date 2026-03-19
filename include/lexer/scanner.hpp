#ifndef SCANNER_HPP
#define SCANNER_HPP
 
#include <string>
#include <vector>
#include "lexer/token.hpp"


class Scanner{

public:
Scanner(std::string source);

std::vector<Token> scanTokens();

private:
std::string source;
std::vector<Token> tokens;

int start = 0;  //Início do lexema atual
int current = 0; //posição do caractere que estamos lendo agora
int line = 1; //Linha atual

bool finished(); 
char advance();
void addToken(TokenType type);
void scanSingleToken();
void isNumber();

};

#endif