#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
        vector<int> integers(n);
        for (int i = 0; i < n; i++)
            cin >> integers[i];
        sort(integers.begin(), integers.end());
        for (int num : integers)
        cout << num << ' ';

    return 0;
}
