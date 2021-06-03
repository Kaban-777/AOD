#include <iostream>
#include "Calc.h"

using namespace std;

Calc::Calc(int m_j) {
    j = m_j;
    if (j > 0) {
        cin >> o1;
        if (o1 == 'C')
            exit(0);
        cin >> n2 >> o2;
        if (o2 == 'C')
            exit(0);
        cin >> n3 >> o3;
        if (o3 == 'C')
            exit(0);
        cin >> n4;
    }
    else {
        cin >> n1 >> o1;
        if (o1 == 'C')
            exit(0);
        cin >> n2 >> o2;
        if (o2 == 'C')
            exit(0);
        cin >> n3 >> o3;
        if (o3 == 'C')
            exit(0);
        cin >> n4;
    }
    i = 0;
}

void Calc::sum1(char o, int m_n1, int m_n2) {
    switch (o) {
    case '+':
        x = m_n1 + m_n2;
        break;
    case '-':
        x = m_n1 - m_n2;
        break;
    case '*':
        x = m_n1 * m_n2;
        break;
    case '%':
        x = m_n1 % m_n2;
        break;
    }
    i++;
    if (i < 2)
        sum2(o2, x, n3);
}

void Calc::sum2(char o, int m_n1, int m_n2) {
    switch (o) {
    case '+':
        x = m_n1 + m_n2;
        break;
    case '-':
        x = m_n1 - m_n2;
        break;
    case '*':
        x = m_n1 * m_n2;
        break;
    case '%':
        x = m_n1 % m_n2;
        break;
    }
    sum1(o3, x, n4);
}

int Calc::retur() {
    if (j > 0)
        sum1(o1, x, n2);
    else
        sum1(o1, n1, n2);
    if (j > 0)
        cout << endl;
    return x;
}

Calc::~Calc() {}
