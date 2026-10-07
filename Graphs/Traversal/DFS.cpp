#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> dfs(vector<vector<int>>);

int main() {
	cout << "\nEnter the no. of vertices: ";
	int n;
	cin >> n;
	vector<vector<int>> adj(n, vector<int>(n));
	cout << "\nEnter the adjacency matrix of the graph: ";
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> adj[i][j];
		}
	}
	cout << "DFS of the graph: ";
	vector<int> DFS = dfs(adj);
	for (int i : DFS)
		cout << " => " << i;
	return 0;
}

vector<int> dfs(vector<vector<int>> adj) {
	vector<bool> visited(adj.size(), false);
	vector<int> dfs;
	stack<int> s;
	s.push(0);
	visited[0] = true;
	while (!s.empty()) {
		int node = s.top();
		dfs.push_back(node);
		s.pop();
		for (int i = 0;i < adj.size();i++) {
			if (adj[node][i] == 1 && visited[i] == false) {
				s.push(i);
				visited[i] = true;
			}
		}
	}
	return dfs;
}