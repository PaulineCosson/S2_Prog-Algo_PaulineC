#pragma once
#include <string>


struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;
    void insert(int newValue);
    int height() const;
    void delete_children();
    void display_infix() const;
};
    
    void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
    void pretty_print_left_right(Node const& node);


    Node* create_node (int value);
    