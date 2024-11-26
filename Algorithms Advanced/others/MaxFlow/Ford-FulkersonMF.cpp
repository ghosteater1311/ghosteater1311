#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

bool dfs(int u, int t, vector<vector<int>> &capacity, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &parent) 
{
    visited[u] = true;
    if (u == t) return true;

    for (int v : adj[u]) 
    {
        if (!visited[v] && capacity[u][v] > 0) 
        {
            parent[v] = u;
            if (dfs(v, t, capacity, adj, visited, parent)) return true;
        }
    }
    return false;
}

int fordFulkerson(int n, int s, int t, vector<vector<int>> &capacity) 
{
    vector<vector<int>> adj(n);
    for (int u = 0; u < n; ++u) 
    {
        for (int v = 0; v < n; ++v) 
        {
            if (capacity[u][v] > 0) 
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }

    vector<int> parent(n);
    int maxFlow = 0;

    while (true) 
    {
        vector<bool> visited(n, false);
        if (!dfs(s, t, capacity, adj, visited, parent)) break;

        int pathFlow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) 
        {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) 
        {
            int u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() 
{
    int n = 6;
    vector<vector<int>> capacity = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    cout << "Maximum Flow: " << fordFulkerson(n, 0, 5, capacity) << endl;
    return 0;
}
