#include <bits/stdc++.h>
using namespace std;

int memory[100000];

int fib(int n)
{   
    for (int i = 0; i < 100000; i++) memory[i] = -1;
    if (n <= 2) return 1;
    if (n == 3) return 2;
    if (memory[n] != -1) return memory[n];
    int result = fib(n - 1) * fib(n - 2) + fib(n - 3);
    memory[n] = result;
    return result;
}

int main()
{
    int n;
    cin >> n;
    int num = fib(n);
    cout << num;
    return 0;
}