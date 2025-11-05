#include <iostream>
using namespace std;

int main() {
    double x;

    cout << "Введите значение x: ";
    cin >> x;

    double y = 7 * x * x - 3 * x + 6;

    cout << "Значение выражения 7x^2 - 3x + 6 при x = " << x << " равно " << y << endl;

    return 0;
}
