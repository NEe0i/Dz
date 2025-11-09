#include <iostream>
using namespace std;

int main() {
    double a, b;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;

    double result = 1 / (1 + ((a + b) / 2));

    cout << "Результат: " << result << endl;

    return 0;
}
