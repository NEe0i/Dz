#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x;

    cout << "Введите значение x: ";
    cin >> x;

    if (x < 0) {
        cout << "Ошибка: подкоренное выражение не может быть отрицательным!" << endl;
        return 0;

    double result = 3 * x - sqrt(x);

    cout << "Значение выражения 3*x - sqrt(x) при x = " << x << " равно " << result << endl;

    return 0;
}
