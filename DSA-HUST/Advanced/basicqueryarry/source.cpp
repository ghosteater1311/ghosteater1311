#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    char ch;
    cin >> ch;

    while (true)
    {
        string query;
        cin >> query;

        if (query == "***")
        break;

        else if (query == "find-max")
        {
            cout << *max_element(arr.begin(), arr.end()) << endl;
        }
        else if (query == "find-min")
        {
            cout << *min_element(arr.begin(), arr.end()) << endl;
        }
        else if (query == "sum")
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += arr[i];
            }
            cout << sum << endl;
        }
        else if (query == "find-max-segment")
        {
            int i, j;
            cin >> i >> j;
            int MaxSeg = arr[i - 1];
            for (int k = i; k < j; ++k) 
            {
                MaxSeg = max(MaxSeg, arr[k]);
            }
            cout << MaxSeg << endl;
        }
    }

    return 0;
}