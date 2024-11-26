#include <iostream>
#include <queue>
using namespace std;

int main() 
{
    priority_queue<int> pq; // Max-heap by default
    pq.push(10);
    pq.push(20);
    pq.push(15);

    while (!pq.empty()) 
    {
        cout << pq.top() << " "; // Outputs the highest priority element
        pq.pop();
    }
    return 0;
}
