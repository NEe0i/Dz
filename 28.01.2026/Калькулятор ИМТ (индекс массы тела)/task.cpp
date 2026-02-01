#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double weight, height, bmi;

    cout << "Введите ваш вес (кг): ";
    cin >> weight;
    cout << "Введите ваш рост (метры, например 1.75): ";
    cin >> height;

    if (height <= 0 || weight <= 0) {
        cout << "Ошибка: рост и вес должны быть больше нуля!" << endl;
        return 1;
    }

    bmi = weight / (height * height);

    cout << fixed << setprecision(1);
    cout << "Ваш ИМТ: " << bmi << endl;

    cout << "Категория: ";
    if (bmi < 18.5) {
        cout << "Недостаточный вес" << endl;
    } 
    else if (bmi < 25.0) {
        cout << "Нормальный вес" << endl;
    } 
    else if (bmi < 30.0) {
        cout << "Избыточный вес" << endl;
    } 
    else {
        cout << "Ожирение" << endl;
    }

    return 0;
}
