#include "parser/mod.hpp"
#include "lexer/token.hpp"
#include <vector>

int main() {
  std::vector<Token> tokens;
  Parser parser(tokens);
}

Expr* Parser::expression(){
    Expr* expr = factor();
    
    while (match(TokenType::PLUS, TokenType::SUB)) {
    Expr* right = factor();
    Token operatorToken = Parser::previous();
    expr = new Binary(expr, operatorToken, right);
    }
    return expr;
}