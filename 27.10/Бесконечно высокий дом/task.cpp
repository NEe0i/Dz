#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введите номер квартиры: ";
    cin >> N;

    if (N <= 0) {
        cout << "Ошибка: номер квартиры должен быть больше нуля." << endl;
        return 0;
    }

    int floor = (N - 1) / 12 + 1;

    cout << "Квартира №" << N << " находится на " << floor << " этаже." << endl;

    return 0;
}
