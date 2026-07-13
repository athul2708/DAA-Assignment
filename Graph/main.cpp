#include "Graph.h"
#include "Graph.tpp"
#include <iostream>

using namespace std;


int main() {

    Graph<int> g(6);
    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 4);
    g.insertEdge(3, 5);
    cout << "Before deletion:\n";
    g.display();
    g.DFS(0);
    g.BFS(0);
    cout << "\nDeleting node 3\n";
    g.deleteNode(3);
    g.display();
    g.DFS(0);
    g.BFS(0);
    return 0;
}