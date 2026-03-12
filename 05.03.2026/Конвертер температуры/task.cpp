#include <iostream>
using namespace std;

int main() {
    double celsius;

    cout << "Введите температуру в градусах Цельсия: ";
    if (!(cin >> celsius)) {
        cout << "Ошибка: введено некорректное значение!" << endl;
        return 0; 
    }
    double fahrenheit = (celsius * 9.0 / 5.0) + 32;
    cout << "Температура в Фаренгейтах: " << fahrenheit << endl;

    return 0;
}