#include <iostream>

using namespace std;

class Calc {
public:
    Calc() {
        cout << "Constructor" << endl;
    }

    ~Calc() {
        cout << "Destructor";
    }
};

int main() {
    Calc calc;

    return 0;
}