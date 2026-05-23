#ifndef ERROR_HPP
#define ERROR_HPP
#include <string>
#include <exception>

//Initial error handling
class ParserError: public std::exception{
    private: 
    std::string value;
    public:
    ParserError ()  {}; 
    
    const char* what() const noexcept override {
           return "Expect expression";
    }
};
#endif