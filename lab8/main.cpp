#include "BitmapSet.h"

int main() {
    // Проверка общего класса
    BitmapSet<int, 64> x;
    cout << "ОБЩИЙ КЛАСС" << endl;
    cout << "Количество элементов в массиве маски: "<< x.size() << endl;
    x.addElem(44);
    x.addElem(62);
    x.addElem(12);
    cout << "44: " << x.isIn(44) << "  12: " << x.isIn(12)
         << "  62: " << x.isIn(62) << "  45: " << x.isIn(45) << endl;
    x.delElem(12);
    cout << "44: " << x.isIn(44) << "  12: " << x.isIn(12)
         << "  62: " << x.isIn(62) << "  45: " << x.isIn(45) << endl;
    // Конец проверки общего класса

    // Проверка специализированного класса <long, 64>
    BitmapSet<long, 64> s;
    cout << endl << "СПЕЦИАЛИЗИРОВАННЫЙ КЛАСС" << endl;
    cout << "Первоначальное значение числа-маски: ";
    s.print();
    s.addElem(44);
    s.addElem(62);
    s.addElem(12);
    cout << "Значение числа-маски после добавления элементов: ";
    s.print();
    cout << "44: " << s.isIn(44) << "  12: " << s.isIn(12)
         << "  62: " << s.isIn(62) << "  45: " << s.isIn(45) << endl;
    s.delElem(12);
    cout << "44: " << s.isIn(44) << "  12: " << s.isIn(12)
         << "  62: " << s.isIn(62) << "  45: " << s.isIn(45) << endl;
    // Конец проверки специализированного класса <long, 64>

    return 0;
}
