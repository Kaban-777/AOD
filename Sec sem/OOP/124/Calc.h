#ifndef CALC_H
#define CALC_H

using namespace std;

class Calc {
private:
    char o1, o2, o3;
    int n1, n2, n3, n4, x, i = 0;
public:
    Calc();
    void sum1(char o, int m_n1, int m_n2);
    void sum2(char o, int m_n1, int m_n2);
    int retur();
    ~Calc();
};

#endif CALC_H
