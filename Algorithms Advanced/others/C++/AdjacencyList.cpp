#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int vertices = 3;
    vector<vector<int>> adjList(vertices);

    // Add edges (example graph)
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(0);
    adjList[1].push_back(2);

    // Print adjacency list
    for (int i = 0; i < vertices; i++) 
    {
        cout << i << ": ";
        for (int j : adjList[i])
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
