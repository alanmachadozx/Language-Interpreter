
#ifndef EXPR_HPP
#define EXPR_HPP
#include "lexer/token.hpp"

class Expr{
    public:
    
};

class Binary: public Expr{
    public:
    Expr* left;
    Token op;
    Expr* right;
    
    Binary(Expr*l, Token o, Expr*r) : left(l), op(o), right(r) {}
};
class Unary: public Expr{
    public:
    Token op;
    Expr*right;
    
    Unary(Token o, Expr*r) : op(o), right(r) {}
};
class Literal: public Expr{
    public:
    LiteralType litType;
    
    Literal(LiteralType c) : litType(c) {}
};
#endif