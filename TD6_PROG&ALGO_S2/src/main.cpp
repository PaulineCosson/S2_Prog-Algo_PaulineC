#include <iostream>

#include "node.hpp"


int main()
{
    //exo2
    //1/
    Node* root = create_node(5);
    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    //2/
    std::cout << "Affichage infixe : " << std::endl;
    root->display_infix();
    std::cout << std::endl;

    //3/
    std::cout << "valeur minimale : " ;
    minValue(root);
    std::cout << "valeur maximale : " ;
    maxValue(root);
    std::cout << std::endl;

    //4/
    std::vector<Node const*> prefixNodes = root->prefix();
    int sum {0};
    for (auto i : prefixNodes){
        sum += i->value;
    }
    std::cout << "Somme des valeurs des noeuds : " << sum << std::endl;

    //5/
    std::cout << "Hauteur de l'arbre binaire : " << root->height() << std::endl;

}