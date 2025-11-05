#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x;

    cout << "Введите число: ";
    cin >> x;

    double square = pow(x, 2);

    double cube = pow(x, 3);

    double fifth = pow(x, 5);

    cout << square << " " << cube << " " << fifth << endl;
    return 0;
}
