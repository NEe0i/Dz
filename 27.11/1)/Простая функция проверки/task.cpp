#include<iostream>
using namespace std;

int isPositive(int x){
    if (x > 0)
        return true;
    else
        return false;
}

int main(){
    int x;
    cout << "Введите число: ";
    cin >> x;
    if(isPositive(x) == 0){
        cout << "Неположительное";
    }
    else{
        cout << "Положительное";
    }
    return 0;
}