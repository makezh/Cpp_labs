#include "TicTacToe.cpp"

/*
                            ЗАДАНИЕ
    Доска для игры в крестики-нолики размером n × n с операциями: 
    1. получение размера доски; 
    2. получение ссылки на клетку с указанными координатами; 
    3. определение, является ли текущая позиция финальной. 

*/

int main() {
    cout << "Введите длину поля:\n";
    int n;
    cin >> n;

    TicTacToe m(n);  // Создание Крестиков-Ноликов

    cout << "Введите "<< m.getSize() - 1 << " значений (1 - X, 0 - O):\n";
    cin >> m;

    int last;  // Последний ход
    cout << "Введите ход:\n";
    cin >> last;

    m.isFinal(last);
    return 0;
}
