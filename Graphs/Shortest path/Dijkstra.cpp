#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int,int>>>,int);

int main()
{
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<pair<int, int>>> adj(v);
    cout << "Enter source, destination and weight of each edge:\n";
    for (int i = 0; i < e; i++) {
        int u, nbr, weight;
        cin >> u >> nbr >> weight;
        adj[u].push_back({weight, nbr});
        adj[nbr].push_back({weight, u});
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    vector<int> shortest = dijkstra(adj, source);
    for (int i = 0; i < adj.size(); i++)
        cout << "\nShortest distance to node " << i
             << " = " << shortest[i];
    return 0;
}

vector<int> dijkstra(vector<vector<pair<int,int>>> adj,int source)
{
	int v = adj.size();
	vector<int> dist(v, 99);
	dist[source] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, source });
	while (!pq.empty()) {
		auto [currdist, node] = pq.top();
		pq.pop();
		if (currdist > dist[node])
			continue;
		for (auto& edge: adj[node]) {
			int u = edge.second;
			int d = edge.first;
			if (currdist + d < dist[u]) {
				dist[u] = currdist + d;
				pq.push({ dist[u],u });
			}
		}
	}
	return dist;
}
