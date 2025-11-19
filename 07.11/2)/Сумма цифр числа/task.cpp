#include<iostream>
using namespace std;

int main(){
    int x, sum = 0;
    cout << "Введите число: ";
    cin >> x;
    do{
        sum += x % 10;
        x /= 10;
    } while(x > 0);

    cout << "Сумма цифр: " << sum << endl;
    
    return 0;
}