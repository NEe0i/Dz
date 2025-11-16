#include <iostream>
using namespace std;

int main() {
    int r;
    double a;
    cout << "Введите рублей(1) или долларов(2) или евро(3): " << endl;
    cin >> r;


    switch(r) {
        case 1: {
            r == 1;
            cout << "Ввдеите количество рублей: " << endl;
            cin >> a;
            cout << "Долларов: " << a / 80 << endl;
            cout << "Евро: " << a / 90 << endl;
            break;
        }
        case 2: {
            r == 2;
            cout << "Ввдеите количество долларов: " << endl;
            cin >> a;
            cout << "Рублей: " << a * 80 << endl;
            cout << "Евро: " << a / 1.15 << endl;
            break;
        }
        case 3: {
            r == 3;
            cout << "Ввдеите количество евро: " << endl;
            cin >> a;
            cout << "Рублей: " << a * 90 << endl;
            cout << "Долларов: " << a * 1.15 << endl;
            break;
        }

        default: {
            cout << "Ошибка" << endl;
        }
    }

    return 0;
}