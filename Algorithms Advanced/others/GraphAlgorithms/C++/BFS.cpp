#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>> &adj, vector<bool> &visited) 
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) 
        {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int nodes = 5;
    vector<vector<int>> adj(nodes);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<bool> visited(nodes, false);
    BFS(0, adj, visited);
    return 0;
}
