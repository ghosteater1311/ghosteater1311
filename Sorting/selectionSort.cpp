#include <bits/stdc++.h>

using namespace std;

void selectionSort(int a[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        int min = a[i];
        int index = i;
        for (int k = i + 1; k <= n - 1; k++)
        {
            if (a[k] < min) 
            {
                min  = a[k];
                index = k;
            }
            int temp = a[i];
            a[i] = a[index];
            a[index] = temp;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[1000];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    selectionSort(a, n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " " ;
    }
    return 0;
}