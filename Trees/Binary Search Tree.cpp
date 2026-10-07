#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node(int data) {
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};

Node* insert(Node* root, int data);
void print(Node* root);

int main() {

    Node* root = nullptr;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    cout << "\nInorder traversal of bst (gives sorted): \n";
    print(root);

    return 0;
}

Node* insert(Node* root, int data) {

    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

void print(Node* root) {

    if (root == nullptr)
        return;

    print(root->left);
    cout << root->data << " ";
    print(root->right);
}