#include <iostream>
#include <vector>
#include <queue>
#define INF 999

using namespace std;

vector<int> prims(vector<vector<int>>);

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
    vector<int> parent = prims(adj);

    for (int i = 1; i < parent.size(); i++) {
        cout << parent[i] << " - " << i << endl;
    }

    return 0;
}

vector<int> prims(vector<vector<int>> adj) {
    int v = adj.size();

    vector<int> parent(v, -1);
    vector<int> key(v, INF);
    vector<bool> inMST(v, false);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > q;

    key[0] = 0;
    q.push({ 0, 0 }); 

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;

        for (int i = 0; i < v; i++) {
            int weight = adj[u][i];

            if (weight != 0 &&
                !inMST[i] &&
                weight < key[i]) {

                key[i] = weight;
                parent[i] = u;

                q.push({ key[i], i });
            }
        }
    }

    return parent;
}
