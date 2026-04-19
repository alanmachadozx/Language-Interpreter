#include "lexer/token.hpp"
#include <vector>

class Parser{  
  private:
  std::vector<Token> tokens;
  int current = 0;
  
  public:
  Parser(std::vector<Token> tokens) : tokens(tokens){}
  
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
  template<typename... Args >
  bool match(Args... types){
       if ((check(types) ||...)){
           advance();
          return true;
       }
       return false;
  }
};