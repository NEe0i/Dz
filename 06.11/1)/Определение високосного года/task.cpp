#include<iostream>
using namespace std;

int main(){
    int x;
    cout << "Введите число: ";
    cin >> x;

    if (x % 4 == 0){
        cout << "Год високосный";
        return 0;
    }
    else{
        cout << "Год невисокосный";
        return 0;
    }
}