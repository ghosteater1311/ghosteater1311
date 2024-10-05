#include <iostream>
#include <algorithm>

using namespace std;

int Alice(int ar1[], int ar2[])
{
    int a = 0;
    for (int i = 0; i < 3; i++)
    {   
        if (ar1[i] == ar2[i]) a = a;
        if (ar1[i] > ar2[i]) a++;
    }
    return a;
}
int Bob(int ar1[], int ar2[])
{
    int b = 0;
    for (int i = 0; i < 3; i++)
    {
        if (ar1[i] == ar2[i]) b = b;
        if (ar2[i] > ar1[i]) b++;
    }
    return b;
}
    
int main()
{
    int a, b;
    int ar1[100], ar2[100];
    for (int i = 0; i < 3; i++) 
    {
        cin >> ar1[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> ar2[i];
    }
    a = Alice(ar1, ar2);
    b = Bob(ar1, ar2);
    
    cout << a << ' ' << b;

    return 0;
}
