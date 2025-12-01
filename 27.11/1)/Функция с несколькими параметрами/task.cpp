#include<iostream>
using namespace std;

int calculateRectangle(int a, int b){
    int s = a * b;
    int p = ((a*b)* 2);
    cout << "Его площадь: " << s << endl;
    cout << "Его периметр: " << p << endl;
    return 0;
}

int main(){
    int a, b;
    cout << "Введите ширену прямоугольника: ";
    cin >> a;
    cout << "Введите длину прямоугольника: ";
    cin >> b;
    calculateRectangle(a, b);
    return 0;
}