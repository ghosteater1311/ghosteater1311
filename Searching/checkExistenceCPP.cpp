#include <iostream>
#include <unordered_set>
using namespace std;

void solve() 
{
    int n;
    cin >> n;
    int* a = new int[n];
    unordered_set<int> seen;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (seen.find(a[i]) != seen.end()) {
            cout << "1\n";
        } else {
            cout << "0\n";
            seen.insert(a[i]);
        }
    }

    delete[] a;
}

int main() {
    solve();
    return 0;
}
