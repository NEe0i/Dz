#include<iostream>
using namespace std;

int main(){
    int x, y;
    y = x;
    cout << "Введите целое положительное число ";
    cin >> x;
    if (x < 0){
        cout << "Ошибка число должно быть положительным";
        return 0;
    }
    while(x != 0){
        cout << x << ",   ";
        x = x - 1;
    }
    return 0;
}
