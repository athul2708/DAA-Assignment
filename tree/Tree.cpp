#include "Tree.h"
#include <iostream>
using namespace std;


Node::Node(int value) {
    data = value;
    left = nullptr;
    right = nullptr;
}


Tree::Tree() {
    root = nullptr;
}


void Tree::create(int value) {
    root = insert(root, value);
}


Node* Tree::insert(Node* node, int value) {

    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);

    return node;
}

void Tree::inorder(Node* node) {

    if (node == nullptr)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void Tree::preorder(Node* node) {

    if (node == nullptr)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}


void Tree::postorder(Node* node) {

    if (node == nullptr)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

bool Tree::search(Node* node, int value) {

    if (node == nullptr)
        return false;

    if (node->data == value)
        return true;

    if (value < node->data)
        return search(node->left, value);

    return search(node->right, value);
}

void Tree::inorder() {
    inorder(root);
}

void Tree::preorder() {
    preorder(root);
}

void Tree::postorder() {
    postorder(root);
}


void Tree::search(int value) {

    if (search(root, value))
        cout << "Found\n";
    else
        cout << "Not Found\n";
}