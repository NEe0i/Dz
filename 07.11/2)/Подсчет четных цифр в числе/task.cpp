#include<iostream>
using namespace std;

int main(){
    int x, y, z;
    cout << "Введите число: ";
    cin >> x;

    do{
        z = x % 10;
        if((z % 2) == 0){
            y++;
        }
        x /= 10;
    }while(x != 0);
    cout << "Количество четных чисел в числе: " << y << endl;
    return 0;
}