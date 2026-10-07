#include <iostream>
#include <vector>
#define INF 999

using namespace std;

// FLOYD WARSHALL
vector<vector<int>> floydwarshall(vector<vector<int>>);

int main() {

    vector<vector<int>> adj = {
        {0,   2,   5, INF},
        {INF, 0,   1,   3},
        {INF, INF, 0,   2},
        {INF, INF, INF, 0}
    };

    vector<vector<int>> shortest = floydwarshall(adj);

    for (int i = 0; i < shortest.size(); i++) {
        for (int j = 0; j < shortest[i].size(); j++) {
            if (shortest[i][j] == INF)
                cout << "inf" << "\t";
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