#include <iostream>

using namespace std;

int getMaxValue(int* p, int n) {
    int Max = p[0];
    for (int i = 0; i < n; i++)
    {
        if (Max < p[i]) Max = p[i];
    }
    return Max;
}

int main() {
    int n;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Max value = " << getMaxValue(arr, n);
    return 0;
}
