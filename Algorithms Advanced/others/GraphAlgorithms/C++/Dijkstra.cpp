#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>> &adj, vector<int> &dist) 
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) 
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto neighbor : adj[node]) 
        {
            int next = neighbor.first;
            int weight = neighbor.second;

            if (dist[node] + weight < dist[next]) 
            {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }
}

int main() 
{
    int nodes = 5;
    vector<vector<pair<int, int>>> adj(nodes);
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[4].push_back({3, 2});
    adj[3].push_back({2, 1});

    vector<int> dist(nodes, INT_MAX);
    dijkstra(0, adj, dist);

    for (int i = 0; i < nodes; i++) 
    {
        cout << "Distance to " << i << ": " << dist[i] << endl;
    }
    return 0;
}
