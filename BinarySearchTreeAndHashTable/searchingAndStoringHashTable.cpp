#include <bits/stdc++.h>

using namespace std;

int h(const string &s, int m)
{
    int code = 0;
    int base = 256;
    for (char c : s) {
        code = (code * base + c) % m;
    }
    return code;
}

int main()
{
    unordered_map<string, int> Hash;
    string s;
    while (true)
        {
        cin >> s;
        if (s == "*") break;
        if (Hash.find(s) == Hash.end())
        {
            Hash[s] = h(s, 100000);
        }
    }
    while (true)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "***") break;
        if (cmd == "insert")
        {
            string key;
            cin >> key;
            if (Hash.find(key) == Hash.end())
            {
                Hash[key] = h(key, 100000);
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (cmd == "find")
        {
            string key;
            cin >> key;
            if (Hash.find(key) != Hash.end())
                {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
