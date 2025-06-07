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

//1/
Node* create_node (int value){
    Node* node {new Node{value}};
    return node;
}

//2/
bool Node::is_leaf() const{
    if (left==nullptr && right==nullptr){
        return true;
    }
    else{
        return false;
    }
}

//3/
void Node::insert(int newValue){
    if (newValue>value){
        if(right == nullptr){
            right = create_node(newValue);
        }
        else{
            right->insert(newValue);
        }
    }
    else{
        if(left == nullptr){
            left = create_node(newValue);
        }
        else{
            left->insert(newValue);
        }
    }
}

//4/
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
        return 1  + std::max(left->height(), right->height());
    }
}

//5/
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

//6/
void Node::display_infix() const{
    if (left) {
        left->display_infix();
    }
    std::cout << value << " ";
    if (right) {
        right->display_infix();
    }
}

//7/
std::vector<Node const*> Node::prefix() const{
    std::vector<Node const*> nodes{};
    nodes.push_back(this);
    if (left) {
        auto left_nodes {left->prefix()};
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right) {
        auto right_nodes {right->prefix()};
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}


//9/
Node*& most_left(Node*& node){
    if(node->left == nullptr){
        return node;
    }
    return most_left(node->left);
}

//10/
bool remove(Node*& node, int supprValue){
    if (node == nullptr){
        return false;
    }

    if(supprValue < node->value){
        return remove(node->left,supprValue);
    }
    else if(supprValue > node->value){
        return remove(node->right,supprValue);
    }
    else{
        if(node->is_leaf()){
            // On supprime le nœud courant
            delete node;
            // Comme on a une référence sur le pointeur du nœud courant, on le met à jour avec nullptr
            node = nullptr;
        }
        if(node->left == nullptr){
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        if(node->right == nullptr){
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else{
            Node*& mostLeftNode = most_left(node->right);
            node->value = mostLeftNode->value;
            return (remove(mostLeftNode, mostLeftNode->value));
        }
        return true;
    }
}

//11/
void delete_tree(Node* node){
    if (node != nullptr) {
        node->delete_children();
        delete node;
    }
}

//12/
void minValue(Node* node){
    std::cout << most_left(node)->value << std::endl;
}

Node*& most_right(Node*& node){
    if(node->right == nullptr){
        return node;
    }
    return most_right(node->right);
}
void maxValue(Node* node){
    std::cout << most_right(node)->value << std::endl;
}