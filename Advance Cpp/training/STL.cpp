#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int LowerBound(vector<int> &nums, int n, int target) {
    int s = 0, e = n-1;
    while(s <= e) {
        int mid = s + (e-s)/2;
        if(nums[mid] >= target) {
          e = mid-1;  
        } else {
            s = mid+1;
        }
    }
    return s;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int q;
    cin >> q;
    vector<int> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    vector<string> ans;
    for(int i = 0; i < q; i++) {
        int index = LowerBound(nums, n, queries[i]);
        if(nums[index] == queries[i]) cout << "Yes " << index+1 << endl;
        else cout << "No " << index+1 << endl;
    }
    return 0;
}