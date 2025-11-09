#include<iostream>
using namespace std;

int main(){
    double a, b;
    cout << "Введите число а ";
    cin >> a;
    cout << "Введите число b ";
    cin >> b;

    if (a == 0){
        if (b == 0){
            cout << "any";
            return 0;
        }
        else{
            cout << "no";
            return 0;
        }
    }
    else{
        int x = b / a;
        cout << x;
        return 0;
    }

}