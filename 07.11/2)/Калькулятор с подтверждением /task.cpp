#include <iostream>
#include <string>
using namespace std;

int main() {
    int num1;
    string check_num1;
    int num2;
    string check_num2;
    string sign;
    string check_num3;

    do {
        cout << "Введите число: " << endl;
        cin >> num1;
        cout << "Вы уверены?" << endl;
        cin >> check_num1;
        if(check_num1 == "нет") {
            break;            
        }

        cout << "Введите число: " << endl;
        cin >> num2;
        cout << "Вы уверены?" << endl;
        cin >> check_num2;
        if(check_num2 == "нет") {
            break;            
        }

        cout << "Введите знак: " << endl;
        cin >> sign;
        cout << "Вы уверены?" << endl;
        cin >> check_num3;
        if(check_num3 == "нет") {
            break;            
        }

        if(sign == "/") {
            cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            break;
        }
        else if(sign == "*") {
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        }
        else if(sign == "+") {
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        }
        else if(sign == "-") {
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }
    while(true);

    return 0;
}