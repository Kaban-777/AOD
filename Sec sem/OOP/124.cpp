#include <iostream>

using namespace std;

class Calc {
private:
    char o1, o2, o3;
    int n1, n2, n3, n4;
public:
    Calc(char m_o1, char m_o2, char m_o3, int m_n1, int m_n2, int m_n3, int m_n4) {
        o1 = m_o1, o2 = m_o2, o3 = m_o3, n1 = m_n1, n2 = m_n2, n3 = m_n3, n4 = m_n4;
    }
    int sum(char o, int m_n1, int m_n2) {
        int x;
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
        }
        return x;
    }
    ~Calc() {}
};

int main() {
    char o1, o2, o3;
    int n1, n2, n3, n4;

    cin >> n1 >> o1 >> n2 >> o2 >> n3 >> o3 >> n4;

    Calc calc(o1, o2, o3, n1, n2, n3, n4);
    cout << calc.sum(o3, calc.sum(o2, calc.sum(o1, n1, n2), n3), n4);

    return 0;
}