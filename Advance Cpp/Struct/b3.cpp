#include <bits/stdc++.h>

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
};

int main()
{
    int i, n;
    cin >> n;
    Student *s = new Student[n];
    for (i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].age;
    }
    for (i = 0; i < n; i++)
    {
        s[i].display();
    }

    delete[] s;
    return 0;
}