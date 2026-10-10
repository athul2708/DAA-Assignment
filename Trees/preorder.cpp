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

Node* createTree() {
    int data;

    cout << "Enter node data (-1 for no node): ";
    cin >> data;

    if (data == -1)
        return nullptr;

    Node* root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = createTree();

    cout << "Enter right child of " << data << endl;
    root->right = createTree();

    return root;
}

void preorder(Node* root) {
	cout << "\t" << root->data;
	if (root->left != nullptr)
		preorder(root->left);
	if (root->right != nullptr)
		preorder(root->right);
}

int main() {
    cout << "Create a binary tree (-1 for no node):" << endl;
    Node* root = createTree();

    cout << "\nPreorder traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}


