#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "Введите три цены на телефоны: ";
    cin >> a >> b >> c;

    if ((a > b) and (a > c)){
        cout << a;
        return 0;
    }

    if ((b > a) and (b > c)){
        cout << b;
        return 0;
    }

    if ((c > a) and (c > b)){
        cout << c;
        return 0;
    }
}