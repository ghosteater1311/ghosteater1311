#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>> &graph, int nodes) 
{
    vector<vector<int>> dist = graph;

    for (int k = 0; k < nodes; ++k) 
    {
        for (int i = 0; i < nodes; ++i) 
        {
            for (int j = 0; j < nodes; ++j) 
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < nodes; ++i) 
    {
        for (int j = 0; j < nodes; ++j) 
        {
            if (dist[i][j] == INT_MAX) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int nodes = 4;
    vector<vector<int>> graph = {
        {0, 3, INT_MAX, 5},
        {2, 0, INT_MAX, 4},
        {INT_MAX, 1, 0, INT_MAX},
        {INT_MAX, INT_MAX, 2, 0}};

    floydWarshall(graph, nodes);
    return 0;
}
