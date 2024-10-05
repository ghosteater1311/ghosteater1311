#include<iostream>

using namespace std;

int main() {
	int a;
	cin >> a;
	a = a & (~(1 << (4 - 1)));
	cout << a;
	return 0;
}