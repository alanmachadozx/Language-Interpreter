#ifndef ERROR_HPP
#define ERROR_HPP
#include <string>
#include <exception>

class ParserError: public std::exception{
    private: 
    std::string value;
    public:
    ParserError (std::string val) : value(val) {}; 
    
    const char* what() const noexcept override {
           return "Expect expression";
    }
};
#endif