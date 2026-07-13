#pragma once
template <class T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T value);
};
template <class T>
class Tree {
private:
    Node<T>* root;

    Node<T>* insert(Node<T>* node, T value);
    void inorder(Node<T>* node);
    void preorder(Node<T>* node);
    void postorder(Node<T>* node);
    bool search(Node<T>* node, T value);

public:
    Tree();

    void create(T value);
    void inorder();
    void preorder();
    void postorder();
    void search(T value);
};