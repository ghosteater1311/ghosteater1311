#include <bits/stdc++.h>
using namespace std;

bool visited[8];

void BFS(int adjMatrix[8][8]) 
{  
    queue<int> q;               
    visited[0] = true;
    q.push(0);
    while (!q.empty()) 
    {
        int node = q.front();
        cout << node << " "; 
        q.pop();
        for (int i = 0; i < 8; i++) 
        {
            if (adjMatrix[node][i] == 1 && !visited[i]) 
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() 
{
    for (int i = 0; i < 8; i++)
    {
       visited[i] = false;
    }
    int adjMatrix[8][8] = {
        {0, 1, 1, 1, 1, 0, 0, 0},  
        {1, 0, 0, 0, 0, 0, 0, 0},  
        {1, 0, 0, 1, 0, 0, 0, 0},  
        {1, 0, 1, 0, 0, 1, 0, 1},  
        {1, 0, 0, 1, 0, 0, 1, 0}, 
        {0, 0, 0, 1, 0, 0, 0, 0},  
        {0, 0, 0, 0, 1, 0, 0, 0},  
        {0, 0, 0, 1, 0, 0, 0, 0}   
    };
    for (int i = 0; i < 8; i++)
    {
        if (visited[i] == false) BFS(adjMatrix);
    }
    return 0;
}