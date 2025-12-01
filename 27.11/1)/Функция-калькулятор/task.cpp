#include <iostream>
using namespace std;

int calculator(int x, int y, int change) {
    if(change == 1) {
        return x + y;
    }
    else if(change == 2) {
        return x - y;
    }
    else if(change == 3) {
        return x * y;
    }
    else if(change == 4) {
        return x / y;
    }
}

int main() {
    int a;
    cout << "Введите число a: " << endl;
    cin >> a;
    int b;
    cout << "Введите число b: " << endl;
    cin >> b;
    int c;
    cout << "Введите сложение - '1', вычитание - '2', умножение -  '3', деление '4' " << endl; 
    cin >> c;
    cout << calculator(a, b, c) << endl;
    return 0;
}