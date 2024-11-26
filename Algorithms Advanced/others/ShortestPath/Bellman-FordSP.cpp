// Bellman-Ford Algorithm (Single Source, Handles Negative Weights)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void bellmanFord(int source, int nodes, vector<vector<int>> &edges) 
{
    vector<int> dist(nodes, INT_MAX);
    dist[source] = 0;

    for (int i = 0; i < nodes - 1; i++) 
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
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    for (int i = 0; i < nodes; i++) 
    {
        cout << "Distance from " << source << " to " << i << " is " << dist[i] << endl;
    }
}

int main() 
{
    int nodes = 5;
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    bellmanFord(0, nodes, edges);
    return 0;
}
