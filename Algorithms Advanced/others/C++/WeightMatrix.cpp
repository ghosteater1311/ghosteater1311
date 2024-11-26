#include <iostream>
#include <climits>
using namespace std;

int main() 
{
    const int INF = INT_MAX; // Infinity for no edge
    int vertices = 3;
    int weightMatrix[3][3] = {
        {0, 4, INF},
        {INF, 0, 3},
        {INF, INF, 0}
    };

    // Print weight matrix
    for (int i = 0; i < vertices; i++) 
    {
        for (int j = 0; j < vertices; j++) 
        {
            if (weightMatrix[i][j] == INF) cout << "INF ";
            else cout << weightMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
