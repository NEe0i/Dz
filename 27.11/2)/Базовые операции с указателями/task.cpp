#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Введите число a: ";
    cin >> a;
    int b;
    cout << "Введите число b: ";
    cin >> b;
    int* a_0 = &a;
    int* b_0 = &b;
    int c = *a_0;
    *a_0 = *b_0;
    *b_0 = c;
    cout <<"Число а: " <<  a << " и число b: " << b;
    return 0;
}