#include <iostream>

using namespace std;

class Digits {
private:
    long long int m_n;
    int m_i;

public:
    Digits(long long int n) {
        m_n = n;
    }

    long long int NumD() {
        if (m_n == 0)
            m_i = 1;
        else
            m_i = 0;
        while (m_n != 0) {
            m_n /= 10;
            m_i++;
        }
        return m_i;
    }
};

int main() {
    long long int n;
    cin >> n;
    Digits digits(n);
    cout << "n = " << n << endl << "N = " << digits.NumD();

    return 0;
}