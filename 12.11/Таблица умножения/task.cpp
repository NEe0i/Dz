#include<iostream>
using namespace std;

int main(){
    int x;
    cout << "Введите число: ";
    cin >> x;

    for(int i = 1;i != 11;){
        cout << x << " * " << i << " = " << x * i << endl;
        i++;
    }
    return 0;
}