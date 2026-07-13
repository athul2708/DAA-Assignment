#pragma once
template <class T>
class Graph {
private:
    int adj[100][100];
    T vertex[100];
    int vertices;

    void DFSUtil(int node, bool visited[]);

public:
    Graph(int v);
    void setVertex(int index, T value);
    void insertEdge(int u, int v);
    void deleteNode(int x);

    void DFS(int start);
    void BFS(int start);

    void display();
};
