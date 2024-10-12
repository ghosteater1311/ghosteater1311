#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; 
    cin >> n;
    vector<int> v;
    
    while (n--) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    
    int x; 
    cin >> x;
    /* "-1" because 1-based index system */
    v.erase(v.begin() + x - 1); 
    
    int a, b; 
    cin >> a >> b;
    /* "-1" because 1-based index system */
    v.erase(v.begin() + a - 1, v.begin() + b - 1); 
    
    cout << v.size() << endl;
    
    for (int x : v) {
        cout << x << " ";
    }
       
    return 0;
}
