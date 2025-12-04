#include <iostream>
using namespace std;

int main() {
    int num1;
    cout << "Введите числ: ";
    cin >> num1;
    int num2;
    cout << "Введите число 2: ";
    cin >> num2;
    int* ptr_num1 = &num1;
    int* ptr_num2 = &num2;
    if(*ptr_num1 < *ptr_num2) {
        cout << *ptr_num2 << endl;
    }
    else if(*ptr_num1 > *ptr_num2) {
        cout << *ptr_num1 << endl;
    }
    return 0;
}