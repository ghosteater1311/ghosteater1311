#include<iostream>

using namespace std;

int main() {
	int a, n;
	cin >> a >> n;
	cout << (1 & (a >> (n - 1)));
	return 0;
}