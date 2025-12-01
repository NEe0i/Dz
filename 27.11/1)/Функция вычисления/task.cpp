#include<iostream>
using namespace std;

int calculateSquare(int x){
    x *= x;
    return x;
}
int main(){
    int x;
    cout << "Введите число: ";
    cin >> x;
    cout << "Его квадрат: " << calculateSquare(x);
}