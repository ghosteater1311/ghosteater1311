#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

#define ZERO 0
using namespace std;


int main() {
    unordered_map <string, int> students;
    int Q, type, mark;
    string name;
    cin >> Q;
    while (Q--)
    {
        cin >> type;
        switch(type){
        case 1: { //Add students and their mark
            cin >> name;
            cin >> mark; 
            
            auto it = students.find(name); 
            if (it != students.end()) { 
                students[name] += mark;
            } else {
                students.insert(std::make_pair(name, mark));
            }
            break;
        }
        case 2: { // Erase the mark of the student name
            std::cin >> name; 
            
            students.erase(name);
            break;
        }
        case 3:{ // Prints student's mark
            std::cin >> name;
			
            auto it2 = students.find(name);
            if (it2 != students.end()) {
            std::cout << students[name] << "\n";
            } else {
            std::cout << ZERO << "\n";
            }
            break;
        }
        }
    }
    
    return 0;
}
