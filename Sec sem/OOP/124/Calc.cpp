#include <iostream>
#include "Calc.h"

using namespace std;

Calc::Calc() {
    cin >> n1 >> o1 >> n2 >> o2 >> n3 >> o3 >> n4;
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
    sum1(o1, n1, n2);
    return x;
}

Calc::~Calc(){}