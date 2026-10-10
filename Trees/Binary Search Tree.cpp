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
    int n, value;

    cout << "\nEnter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "Tree is empty";
        return 0;
    }

    cout << "\nEnter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder traversal of bst (gives sorted): \n";
    print(root);
    cout << endl;

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
