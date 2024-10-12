#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numberOfToys(vector<int> arr, int k)
{
    int count = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (k < arr[i])
        {
            break;
        }
        else 
        {
            k -= arr[i];
            count++;
        }
    }
    return count;
}

int main()
{
    int k; 
    vector<int> toys;
    int n;
    cin >> k >> n;
    toys.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> toys[i];
    }

    cout << numberOfToys(toys, k);
    exit(0);

}