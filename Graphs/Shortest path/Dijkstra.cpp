#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int,int>>>,int);
int main()
{
	vector<vector<pair<int, int>>> adj =
	{ 
	{ {1,1},{7,2} },
	{ {1,0},{3,2},{2,3}},
	{ {7,0},{3,1},{4,4}},
	{ { 2,1 },{2,4}},
	{ {4,2},{2,3}}
	};
	vector<int> shortest = dijkstra(adj,0);
	for (int i = 0;i < adj.size();i++)
		cout << "\nShortest distance to node " << i << " = " << shortest[i];
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