#include<bits/stdc++.h>

using namespace std;

struct Student 
{
	string name;
	int age;
	void display() 
    {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
	void getInformation() 
    {
		cin >> name >> age;
	}
};

int main() 
{
	int n;
	Student *s = new Student[n];
	cin >> n;
	for (int i = 0; i < n; i++) 
    {
		s[i].getInformation();
	}
	for (int i = 0; i < n; i++) 
    {
		s[i].display();
	}
    delete[] s;
	return 0;
}