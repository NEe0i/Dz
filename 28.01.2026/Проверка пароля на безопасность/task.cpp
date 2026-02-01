#include <iostream>
#include <string>
#include <cctype> // Для функций isupper, islower, isdigit
using namespace std;

int main() {
    string password;
    cout << "Введите пароль для проверки: ";
    cin >> password;

    bool hasDigit = false;
    bool hasUpper = false;
    bool hasLower = false;
    bool hasSpecial = false;
    string specialChars = "!@#$%^&*";

    bool isLengthValid = password.length() >= 8;

    for (char c : password) {
        if (isdigit(c)) hasDigit = true;
        else if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (specialChars.find(c) != string::npos) hasSpecial = true;
    }

    bool isSafe = true;

    if (!isLengthValid) {
        cout << "Ошибка: Длина должна быть не менее 8 символов" << endl;
        isSafe = false;
    }
    if (!hasDigit) {
        cout << "Ошибка: Добавьте хотя бы одну цифру" << endl;
        isSafe = false;
    }
    if (!hasUpper) {
        cout << "Ошибка: Добавьте хотя бы одну заглавную букву" << endl;
        isSafe = false;
    }
    if (!hasLower) {
        cout << "Ошибка: Добавьте хотя бы одну строчную букву" << endl;
        isSafe = false;
    }
    if (!hasSpecial) {
        cout << "Ошибка: Добавьте спецсимвол (!@#$%^&*)" << endl;
        isSafe = false;
    }

    if (isSafe) {
        cout << "[+] Пароль надежен!" << endl;
    } else {
        cout << "\n[!] Пароль небезопасен. Исправьте ошибки выше." << endl;
    }

    return 0;
}
