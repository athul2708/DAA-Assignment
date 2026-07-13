#include "Graph.h"
#include <iostream>
#include <queue>

using namespace std;

template <class T>
Graph<T>::Graph(int v) {

    vertices = v;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }
}
template <class T>
void Graph<T>::insertEdge(int u, int v) {

    adj[u][v] = 1;
    adj[v][u] = 1;   
}
template <class T>
void Graph<T>::DFSUtil(int node, bool visited[]) {

    visited[node] = true;

    cout << node << " ";

    for (int i = 0; i < vertices; i++) {

        if (adj[node][i] == 1 && !visited[i]) {
            DFSUtil(i, visited);
        }

    }
}
template <class T>
void Graph<T>::DFS(int start) {

    bool visited[100] = { false };

    cout << "DFS: ";

    DFSUtil(start, visited);

    cout << endl;
}
template <class T>
void Graph<T>::BFS(int start) {

    bool visited[100] = { false };

    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";


    while (!q.empty()) {

        int node = q.front();
        q.pop();

        cout << node << " ";


        for (int i = 0; i < vertices; i++) {

            if (adj[node][i] == 1 && !visited[i]) {

                visited[i] = true;
                q.push(i);

            }
        }
    }

    cout << endl;
}
template <class T>
void Graph<T>::deleteNode(int x) {

    for (int i = 0; i < vertices; i++) {

        adj[x][i] = 0;
        adj[i][x] = 0;

    }

}
template <class T>
void Graph<T>::display() {

    cout << "Adjacency Matrix:\n";

    for (int i = 0; i < vertices; i++) {

        for (int j = 0; j < vertices; j++) {

            cout << adj[i][j] << " ";

        }

        cout << endl;
    }
}

template <class T>
void Graph<T>::setVertex(int index, T value) {
    vertex[index] = value;
}