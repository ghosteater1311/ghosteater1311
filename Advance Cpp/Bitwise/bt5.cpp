#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int answer = 0;
	while (n != 0) {
		if (n & 1) {
			answer++;
		}
		n = n >> 1;
	}
	cout << "answer = " << answer;
	return 0;
}