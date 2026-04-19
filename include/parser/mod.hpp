#include "lexer/scanner.hpp"
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
  bool isEnd(){
      return peek().type == TokenType::ENDL;
  }
};