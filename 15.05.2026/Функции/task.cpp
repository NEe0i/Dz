#include <iostream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;


double Add(double a, double b) {
    return a + b;
}

double Subtract(double a, double b) {
    return a - b;
}

double Multiply(double a, double b) {
    return a * b;
}

double Divide(double a, double b) {
    return a / b;
}

int Modulo(int a, int b) {
    return a % b;
}

int main() {
    string inputLine;

    while (true) {
        cout << "Введите выражение (или q для выхода): ";

        if (!getline(cin, inputLine)) {
            break;
        }

        size_t firstNonSpace = inputLine.find_first_not_of(" \t");
        if (firstNonSpace != string::npos && inputLine[firstNonSpace] == 'q') {
            cout << "Программа завершена. До свидания!\n";
            break;
        }

        stringstream ss(inputLine);
        double num1, num2;
        char op;

        if (!(ss >> num1 >> op >> num2)) {
            cout << "Ошибка! Неверный формат выражения. Попробуйте еще раз.\n\n";
            continue;
        }

        string trailing;
        if (ss >> trailing) {
            cout << "Ошибка! Слишком много аргументов. Введите только два числа и один оператор.\n\n";
            continue;
        }

        bool hasError = false;

        switch (op) {
            case '+':
                cout << "Результат: " << Add(num1, num2) << "\n\n";
                break;
            case '-':
                cout << "Результат: " << Subtract(num1, num2) << "\n\n";
                break;
            case '*':
                cout << "Результат: " << Multiply(num1, num2) << "\n\n";
                break;
            case '/':

                if (num2 == 0.0) {
                    cout << "Ошибка! Деление на ноль запрещено.\n\n";
                    hasError = true;
                } else {
                    cout << "Результат: " << Divide(num1, num2) << "\n\n";
                }
                break;
            case '%':

                if (static_cast<int>(num2) == 0) {
                    cout << "Ошибка! Деление по модулю на ноль запрещено.\n\n";
                    hasError = true;
                } else {
                    int intNum1 = static_cast<int>(num1);
                    int intNum2 = static_cast<int>(num2);
                    cout << "Результат: " << Modulo(intNum1, intNum2) << "\n\n";
                }
                break;
            default:
                cout << "Ошибка! Неизвестный оператор '" << op << "'. Используйте +, -, *, / или %.\n\n";
                hasError = true;
                break;
        }

        if (hasError) {
            continue;
        }
    }

    return 0;
}