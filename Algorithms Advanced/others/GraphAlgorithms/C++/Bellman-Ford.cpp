#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void bellmanFord(int start, int nodes, vector<vector<int>> &edges) 
{
    vector<int> dist(nodes, INT_MAX);
    dist[start] = 0;

    for (int i = 0; i < nodes - 1; ++i) 
    {
        for (auto edge : edges) 
        {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) 
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (auto edge : edges) 
    {
        int u = edge[0], v = edge[1], w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) 
        {
            cout << "Negative weight cycle detected\n";
            return;
        }
    }

    for (int i = 0; i < nodes; i++) 
    {
        cout << "Distance to " << i << ": " << dist[i] << endl;
    }
}

int main() 
{
    int nodes = 5;
    vector<vector<int>> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    bellmanFord(0, nodes, edges);
    return 0;
}
