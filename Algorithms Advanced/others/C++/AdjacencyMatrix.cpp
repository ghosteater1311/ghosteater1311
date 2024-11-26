#include <iostream>
using namespace std;

int main() 
{
    int vertices = 3;
    int adjMatrix[3][3] = {0};

    // Add edges (example graph)
    adjMatrix[0][1] = 1;
    adjMatrix[0][2] = 1;
    adjMatrix[1][2] = 1;

    // Print adjacency matrix
    for (int i = 0; i < vertices; i++) 
    {
        for (int j = 0; j < vertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
