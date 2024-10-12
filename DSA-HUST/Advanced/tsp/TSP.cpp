#include <bits/stdc++.h>

using namespace std;

int c[1000][1000], x[1000], n;
bool visited[1000];
int fopt = INT_MAX;
int f = 0;

void Try(int k)
{
    //x[k] = ?
    for (int i = 2; i <= n; i++)
    {
        if (!visited[i]) 
        {
            x[k] = i;
            visited[i] = true;
            f = f + c[x[k - 1]][x[k]];
            if (k == n)
            {
                //f += c[x[n]][x[1]];
                //if (f < fopt) fopt = f;
                int ftemp = f + c[x[n]][x[1]];
                if (fopt > ftemp) fopt = ftemp;
            }
            else Try(k + 1);
            visited[i] = false;
            f = f - c[x[k - 1]][x[k]];
            //if (k == n) f -= c[x[n]][x[1]];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    for (int m = 1; m <= n; m++) visited[m] = false;
    x[1] = 1;
    Try(2);
    cout << fopt;
    return 0;
}