#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> kruskals(vector<vector<int>>);

int main() {
   int v;
	cout << "Enter number of vertices: ";
	cin >> v;
	vector<vector<int>> adj(v, vector<int>(v));
	cout << "Enter the adjacency matrix:\n";
	for (int i = 0; i < v; i++) {
	    for (int j = 0; j < v; j++) {
	        cin >> adj[i][j];
	    }
	}
	vector<vector<int>> mst = kruskals(adj);
	for (auto edge : mst) {
        cout << edge[0] << " - "
            << edge[1] << " : "
            << edge[2] << endl;
    }
	return 0;
}

vector<vector<int>> kruskals(vector<vector<int>> adj) {
    int v = adj.size();

    vector<vector<int>> edges;


    for (int i = 0; i < v; i++) {
        for (int j = i + 1; j < v; j++) {
            if (adj[i][j] != 0) {
                edges.push_back({ adj[i][j], i, j });
            }
        }
    }


    sort(edges.begin(), edges.end());

    vector<int> parent(v);

    for (int i = 0; i < v; i++) {
        parent[i] = i;
    }

    vector<vector<int>> mst;


    auto find = [&](int x) {
        while (parent[x] != x)
            x = parent[x];

        return x;
        };


    for (auto edge : edges) {
        int weight = edge[0];
        int u = edge[1];
        int w = edge[2];

        int parentU = find(u);
        int parentW = find(w);


        if (parentU != parentW) {
            mst.push_back({ u, w, weight });

            parent[parentW] = parentU;
        }

        if (mst.size() == v - 1)
            break;
    }

    return mst;
}
