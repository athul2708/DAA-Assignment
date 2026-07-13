#include "Tree.h"
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node(T value) {
    data = value;
    left = nullptr;
    right = nullptr;
}

template <class T>
Tree<T>::Tree() {
    root = nullptr;
}

template <class T>
void Tree<T>::create(T value) {
    root = insert(root, value);
}

template <class T>
Node<T>* Tree<T>::insert(Node<T>* node, T value) {

    if (node == nullptr)
        return new Node<T>(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);

    return node;
}
template <class T>
void Tree<T>::inorder(Node<T>* node) {

    if (node == nullptr)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
template <class T>
void Tree<T>::preorder(Node<T>* node) {

    if (node == nullptr)
        return;

    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

template <class T>
void Tree<T>::postorder(Node<T>* node) {

    if (node == nullptr)
        return;

    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}
template <class T>
bool Tree<T>::search(Node<T>* node, T value) {

    if (node == nullptr)
        return false;

    if (node->data == value)
        return true;

    if (value < node->data)
        return search(node->left, value);

    return search(node->right, value);
}
template <class T>
void Tree<T>::inorder() {
    inorder(root);
}
template <class T>
void Tree<T>::preorder() {
    preorder(root);
}
template <class T>
void Tree<T>::postorder() {
    postorder(root);
}

template <class T>
void Tree<T>::search(T value) {

    if (search(root, value))
        cout << "Found\n";
    else
        cout << "Not Found\n";
}