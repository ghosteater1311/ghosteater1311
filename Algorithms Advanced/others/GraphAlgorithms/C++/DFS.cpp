#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited) 
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) 
    {
        if (!visited[neighbor]) 
        {
            DFS(neighbor, adj, visited);
        }
    }
}

int main() 
{
    int nodes = 5;
    vector<vector<int>> adj(nodes);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<bool> visited(nodes, false);
    DFS(0, adj, visited);
    return 0;
}
