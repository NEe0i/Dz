#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Введите первое число: ";
    cin >> a;
    
    int b;
    cout << "Введите второе число: ";
    cin >> b;

    int op;
    cout << "Введите +(1) или -(2) или *(3) или /(4) (поставьте цифры): ";
    cin >> op;

    switch(op) {
        case 1:
            op == 1;
            cout << a + b;
            break;
        case 2:
        op == 2;
            cout << a - b;
            break;
        case 3:
            op == 3;
            cout << a * b;
            break;
        case 4:
            op == 4;
            cout << a / b;
            break;
        default: {
            cout << "Ошибка";
            break;
        }
            
    }
    return 0;
}