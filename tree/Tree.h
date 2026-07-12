#pragma once

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value);
};

class Tree {
private:
    Node* root;

    Node* insert(Node* node, int value);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    bool search(Node* node, int value);

public:
    Tree();

    void create(int value);
    void inorder();
    void preorder();
    void postorder();
    void search(int value);
};