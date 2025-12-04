#include<iostream>
using namespace std;

int main(){
    int x;
    cout << "Введите число: ";
    cin >> x;
    int *num = &x;
    cout << "Цифры: ";
    while(x != 0){
        int num0 = *num % 10;
        cout << num0 << " ";
        *num = *num / 10;
    }
    return 0;
}

