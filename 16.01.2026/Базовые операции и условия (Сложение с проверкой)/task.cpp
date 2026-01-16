#include <iostream>
using namespace std;

int main() {
    int num1, num2, sum;

    cout << "Введите первое число: ";
    cin >> num1;
    
    cout << "Введите второе число: ";
    cin >> num2;

    sum = num1 + num2;
    
    if (sum > 0) {
        cout << "Сумма положительная: " << sum << endl;
    } 
    else if (sum < 0) {
        cout << "Сумма отрицательная: " << sum << endl;
    } 
    else {
        cout << "Сумма равна нулю" << endl;
    }
    
    return 0;
}