#include <bits/stdc++.h>
using namespace std;

class graph
{
private:
    /* data */
public:
    //undireccted graph 
    vector<vector<int>> createGraph(bool isDirected) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        if (!isDirected) {
            adj[v].push_back(u);
        }
    }

        return adj;
    }
    void printGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        int edgeCount = 0;

        cout << "Graph Representation:\n";
        for (int i = 0; i < n; i++) {
            cout << i << " = {";
            int m = adj[i].size();
            edgeCount += m;

            for (int j = 0; j < m; j++) {
             cout << adj[i][j];
                if (j != m - 1) cout << " ";
            }
            cout << "}" << endl;
        }
    }
    vector<vector<pair<int,int>>> createWeightedGraph(bool isDirected) {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int u, v , w;
        cin >> u >> v>>w;
        adj[u].push_back({v,w});
        if (!isDirected) {
            adj[v].push_back({u,w});
        }
    }

        return adj;
    }

    void printWeightedGraph(const vector<vector<pair<int, int>>>& adj) {
        for (int i = 0; i < adj.size(); i++) {
            cout << i << " -> ";
            for (const auto& neighbor : adj[i]) {
                cout << "{" << neighbor.first << ", w =" << neighbor.second << "} ";
            }
            cout << endl;
        }
    }

};


