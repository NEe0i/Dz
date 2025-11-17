#include<iostream>
using namespace std;

int main(){
    double x ,y;
    int z;
    cout << "Введите первое число: ";
    cin >> x;
    cout << "Введите второе число: ";
    cin >> y;
    z = -1;
    while(z != 0){
        cout << "Что вы хотите сделать (1) Сложение, (2) Вычитание, (3) Умножение, (4) Деление без остатотка, Завершить программу 0" << endl;
        cin >> z;
        switch (z){
            case 1:
                cout << "x + y = " << x + y << endl;
                break;
            case 2:
                cout << "x - y = " << x - y << endl;
                break;
            case 3:
                cout << "x * y = " << x * y << endl;
                break;
            case 4:
                cout << "x / y =" << x / y << endl;
                break;
            case 0:
                cout << "Программа завершенна " << endl;
                break;
            }
        }
    return 0;
}
