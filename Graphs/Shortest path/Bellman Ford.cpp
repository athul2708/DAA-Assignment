#include <iostream>
#include <vector>
#define INF 999
using namespace std;
//BELLMAN FORD
vector<int> belford(vector<vector<pair<int, int>>>&,int);

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<pair<int, int>>> adjlist(v);
    cout << "Enter source, destination and weight of each edge:\n";
    for (int i = 0; i < e; i++) {
        int u, nbr, weight;
        cin >> u >> nbr >> weight;
        adjlist[u].push_back({weight, nbr});
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    vector<int> shortest = belford(adjlist, source);
    for (int i = 0; i < shortest.size(); i++) {
        cout << "\nShortest distance to node " << i
             << " = " << shortest[i];
    }
    return 0;
}

vector<int> belford(vector<vector<pair<int, int>>>& adj,int source) {
	int v = adj.size();
	vector<int> dist(v, INF);
	dist[source] = 0;
	for (int i = 1;i < v;i++) {
		for (int u = 0;u < v;u++) {
			for (auto edge : adj[u]) {
				int nbr = edge.second;
				int d = edge.first;
				if (dist[nbr] > dist[u] + d && dist[u]!=INF) {
					dist[nbr] = dist[u] + d;
				}
			}
		}
	}
	for (int u = 0;u < v;u++) {
		for (auto edge : adj[u]) {
			int nbr = edge.second;
			int d = edge.first;
			if (dist[nbr] > dist[u] + d && dist[u] != INF) {
				cout << "Negative - weight cycle exist!!!\n";
			}
		}
	}
	return dist;
}
