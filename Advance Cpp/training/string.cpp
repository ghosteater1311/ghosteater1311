
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    string b;

    cin >> a;
    cin >> b;
    cout << a.size() << ' ' << b.size() << endl;
    cout << a + b << endl;
    char c0 = a[0];
    char c1 = b[0];
    a[0] = c1;
    b[0] = c0;
    cout << a << " " << b;

    return 0;
}
