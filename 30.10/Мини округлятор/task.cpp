#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double N;

    cout << "Введите число N: ";
    cin >> N;

    cout << fixed;
    cout << setprecision(2);

    cout << "Округлённое число: " << N << endl;

    return 0;
}
