#include<iostream>
using namespace std;

int main(){
    int x;
    cout << "Введите двухзначное число: ";
    cin >> x;

    if(x <= 9 or x >= 100){
        cout << "Ошибка число должно быть двухзначным";
        return 0;
    }
    int decytki = x / 10;
    int edinitchi = x % 10;

    cout << decytki << " " << edinitchi;
    return 0;
}