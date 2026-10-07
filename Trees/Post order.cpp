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

void postorder(Node* root) {
	if (root->left != nullptr)
		postorder(root->left);
	if (root->right != nullptr)
		postorder(root->right);
	cout << "\t" << root->data;
}

int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->right = new Node(4);
	postorder(root);
	return 0;
}

