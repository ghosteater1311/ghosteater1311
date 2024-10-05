#include<iostream>

using namespace std;

int main() {
	char ch = 'a';
	char* p = &ch;
	cout << "Size of p: " << sizeof(p);
	return 0;
}