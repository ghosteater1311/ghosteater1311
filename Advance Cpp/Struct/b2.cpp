#include <bits/stdc++.h>

using namespace std;

struct Student
{
    string name;
    int age;
    float score;
};

int main()
{
    int n, i;
    cin >> n;
    Student *s = new Student[n];
    for (i = 0; i < n; i++)
    {
        cin >> s[i].name >> s[i].age >> s[i].score;
    }
    
    Student smax = s[0];

    for (i = 0; i < n; i++)
    {
        if (s[i].score > smax.score)
        {
            smax = s[i];
        }
    }
    
    cout << "Name: " << smax.name << endl;
    cout << "Age: " << smax.age << endl;
    cout << "Score: "<< smax.score << endl;
    
    delete[] s;
    return 0;
}