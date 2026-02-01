#include <iostream>
#include <limits>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Введите первое число: ";

    cout << "Введите операцию (+, -, *, /): ";
    cin >> op;
    cout << "Введите второе число: ";

    cout << "Результат: ";
    switch (op) {
        case '+':
            cout << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 * num2 << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Ошибка! Деление на ноль невозможно." << endl;
            } else {
                cout << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Ошибка! Операция '" << op << "' не поддерживается." << endl;
            break;
    }

    return 0;
}
