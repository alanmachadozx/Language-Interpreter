#include "parser/mod.hpp"
#include "lexer/token.hpp"
#include "parser/expr.hpp"
#include <string>
#include <vector>

void parserFuncs() {
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

Expr* Parser::factor(){
    Expr* expr = unary();
    
    while (match(TokenType::STAR, TokenType::SLASH)){
        Expr* right = unary();
        Token operatorToken = Parser::previous();
        expr = new Binary(expr, operatorToken, right); 
    }
    return expr; 
}

Expr* Parser::unary(){
    if(match(TokenType::SUB)){
        Expr* right = unary();
        Token operatorToken = Parser::previous();
        return new Unary(operatorToken, right);
    }
    return primary();
}

Expr* Parser::primary(){
    if (match(TokenType::NUMBER)){
        return new Literal(previous().literal);
    }
    if (match(TokenType::LPAREN)){
        Expr* content = expression();
        consume(TokenType::RPAREN, "Expect ')' after expression");
        return new Grouping(content);
    }
}