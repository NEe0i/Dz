#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Введите цвет светофора Зелёный(1) Жёлтый(2) Красный(3): " << endl;
    cin >> a;

    switch(a) {
        case 1: {
            a == 1;
            cout << "Зелёный" << endl;
            break;
        }
        case 2: {
            a == 2;
            cout << "Жёлтый" << endl;
            break;
        }
        case 3: {
            a == 3;
            cout << "Красный" << endl;
            break;
        }
        default: {
            cout << "Ошибка" << endl;
        }
    }

    return 0;
}