#include <iostream>
#include <list>
using namespace std;

int main() 
{
    list<int> lst = {1, 2, 3};
    lst.push_back(4);

    for (int x : lst) cout << x << " ";

    return 0;
}
