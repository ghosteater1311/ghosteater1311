// 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int prim(int n, vector<vector<pair<int, int>>> &adj) 
{
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}
    int mstWeight = 0;

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;
        mstWeight += key[u];

        for (auto &[v, weight] : adj[u]) 
        {
            if (!inMST[v] && weight < key[v]) 
            {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }

    return mstWeight;
}

int main() 
{
    int n = 4;
    vector<vector<pair<int, int>>> adj(n);
    adj[0] = {{1, 10}, {2, 6}, {3, 5}};
    adj[1] = {{0, 10}, {3, 15}};
    adj[2] = {{0, 6}, {3, 4}};
    adj[3] = {{0, 5}, {1, 15}, {2, 4}};
    cout << "Minimum Spanning Tree weight: " << prim(n, adj) << endl;
    return 0;
}
