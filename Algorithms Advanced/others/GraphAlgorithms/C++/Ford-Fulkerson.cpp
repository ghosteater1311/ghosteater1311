#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

bool dfs(int u, int t, vector<vector<int>> &residual, vector<bool> &visited, vector<int> &parent) 
{
    visited[u] = true;
    if (u == t) return true;

    for (int v = 0; v < residual.size(); v++) 
    {
        if (!visited[v] && residual[u][v] > 0) 
        {
            parent[v] = u;
            if (dfs(v, t, residual, visited, parent)) return true;
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>> &capacity, int source, int sink) 
{
    int nodes = capacity.size();
    vector<vector<int>> residual = capacity;
    vector<int> parent(nodes, -1);
    int maxFlow = 0;

    while (true) 
    {
        vector<bool> visited(nodes, false);
        if (!dfs(source, sink, residual, visited, parent)) break;

        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) 
        {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) 
        {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() 
{
    vector<vector<int>> capacity = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};
    cout << "The maximum possible flow is " << fordFulkerson(capacity, 0, 5) << endl;
    return 0;
}
