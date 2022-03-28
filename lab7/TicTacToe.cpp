#include "TicTacToe.h"

TicTacToe::TicTacToe(int size): n(size)
{
    this->arr = new Row [n];
    for(int i = 0; i < n; i++)
        arr[i] = Row(n);

}

TicTacToe::~TicTacToe()
{
    for(int i = 0; i < n; i++)
        delete[] (arr[i].row);

    delete[] arr;
}

TicTacToe::Row &TicTacToe::operator[](int i) {
    return arr[i];
}

int TicTacToe::getSize() const { return n * n; }

istream& operator>>(istream &in, TicTacToe&t)
{
    for(int i = 0; i < t.n - 1; i++)
        for(int j = 0; j < t.n; j++)
            in >> t[i][j];

    for(int j = 0; j < t.n - 1; j++)
        in >> t[t.n-1][j];

    return in;
}

ostream &operator<<(ostream &out, TicTacToe &t)
{
    for(int i = 0; i < t.n; i++) {
        for (int j = 0; j < t.n; j++) {
            out << t[i][j] << ' ';
        }
        cout << '\n';
    }

    return out;
}

bool TicTacToe::checkDiagonal(){
    bool res = true;
    for(int i = 0; i < n - 1; i++)
        if (arr[i][i] != arr[i+1][i+1])
            res = false;

    return res;
}

bool TicTacToe::checkRow() {
    bool res = true;
    for(int j = 0; j < n - 1; j++)
        if (arr[n-1][j] != arr[n-1][j+1])
            res = false;

    return res;
}

bool TicTacToe::checkCol() {
    bool res = true;
    for(int i = 0; i < n - 1; i++)
        if (arr[i][n-1] != arr[i+1][n-1])
            res = false;

    return res;
}

void TicTacToe::isFinal(int elem) {
    arr[n-1][n-1] = elem;
    if (checkRow() || checkCol() || checkDiagonal())
        cout << "Это выигрышный ход!\n";
    else
        cout << "Это не выигрышный ход!\n";
}
