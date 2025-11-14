#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "Введите число a ";
    cin >> a;

    cout << "Введите число b ";
    cin >> b;

    cout << "Введите число c ";
    cin >> c;

    int sum;
    if (a > 0)
        sum += a;

    if (b > 0)
        sum += b;

    if (c > 0)
        sum += c;

    cout << "Сумма положительных чисел = " << sum << endl;
}