#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

bool bfs(int s, int t, vector<vector<int>> &capacity, vector<vector<int>> &adj, vector<int> &parent) 
{
    fill(parent.begin(), parent.end(), -1);
    queue<int> q;
    q.push(s);
    parent[s] = s;

    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) 
        {
            if (parent[v] == -1 && capacity[u][v] > 0) 
            {
                parent[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int edmondsKarp(int n, int s, int t, vector<vector<int>> &capacity) 
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

    while (bfs(s, t, capacity, adj, parent)) 
    {
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

    cout << "Maximum Flow: " << edmondsKarp(n, 0, 5, capacity) << endl;
    return 0;
}
