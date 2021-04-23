#ifndef OBJECT_ROOT_H
#define OBJECT_ROOT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Object_root {
protected:
    vector <string> arr_root;
    bool b; // Конец заполнения
public:
    Object_root() {
        bool a = true; // Переход на новый массив
        bool m_b = true; // Конец заполнения
        string name;
        int i = 0;
        vector <string> m_arr_root;
        while (a == true) {
            cin >> name;
            m_arr_root.push_back(name);
            if (i % 2 == 0 && m_arr_root.at(i) != m_arr_root.at(0))
                a = false;
            if (i % 2 != 0 && m_arr_root.at(i) == m_arr_root.at(0)) {
                a = false;
                m_b = false;
            }
            i++;
        }
        arr_root = m_arr_root;
        b = m_b;
    }
    ~Object_root() {}
};

#endif
