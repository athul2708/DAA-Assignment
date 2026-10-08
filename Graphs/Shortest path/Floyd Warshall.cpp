#include <iostream>
#include <vector>
#define INF 999

using namespace std;

// FLOYD WARSHALL
vector<vector<int>> floydwarshall(vector<vector<int>>);

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;
    vector<vector<int>> adj(v, vector<int>(v));
    cout << "Enter the adjacency matrix (use 999 for no edge):\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> adj[i][j];
        }
    }
    vector<vector<int>> shortest = floydwarshall(adj);
    for (int i = 0; i < shortest.size(); i++) {
        for (int j = 0; j < shortest[i].size(); j++) {
            if (shortest[i][j] == INF)
                cout << "inf\t";
            else
                cout << shortest[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}

vector<vector<int>> floydwarshall(vector<vector<int>> adj) {

    int v = adj.size();

    for (int k = 0; k < v; k++) {

        for (int i = 0; i < v; i++) {

            for (int j = 0; j < v; j++) {

                if (adj[i][k] != INF &&
                    adj[k][j] != INF &&
                    adj[i][j] > adj[i][k] + adj[k][j]) {

                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    return adj;
}
