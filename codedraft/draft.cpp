#include <iostream>
using namespace std;

int main() {
    double items[] = {500, 12.4, 94, 45, 3, 81, 1000.9, 85, 90, 1, 35};
    double discount;
    int index;
    double ans[11];
    double minus[11];
    cin >> discount;
    for (index = 0; index < 11; index++)
    {
        minus[index] = items[index] * (discount / 100);
        ans[index] = items[index] - minus[index]; 
    }
    for (index = 0; index < 11; index++)
    {
        cout << ans[index] << " ";
    }

    return 0;
}
