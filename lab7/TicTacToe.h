// ЗАДАНИЕ (ВАРИАНТ 17)
// Доска для игры в крестики-нолики размером n × n с операциями:
// 1. получение размера доски;
// 2. получение ссылки на клетку с указанными координатами;
// 3. определение, является ли текущая позиция финальной.

#ifndef LAB7_TICTACTOE_H
#define LAB7_TICTACTOE_H

#include <iostream>
using namespace std;
class TicTacToe
{
private:
    class Row;
    int n;
    Row *arr;
    class Row  // подкласс строк матрицы (реализация)
    {
    public:
        int *row;

        // конструктор по умолчанию необходим для создания массива указателей на класс подстрок матрицы
        Row() {}

        Row(int size) {
            row = new int[size];  // создание массива целочисленных данных
            for (int i = 0; i < size; i++)  // инициализация полей нулями
            {
                row[i] = 0;
            }
        }

        int &operator[](int i)  // оператор [] возвращает ссылку на int
        {
            return row[i];
        }
    };

public:

    TicTacToe(int size);
    ~TicTacToe();
    Row & operator [] (int i);

    int getSize() const;

    bool checkDiagonal();
    bool checkRow();
    bool checkCol();

    void isFinal(int);

    friend istream& operator>>(istream &, TicTacToe&);
    friend ostream& operator<<(ostream &, TicTacToe&);
};

#endif //LAB7_TICTACTOE_H
