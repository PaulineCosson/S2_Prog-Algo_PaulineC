#include "exo1.hpp"
#include <iostream>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
    // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
}

bool is_floating (std::string const& s)
{
    for (char i:s){
        if (!(std::isdigit(i) && i != '.')){
            return(false);
        }
    }
    return (true); 
}

float npi_evaluate(std::vector<std::string> const& tokens){
    std::stack<float> stack;
    for (std::string i:tokens){
        if (is_floating(i)){
            stack.push(std::stof(i));
        }
        else{
        // Je récupère l'élément en haut de la pile
        float rightOperand { stack.top() };
        // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
        stack.pop();
        float leftOperand { stack.top() };
        stack.pop();

        // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
        float result {i == "+" ? leftOperand + rightOperand :
            i == "-" ? leftOperand - rightOperand :
            i == "*" ? leftOperand * rightOperand :
            i == "/" ? leftOperand / rightOperand : 0
        };

        stack.push(result);
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
