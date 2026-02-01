#include <iostream>
using namespace std;

int main() {
    int age;
    cout << "Введите ваш возраст: ";
    cin >> age;

    if (age < 0) {
        cout << "Ошибка: возраст не может быть отрицательным!" << endl;
    } 
    else if (age <= 12) {
        cout << "Категория: Ребенок" << endl;
    } 
    else if (age <= 17) {
        cout << "Категория: Подросток" << endl;
    } 
    else if (age <= 64) {
        cout << "Кedатегория: Взрослый" << endl;
    } 
    else {
        cout << "Категория: Пенсионер" << endl;
    }

    return 0;
}
