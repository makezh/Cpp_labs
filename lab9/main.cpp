#include "Curve.h"
int main() {
    Curve<double> x(3, false);
    Curve<double> y(4, false);

    Curve<double> res = x + x;  // проверка на бинарный плюс при инициализации
    res.print();

    res = x + y;  // проверка на бинарный минус
    res.print();

    res = y - x;  // проверка на бинарный минус
    res.print();

    res = x * 5.1;  // проверка умножения на число
    res.print();

    res = -x;  // проверка на унарный минус
    res.print();

    res = !x;  // проверка на дифференцирование
    res.print();

    cout << x(5, true)<< endl;  // проверка на оператор ()

    return 0;
}
