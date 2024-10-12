#include <iostream>
#include <algorithm>



using namespace std;

/*
 * Complete the 'simpleArraySum' function below.
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY ar as parameter.
 */

int simpleArraySum(int ar[], int ar_count) {
    if (ar_count == 1) return ar[0];
    return ar[ar_count - 1] + simpleArraySum(ar, ar_count - 1);
}
//Write your main()
int main()
{
    int ar_count;
    int result;
    int ar[10000];

    cin >> ar_count;
    for (int i = 0; i < ar_count; i++) {
        cin >> ar[i];
    }

    result = simpleArraySum(ar, ar_count);

    cout << result << "\n";
    return 0;
}
