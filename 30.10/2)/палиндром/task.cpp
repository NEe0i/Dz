#include <iostream>
using namespace std;

int main(){
    int a;
    cout << "Введите трехзначное число: ";
    cin >> a;

    if (a < 100 or a > 1000){
        cout << "Ошибка число должно быть трехзначным";
        return 0;
    }

    int sotny;
    sotny = a / 100;

    int edin;
    edin = a % 10;

    if  (sotny == edin){
        cout << "Yes";
        return 0;
    }
    else{
        cout << "No";
        return 0; 
    }
    return 0;
}