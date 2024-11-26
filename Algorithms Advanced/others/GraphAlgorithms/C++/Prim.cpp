#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void prims(int nodes, vector<vector<pair<int, int>>> &adj) 
{
    vector<int> key(nodes, INT_MAX), parent(nodes, -1);
    vector<bool> inMST(nodes, false);
    key[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto &[v, weight] : adj[u]) 
        {
            if (!inMST[v] && weight < key[v]) 
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < nodes; i++) 
    {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() 
{
    int nodes = 5;
    vector<vector<pair<int, int>>> adj(nodes);
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adj[2] = {{1, 3}, {4, 7}};
    adj[3] = {{0, 6}, {1, 8}};
    adj[4] = {{1, 5}, {2, 7}};

    prims(nodes, adj);
    return 0;
}
