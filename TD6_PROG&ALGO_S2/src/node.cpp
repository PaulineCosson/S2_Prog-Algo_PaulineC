#include "node.hpp"

#include <iostream>

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}


Node* create_node (int value){
    Node* node {new Node{value}};
    return node;
}

bool Node::is_leaf() const{
    if (left==nullptr && right==nullptr){
        return true;
    }
    else{
        return false;
    }
}

void Node::insert(int newValue){
    if (newValue>value){
        right = create_node(newValue);
    }
    else{
        left = create_node(newValue);
    }
}

int Node::height() const{
    if(left == nullptr && right == nullptr)
        return 1;
    else if(left == nullptr && right != nullptr){
        return 1 + right->height();
    }
    else if(left != nullptr && right == nullptr){
        return 1 + left->height();
    }
    else {
        return 1  + std::max(left->height(), right->height())
    }
}

void Node::delete_children(){
    if(left != nullptr){
        left->delete_children();
        delete left;
    }
    if(right !=nullptr){
        right->delete_children();
        delete right;
    }
}

void Node::display_infix() const{

}