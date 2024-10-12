#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Triagle{
    private: 
    int width, height, volume;
    public:
        int setWidth(int width){
            this->width = width;
            return this->width;
        }
        int setHeight(int height){
            this->height = height;
            return this->height
        }
        int calculateVolume(){
            this->volume = width * height;
            return this->volume;
        }
};

int main() {
    int width, height;
    Triagle tr1;
    cin >> width;
    cin >> height;    
    tr1.setHeight(height);  
    tr1.setWidth(width);
    cout << tr1.calculateVolume();
   

    return 0;
}
