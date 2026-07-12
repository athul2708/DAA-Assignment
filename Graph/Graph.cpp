#include "Graph.h"
#include <iostream>
#include <queue>

using namespace std;


Graph::Graph(int v) {

    vertices = v;

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }
}

void Graph::insertEdge(int u, int v) {

    adj[u][v] = 1;
    adj[v][u] = 1;   
}

void Graph::DFSUtil(int node, bool visited[]) {

    visited[node] = true;

    cout << node << " ";

    for (int i = 0; i < vertices; i++) {

        if (adj[node][i] == 1 && !visited[i]) {
            DFSUtil(i, visited);
        }

    }
}

void Graph::DFS(int start) {

    bool visited[100] = { false };

    cout << "DFS: ";

    DFSUtil(start, visited);

    cout << endl;
}

void Graph::BFS(int start) {

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

void Graph::deleteNode(int x) {

    for (int i = 0; i < vertices; i++) {

        adj[x][i] = 0;
        adj[i][x] = 0;

    }

}

void Graph::display() {

    cout << "Adjacency Matrix:\n";

    for (int i = 0; i < vertices; i++) {

        for (int j = 0; j < vertices; j++) {

            cout << adj[i][j] << " ";

        }

        cout << endl;
    }
}