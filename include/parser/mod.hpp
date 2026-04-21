#ifndef MOD_HPP
#define MOD_HPP
#include "lexer/token.hpp"
#include <vector>
#include "parser/expr.hpp"

class Parser{  
  public:
  Parser(std::vector<Token> tokens) : tokens(tokens){};

  private:
  std::vector<Token> tokens;
  int current = 0;
  
  Token peek(){
      return tokens[current];
  }
  Token advance(){
      if (!isEnd()) current++;
      return tokens[current - 1];
  }
  bool isEnd(){
      return peek().type == TokenType::ENDL;
  }
  bool check(TokenType type){
      if (isEnd()) return false;
      return peek().type == type;
  }
  Token previous(){
      return tokens[current - 1];
  }
  template<typename... Args >
  bool match(Args... types){
       if ((check(types) ||...)){
           advance();
          return true;
       }
       return false;
  }
  
  Expr* expression();//rule of least precedence(PLUS and SUB)
  Expr* factor();//STAR and SLASH
  Expr* unary();//MINUS and BANG
};

#endif