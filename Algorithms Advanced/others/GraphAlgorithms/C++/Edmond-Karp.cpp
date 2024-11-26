#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

bool bfs(int source, int sink, vector<vector<int>> &residual, vector<int> &parent) 
{
    int nodes = residual.size();
    vector<bool> visited(nodes, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < nodes; v++) 
        {
            if (!visited[v] && residual[u][v] > 0) 
            {
                parent[v] = u;
                if (v == sink) return true;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

int edmondKarp(vector<vector<int>> &capacity, int source, int sink) 
{
    int nodes = capacity.size();
    vector<vector<int>> residual = capacity;
    vector<int> parent(nodes, -1);
    int maxFlow = 0;

    while (bfs(source, sink, residual, parent)) 
    {
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
    cout << "The maximum possible flow is " << edmondKarp(capacity, 0, 5) << endl;
    return 0;
}
