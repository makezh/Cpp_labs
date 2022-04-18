#ifndef LAB8_BITMAPSET_H
#define LAB8_BITMAPSET_H

#include <iostream>
#include <vector>

using namespace std;

template <typename T, int N>
class BitmapSet {
private:
    int cap = sizeof(T) * 8;
    int len = N / cap;
    vector<T> arr = vector<T>(len);
public:
    BitmapSet() = default;
    bool isIn(int elem);
    T elem(int index);
    void addElem(int elem);
    void delElem(int elem);
    T operator[](int i);
    int size();
};

template<typename T, int N>
bool BitmapSet<T, N>::isIn(int elem) {
    return (bool) ((1 << elem) & arr[elem / cap]);
}

template<typename T, int N>
void BitmapSet<T, N>::addElem(int elem) {
    arr[elem / cap] |= (1 << (elem % cap));
}

template<typename T, int N>
void BitmapSet<T, N>::delElem(int elem) {
    arr[elem / cap] &= ~(1 << (elem % cap));
}

template<typename T, int N>
T BitmapSet<T, N>::elem(int index) {
    return arr[index];
}

template<typename T, int N>
T BitmapSet<T, N>::operator[](int i) {
    return arr[i];
}

template<typename T, int N>
int BitmapSet<T, N>::size() {
    return arr.size();
}

template<>
class BitmapSet<long, 64> {
private:
    int cap = sizeof(long) * 8;
    long x{};
public:
    BitmapSet() = default;
    bool isIn(int elem) const;
    void addElem(int elem);
    void delElem(int elem);
    void print() const;
};

bool BitmapSet<long, 64>::isIn(int elem) const {
    return (bool) ((1 << elem) & x);
}

void BitmapSet<long, 64>::addElem(int elem){
    x |= (1 << (elem % cap));
}

void BitmapSet<long, 64>::delElem(int elem) {
    x &= ~(1 << (elem % cap));
}

void BitmapSet<long, 64>::print() const {
    cout << x << endl;
}

#endif //LAB8_BITMAPSET_H
