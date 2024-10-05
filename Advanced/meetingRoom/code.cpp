#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int mettingRoom(std::vector<int> s, std::vector<int> e)
{
    for (int i = 0; i < e.size() - 1; i++)
    {
        for (int j = 0; j < e.size() - i - 1; j++)
        {
            if (e[j] > e[j + 1])    
            {
                swap(e[j], e[j + 1]);
                swap(s[j], s[j + 1]);
            }
        }
    }
    int cnt = 1, j = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] >= e[j])
        {
            cnt++;
            j = i;
        }
    }
    return cnt;
}