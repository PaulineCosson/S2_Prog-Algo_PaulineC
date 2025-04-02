#include "exo2.hpp"



Token make_token(float value){
    Token token{TokenType::OPERAND, value}; 

    return token;
}

Token make_token(Operator op){
    Token token{TokenType::OPERAND,0.0f,op}; 

    return token;
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    
}
