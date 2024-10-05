#include <bits/stdc++.h>

using namespace std;

struct Student {
	string name;
	int age;
};

int main() {
	Student s1;
	cin >> s1.name;
	cin >> s1.age;
	cout << "Name: " << s1.name << endl;
	cout << "Age: " << s1.age;
	return 0;
}