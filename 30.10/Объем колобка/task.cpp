#include <iostream>
using namespace std;

int main() {
    double R;
    cout << "Введите Радиус: ";
    cin >> R;   

    double result = (4.0/3.0) * 3.14 * (R * R *R);

    cout << "Результат: " << result << endl;

    return 0;
}