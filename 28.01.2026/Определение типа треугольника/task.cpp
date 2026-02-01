#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double s[3];
    cout << "Введите три стороны треугольника через пробел: ";
    cin >> s[0] >> s[1] >> s[2];

    if (s[0] + s[1] <= s[2] || s[0] + s[2] <= s[1] || s[1] + s[2] <= s[0]) {
        cout << "Треугольник с такими сторонами не существует!" << endl;
        return 0;
    }

    cout << "Треугольник существует. Тип: " << endl;

    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "- Равносторонний" << endl;
    } else if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) {
        cout << "- Равнобедренный" << endl;
    } else {
        cout << "- Разносторонний" << endl;
    }

    sort(s, s + 3);

    if (abs((s[0] * s[0] + s[1] * s[1]) - (s[2] * s[2])) < 0.0001) {
        cout << "- Прямоугольный" << endl;
    }

    return 0;
}
