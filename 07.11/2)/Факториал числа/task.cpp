#include<iostream>
using namespace std;

int main(){
    int x, fac = 1, sum = 1;
    cout << "Введите число: ";
    cin >> x;

    if (x <= 0){
        cout << "Ошибка";
        return 0;
    }

    do{
        sum = sum * fac;
        fac++; 
    }while((x + 1) != fac);
    cout << sum;
    return 0;
}