#include <iostream>
using namespace std;

int main() {
    double S, A;

    cout << "Введите общую стоимость S: ";
    cin >> S;

    cout << "Введите стоимость взрослого билета A: ";
    cin >> A;

    double child = S - 3 * A;

    if (child < 0) {
        cout << "Ошибка: введённые данные некорректны (стоимость не может быть отрицательной)." << endl;
        return 0;
    }

    cout << "Стоимость детского билета: " << child << " руб." << endl;

    return 0;
}
