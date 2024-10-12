#include<bits/stdc++.h>

using namespace std;

class Box{
    friend ostream& operator<<(ostream& out,Box& B);
    private:
        long long l,b,h;
    
    public:
        int getLength();
        int getBreadth();
        int getheight();
        long long CalculateVolume();
    
    //defult constructor
    Box(void){
        this->l = 0;
        this->b = 0;
        this->h = 0;
    }
    //parameterized constructor
    Box(int l,int b ,int h){
        this->l=l;
        this->b=b;
        this->h=h;
    }
    //copy constructor by reference
    Box(Box& box){
        this->l = box.getLength();
        this->b = box.getBreadth();
        this->h = box.getheight();
    }
    //overload <
    bool operator<(Box& b){
        if(this->l<b.getLength()){
            return true;
        }
        else if(this->b<b.getBreadth() && this->l==b.getLength()){
            return true;
        }
        else if(this->h<b.getheight() && this-> b== b.getBreadth() && this->l == b.getLength()){
            return true;
        }
        else{
            return false;
        }
    }
    
    
};

//overload <<
    ostream& operator<<(ostream& out,Box& B){
        out<<B.l<<" "<<B.b<<" "<<B.h;
        return out;
    }

int Box::getLength(){
    return Box::l;   
}
int Box::getBreadth(){
    return Box::b;
}
int Box::getheight(){
    return Box::h;
}
long long Box::CalculateVolume(){
    return Box::l*Box::b*Box::h;
}

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if(type == 3)
		{
			int l,b,h;
			cin >> l >> b >> h;
			Box NewBox(l,b,h);
			if (NewBox < temp)
			{
				cout <<"Lesser\n";
			}
			else
			{
				cout <<"Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() <<endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}