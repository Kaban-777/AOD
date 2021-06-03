#include <iostream>
#include "Calc.h"

using namespace std;

int main() {
    int i = 0;
    while (1) {
        Calc calc(i);
        cout << calc.retur();
        i++;
    }

    return 0;
}
