#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> bfs(vector<vector<int>>);

int main() {
	cout << "\nEnter the no. of vertices: ";
	int n;
	cin >> n;
	vector<vector<int>> adj(n,vector<int>(n));
	cout << "\nEnter the adjacency matrix of the graph: ";
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> adj[i][j];
		}
	}
	cout << "BFS of the graph: ";
	vector<int> BFS = bfs(adj);
	for (int i : BFS)
		cout << " => " << i;
	return 0;
}

vector<int> bfs(vector<vector<int>> adj) {
	vector<bool> visited(adj.size(), false);
	vector<int> bfs;
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int node = q.front();
		bfs.push_back(node);
		q.pop();
		for (int i = 0;i < adj.size();i++) {
			if (adj[node][i] == 1&&visited[i]==false) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return bfs;
}