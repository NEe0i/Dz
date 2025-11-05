#include <iostream>
using namespace std;

int main() {
    int days;

    cout << "Введите количество прошедших дней: ";
    cin >> days;

    if (days < 0) {
        cout << "Ошибка: количество дней не может быть отрицательным!" << endl;
        return 0;
    }

    int weeks = days / 7;

    cout << "Полных недель прошло: " << weeks << endl;

    return 0;
}
