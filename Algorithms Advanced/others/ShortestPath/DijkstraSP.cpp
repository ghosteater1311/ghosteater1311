// Dijkstra's Algorithm (Single Source, Non-negative Weights)
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int source, int nodes, vector<vector<pair<int, int>>> &adj) 
{
    vector<int> dist(nodes, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &[v, weight] : adj[u]) 
        {
            if (dist[u] + weight < dist[v]) 
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
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
    vector<vector<pair<int, int>>> adj(nodes);
    adj[0] = {{1, 10}, {4, 3}};
    adj[1] = {{2, 2}};
    adj[2] = {{3, 9}};
    adj[3] = {};
    adj[4] = {{1, 1}, {2, 8}};

    dijkstra(0, nodes, adj);
    return 0;
}
