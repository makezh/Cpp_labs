#include "Sequence.h"

int main() {
    Sequence x(5);
    for(int i = 0; i < x.getSize(); i++)
        x[i] = 124+ i;

    ///// Итератор без изменений /////
    auto it1 = Sequence::Iterator(x.begin());
    while (it1 != x.end()) {
        cout << *it1 << ' ';
        it1++;
    }
    cout << endl;
    for(int i = 0; i < x.getSize(); i++)
        cout << x[i] << ' ';
    cout << endl << endl;
    ///////////////

    ///// Итератор c прибавлением 1 бита /////
    auto it2 = Sequence::Iterator(x.begin());
    while (it2 != x.end()) {
        it2 += 1;
        cout << *it2 << ' ';
        it2++;
    }
    cout << endl;
    for(int i = 0; i < x.getSize(); i++)
        cout << x[i] << ' ';
    ///////////////

    return 0;
}
