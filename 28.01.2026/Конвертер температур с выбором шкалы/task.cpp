#include <iostream>
#include <string>

using namespace std;

int main() {
    char fromScale, toScale;
    double temp, celsius, result;

    cout << "Из какой шкалы конвертировать? (C/F/K): ";
    cin >> fromScale;
    cout << "В какую шкалу конвертировать? (C/F/K): ";
    cin >> toScale;
    cout << "Введите значение температуры: ";
    cin >> temp;

    switch (toupper(fromScale)) {
        case 'C': celsius = temp; break;
        case 'F': celsius = (temp - 32) * 5 / 9; break;
        case 'K': celsius = temp - 273.15; break;
        default: 
            cout << "Ошибка: Неверная исходная шкала!" << endl; 
            return 1;
    }

    switch (toupper(toScale)) {
        case 'C': result = celsius; break;
        case 'F': result = (celsius * 9 / 5) + 32; break;
        case 'K': result = celsius + 273.15; break;
        default: 
            cout << "Ошибка: Неверная целевая шкала!" << endl; 
            return 1;
    }

    cout << "Результат: " << result << " " << (char)toupper(toScale) << endl;

    return 0;
}
