#include "Tree.h"
#include "Tree.tpp"
#include <iostream>
using namespace std;

int main() {

    Tree<int> t;

 
    t.create(50);
    t.create(30);
    t.create(70);
    t.create(20);
    t.create(40);
    t.create(60);
    t.create(80);


    cout << "Inorder: ";
    t.inorder();

    cout << "\nPreorder: ";
    t.preorder();

    cout << "\nPostorder: ";
    t.postorder();


    cout << "\n\nSearch 40: ";
    t.search(40);

    cout << "Search 100: ";
    t.search(100);


    return 0;
}