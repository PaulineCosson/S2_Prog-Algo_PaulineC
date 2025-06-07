#pragma once
#include <string>
#include <vector>


struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;
    void insert(int newValue);
    int height() const;
    void delete_children();
    void display_infix() const;
    std::vector<Node const*> prefix() const;
};

//afficher une représentation ASCII dans la console d'un arbre binaire
void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
void pretty_print_left_right(Node const& node);


Node* create_node (int value);
Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
void delete_tree(Node* node);
void minValue(Node* node);
void maxValue(Node* node);
