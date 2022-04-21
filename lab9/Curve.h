#ifndef LAB9_CURVE_H
#define LAB9_CURVE_H
#include <iostream>
#include <cmath>

using namespace std;

template <typename T = double>
class Curve {
private:
    T x;
    T y;
    bool type{}; // 0 - sin(x), 1 - cos(x)
public:
    // КОНСТРУКТОРЫ
    Curve() = default;
    explicit Curve(T y) : y(y), x(0), type(false){}
    Curve(T x, bool type_function) : x(x), type(type_function) {
        y = (type) ? cos(x) : sin(x);
    }

    // МЕТОДЫ
    void print();
    bool type_function();
    T argument();
    void changeType();

    // ПЕРЕГРУЗКА ОПЕРАТОРОВ
    Curve<T> &operator=(Curve<T> func);
    Curve<T> operator+(Curve<T> func);
    Curve<T> operator-(Curve<T> func);
    Curve<T> operator-();
    Curve<T> operator*(double k);
    Curve<T> operator!();
    T operator()(T arg);
    T operator()(T arg, bool type_function);
};

template<typename T>
void Curve<T>::print() {
    cout << "y(x) = " << y << endl;
}

template<typename T>
bool Curve<T>::type_function() {
    return type;
}

template<typename T>
T Curve<T>::argument() {
    return x;
}

template<typename T>
void Curve<T>::changeType() {
    type = !(type);
}

template<typename T>
Curve<T> Curve<T>::operator+(Curve<T> func) {
    if (this->type_function() && func.type_function())
        return Curve(2 * cos((this->argument() + func.argument()) / 2) * cos((this->argument() - func.argument()) / 2));
    if (!this->type_function() || func.type_function())
        return Curve(2 * sin((this->argument() + func.argument()) / 2) * cos((this->argument() - func.argument()) / 2));
}

template<typename T>
Curve<T> operator+(const Curve<T>& x, const Curve<T>& y) {
    if (x.type_function() && y.type_function())
        return Curve(2 * cos((x.argument() + y.argument()) / 2) * cos((x.argument() - y.argument()) / 2));
    if (!x.type_function() || y.type_function())
        return Curve(2 * sin((x.argument() + y.argument()) / 2) * cos((x.argument() - y.argument()) / 2));
}

template<typename T>
Curve<T> operator-(const Curve<T>& x, const Curve<T>& y) {
    if (x.type_function() && y.type_function())
        return Curve(-2 * sin((x.argument() + y.argument()) / 2) * sin((x.argument() - y.argument()) / 2));
    if (!x.type_function() || y.type_function())
        return Curve(2 * sin((x.argument() - y.argument()) / 2) * cos((x.argument() + y.argument()) / 2));
}

template<typename T>
Curve<T> Curve<T>::operator-(Curve<T> func) {
    if (this->type_function() && func.type_function())
        return Curve(-2 * sin((this->argument() + func.argument()) / 2) * sin((this->argument() - func.argument()) / 2));
    if (!this->type_function() || func.type_function())
        return Curve(2 * sin((this->argument() - func.argument()) / 2) * cos((this->argument() + func.argument()) / 2));
}

template<typename T>
Curve<T> &Curve<T>::operator=(Curve<T> func) {
    this->x = func.x;
    this->y = func.y;
    this->type = func.type;
    return *this;
}

template<typename T>
Curve<T> Curve<T>::operator*(double k) {
    return Curve<T>(k * y);
}

template<typename T>
Curve<T> Curve<T>::operator-() {
    return Curve<T>(-y);
}

template<typename T>
Curve<T> Curve<T>::operator!() {
    this->changeType();
    if (type)
        return Curve(-sin(x));
    return Curve(cos(x));
}

template<typename T>
T Curve<T>::operator()(T arg) {
    if (type)
        return cos(arg);
    return sin(arg);
}

template<typename T>
T Curve<T>::operator()(T arg, bool type_function) {
    if (type_function)
        return cos(arg);
    return sin(arg);
}




#endif //LAB9_CURVE_H
