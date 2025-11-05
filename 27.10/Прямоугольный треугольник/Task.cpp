#include <iostream>
#include <cmath>3
using namespace std;

int main() {
    double a, b;
    cout << "Введите длину первого катета: ";
    cin >> a;
    cout << "Введите длину второго катета: ";
    cin >> b;

    if (a <= 0 || b <= 0) {
        cout << "Ошибка: длина катетов должна быть положительной!" << endl;
        return 0;
    }

    double c = sqrt(a*a + b*b);

    double perimeter = a + b + c;

    double s = perimeter / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    cout << "Гипотенуза: " << c << endl;
    cout << "Периметр: " << perimeter << endl;
    cout << "Площадь (по формуле Герона): " << area << endl;

    return 0;
}
