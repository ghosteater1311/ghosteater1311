#include <bits/stdc++.h>
using namespace std;

struct Edge 
{
    int to, rev;
    int capacity;
};

class Dinic 
{
    int n;
    vector<vector<Edge>> adj;
    vector<int> level, ptr;

    bool bfs(int s, int t) 
    {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);

        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            for (const auto &edge : adj[node]) 
            {
                if (edge.capacity > 0 && level[edge.to] == -1) 
                {
                    level[edge.to] = level[node] + 1;
                    q.push(edge.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int node, int flow, int t) 
    {
        if (node == t) return flow;
        for (int &i = ptr[node]; i < adj[node].size(); ++i) 
        {
            Edge &edge = adj[node][i];
            if (level[edge.to] == level[node] + 1 && edge.capacity > 0) 
            {
                int pushed = dfs(edge.to, min(flow, edge.capacity), t);
                if (pushed > 0) 
                {
                    edge.capacity -= pushed;
                    adj[edge.to][edge.rev].capacity += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

public:
    Dinic(int n) : n(n), adj(n), level(n), ptr(n) {}

    void add_edge(int u, int v, int capacity) 
    {
        adj[u].push_back({v, (int)adj[v].size(), capacity});
        adj[v].push_back({u, (int)adj[u].size() - 1, 0}); // reverse edge with 0 capacity
    }

    int max_flow(int s, int t) 
    {
        int flow = 0;
        while (bfs(s, t)) 
        {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, INT_MAX, t)) 
            {
                flow += pushed;
            }
        }
        return flow;
    }
};

int main() 
{
    int n, m;
    cin >> n >> m; // Number of nodes and edges
    Dinic dinic(n);
    for (int i = 0; i < m; ++i) 
    {
        int u, v, cap;
        cin >> u >> v >> cap;
        dinic.add_edge(u, v, cap);
    }
    int s, t;
    cin >> s >> t; // Source and sink
    cout << dinic.max_flow(s, t) << endl;
    return 0;
}
