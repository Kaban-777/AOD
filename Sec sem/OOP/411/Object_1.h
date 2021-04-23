#ifndef OBJECT_1_H
#define OBJECT_1_H

#include <iostream>
#include <string>
#include <vector>
#include "Object_root.h"

using namespace std;

class Object_1 :public Object_root {
private:
    int num = arr_root.size() - 1; // Последний элемент arr_root
    int num_1;
protected:
    vector <string> arr_1;
    bool c = true; // Конец заполнения
public:
    Object_1() {
        if (b == true) {
            bool a = true; // Переход на новый массив
            bool m_c = true; // Конец заполнения
            string name;
            int i = 1;
            vector <string> m_arr_1;
            m_arr_1.push_back(arr_root.at(num));
            while (a == true) {
                cin >> name;
                m_arr_1.push_back(name);
                if (i % 2 == 0 && m_arr_1.at(i) != m_arr_1.at(0))
                    a = false;
                if (i % 2 != 0 && m_arr_1.at(i) == m_arr_1.at(0)) {
                    a = false;
                    m_c = false;
                }
                i++;
            }
            num_1 = m_arr_1.size() - 1; // last element of arr_1
            c = m_c;
            arr_1 = m_arr_1;
        }
    }
    void print_arr() {
        cout << endl << arr_root.at(0) << endl;
        if (b == false) {
            arr_root.pop_back(); arr_root.pop_back(); // delete last 2 elements
            cout << arr_root.at(0) << "  ";
            for (int k = 0; k < num - 1; k++) {
                if (k % 2 != 0) {
                    cout << arr_root.at(k);
                    if (k < num - 2)
                        cout << "  ";
                }
            }
        }
        if (c == false) {
            arr_root.pop_back(); // delete last element
            arr_1.pop_back(); arr_1.pop_back(); // delete last 2 elements
            cout << arr_root.at(0) << "  ";
            for (int k = 0; k <= num - 1; k++) {
                if (k % 2 != 0) {
                    cout << arr_root.at(k);
                    if (k < num - 1)
                        cout << "  ";
                }
            }
            cout << endl << arr_1.at(0) << "  ";
            for (int k2 = 0; k2 <= num_1 - 2; k2++) {
                if (k2 % 2 != 0) {
                    cout << arr_1.at(k2);
                    if (k2 < num_1 - 2)
                        cout << "  ";
                }
            }
        }
    }
    ~Object_1() {}
};

#endif // !OBJECT_1_H