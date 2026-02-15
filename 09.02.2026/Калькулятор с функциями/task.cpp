#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "Ошибка: Деление на ноль! " << endl;
        return 0;
    }
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}

string get_operation_name(char symbol) {
    switch (symbol) {
        case '+': return "Сложение";
        case '-': return "Вычитание";
        case '*': return "Умножение";
        case '/': return "Деление";
        case '^': return "Возведение в степень";
        default:  return "Неизвестная операция";
    }
}

double calculate(char operation, double a, double b) {
    switch (operation) {
        case '+': return add(a, b);
        case '-': return subtract(a, b);
        case '*': return multiply(a, b);
        case '/': return divide(a, b);
        case '^': return power(a, b);
        default:
            cout << "Ошибка: Неверный символ операции!" << endl;
            return 0;
    }
}

int main() {
    double num1, num2;
    char op;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите операцию (+, -, *, /, ^): ";
    cin >> op;
    cout << "Введите второе число: ";
    cin >> num2;

    cout << "Выполняется: " << get_operation_name(op) << endl;
    double result = calculate(op, num1, num2);
    cout << "Результат: " << result << endl;

    return 0;
}
