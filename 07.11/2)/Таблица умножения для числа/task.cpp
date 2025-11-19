#include<iostream>
using namespace std;

int main(){
    int x, y = 0;
    cout << "Введите число: ";
    cin >> x;

    do{
        cout << x << "*" << y << "=" << x * y << endl;
        y++;
    } while(y != 11);
    return 0;
}