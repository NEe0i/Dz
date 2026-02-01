#include <iostream>
using namespace std;

int main() {
    int hour;
    cout << "Введите текущий час (0-23): ";
    cin >> hour;

    if (hour < 0 || hour > 23) {
        cout << "Ошибка: введите число от 0 до 23!" << endl;
    } 

    else if (hour <= 5) {
        cout << "Сейчас ночь." << endl;
    } 
    else if (hour <= 11) {
        cout << "Сейчас утро." << endl;
    } 
    else if (hour <= 17) {
        cout << "Сейчас день." << endl;
    } 
    else {
        cout << "Сейчас вечер." << endl;
    }

    return 0;
}
