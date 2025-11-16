#include<iostream>
using namespace std;

int main(){
    int x;
    cout << "Введите число ";
    cin >> x;

    if ((x % 2) == 0){
        cout << "Четное";
        return 0;
    }
    else{
        cout << "нечетное";
        return 0;
    }
}