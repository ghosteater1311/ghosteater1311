// S
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge 
{
    int u, v, weight;
    bool operator<(const Edge &other) const 
    {
        return weight < other.weight;
    }
};

class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) 
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) 
    {
        if (parent[x] != x) 
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSet(int x, int y) 
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) 
        {
            parent[rootY] = rootX;
        } 
        else if (rank[rootX] < rank[rootY]) 
        {
            parent[rootX] = rootY;
        } 
        else 
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }
};

int kruskal(int n, vector<Edge> &edges) 
{
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int mstWeight = 0;

    for (auto &edge : edges) 
    {
        if (dsu.unionSet(edge.u, edge.v)) 
        {
            mstWeight += edge.weight;
        }
    }

    return mstWeight;
}

int main() 
{
    int n = 4; // Number of nodes
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    cout << "Minimum Spanning Tree weight: " << kruskal(n, edges) << endl;
    return 0;
}
