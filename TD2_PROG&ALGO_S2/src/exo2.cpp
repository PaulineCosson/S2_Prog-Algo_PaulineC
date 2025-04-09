#include "exo2.hpp"

#include <stack>
#include <iostream>

Token make_token(float value){
    Token token{}; 
    token.type = TokenType::OPERAND;
    token.value = value;
    return token;
}


Token make_token(Operator op){
    Token token;
    token.type = TokenType::OPERATOR;
    token.op = op;
    return token;
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> tokens{}; 
    for (const std::string& word : words ){
        if (word == "+"){
            tokens.push_back(make_token(Operator::ADD));
        }
        else if (word == "-"){
            tokens.push_back(make_token(Operator::SUB));
        }
        else if (word == "*"){
            tokens.push_back(make_token(Operator::MUL));
        }
        else if (word == "/"){
            tokens.push_back(make_token(Operator::DIV));
        }
        else {
            tokens.push_back(make_token(std::stof(word)));
        }
    }
    return (tokens);
}

float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> stack;
    for (const Token token : tokens ){
        if (token.type == TokenType::OPERAND){
            stack.push(token.value);
        }
        else{
            // Je récupère l'élément en haut de la pile
            float rightOperand { stack.top() };
            // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
            stack.pop();
            float leftOperand { stack.top() };
            stack.pop();
            // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
            switch (token.op){
                case Operator::ADD:
                    stack.push(leftOperand + rightOperand);
                    break; 
                case Operator::SUB:
                    stack.push(leftOperand - rightOperand);       
                    break;
                case Operator::MUL:
                    stack.push(leftOperand * rightOperand); 
                    break;
                case Operator::DIV:
                    stack.push(leftOperand / rightOperand); 
                    break;
                }
        }
    }
    if (stack.size() != 1) {
        std::cout << "Erreur: Problème dans l'expression NPI" << std::endl;
        return 0;
    }
    else{
        return stack.top(); 
    }
}
