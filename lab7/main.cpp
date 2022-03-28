#include "TicTacToe.cpp"

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