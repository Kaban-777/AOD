#include <iostream>

using namespace std;

class BaseClass{
protected:
    string base;
public:
    BaseClass(){
        cin >> base;
    }
};

class SecClass :public BaseClass{
protected:
    string base2;
    string arr[50];
    bool a;
public:
    SecClass(){
        for(int i = 0; i++; i<50){
            cin >> arr[i];
            if (i % 2 == 0 && arr[i] != base) {
                a = true;
                base2 = arr[i];
                break;
            }
            if(i % 2 != 0 && arr[i] == base) {
                a = false;
                break;
            }
        }
    }
};

class ThirdClass :public SecClass{
public:

};

int main(){


    return 0;
}