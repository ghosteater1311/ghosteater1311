#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    
  set < int > s;
  int Q;
  int type, num;
  
  cin >> Q;

  while (Q--) {
    cin >> type;
    cin >> num;

    switch (type) {

    case 1: {
      s.insert(num);
      break;
    }

    case 2: {
      set < int > ::iterator it = s.find(num);
      if (it != s.end()) {
        s.erase(num);
      } else {
        ;;
      }
      break;
    }

    case 3: {
      set < int > ::iterator it = s.find(num);
      if (it != s.end()) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
      break;
    }

    default:
      break;
    }
  }

  return 0;
}
