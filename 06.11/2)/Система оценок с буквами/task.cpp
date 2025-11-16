#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Введите оценку A(5), B(4), C(3), D(2), F(1): " << endl;
    cin >> a;

    switch(a) {
        case 1: {
            a == 1;
            cout << "Ужасно" << endl;
            break;
        }
        case 2: {
            a == 2;
            cout << "Плохо" << endl;
            break;
        }
        case 3: {
            a == 3;
            cout << "Нормально" << endl;
            break;
        }
        case 4: {
            a == 4;
            cout << "Хорошо" << endl;
            break;
        }
        case 5: {
            a == 5;
            cout << "Отлично" << endl;
            break;
        }
        default: {
            cout << "Ошибка" << endl;
        }
    }

    return 0;
}