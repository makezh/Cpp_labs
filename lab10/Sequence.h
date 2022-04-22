#ifndef LAB10_SEQUENCE_H
#define LAB10_SEQUENCE_H
#include <iostream>

using namespace std;

class Sequence {
private:
    int* arr;
    int size;
public:
    class Iterator;
    explicit Sequence(int n) : size(n) { arr = new int[n]; }

    int& operator[](const int& i) { return arr[i]; }

    int getSize() const {
        return size;
    }

    int countByte(int i) {
        int count = 0;
        for (; arr[i]; count++)
            arr[i] &= (arr[i] - 1);
        return count;
    }

    Iterator begin() { return arr; }
    Iterator end() { return arr + size; }

    class Iterator {
        int* cur;
    public:
        Iterator(int* first) : cur(first) {}

        int&  operator++ (int) { return *cur++; }
        int&  operator++ () { return *++cur; }

        bool operator!= (const Iterator& it) { return cur != it.cur; }
        bool operator== (const Iterator& it) { return cur == it.cur; }

        Iterator operator+=(int x) {
            for(int i = 0; i < CHAR_BIT * sizeof(*cur) && x>0 ; i++)
            {
                if ((*cur & (1 << i)) == 0)
                {
                    *cur |= (1 << i);
                    x--;
                }
            }
            return *this;
        }

        int& operator* () {
            int count = 0;
            int numb = *cur;
            for (; numb; count++)
                numb &= (numb - 1);
            return count;
        }
    };
};


#endif //LAB10_SEQUENCE_H
