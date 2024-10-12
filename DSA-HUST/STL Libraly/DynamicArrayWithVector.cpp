#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a.push_back(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i];
    }
    a.clear();
    return 0;
}