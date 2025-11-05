#include <iostream>
using namespace std;

int main() {
    double l;

    cout << "Введите длину верёвки: ";
    cin >> l;

    if (l < 0) {
        cout << "Ошибка: длина верёвки не может быть отрицательной!" << endl;
        return 0;
    }

    double remaining = l * 0.66;

    cout << "Длина оставшейся верёвки: " << remaining << endl;

    return 0;
}
