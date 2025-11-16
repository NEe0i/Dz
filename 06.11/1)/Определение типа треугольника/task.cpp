#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cout << "Введите три стороны треугольника через пробел: ";
    cin >> a, b, c;
    
 if ((a + b) >= c and (a + c) >= b and (c + b) >= a){
        if (a == b and b == c){
            cout << "Треугольник Равнестороний";
            return 0;
        }
        else{
            if (a == b or b == c or a == c){
                cout << "Треугольник Равнебедренный";
                return 0;
            }
            else{
                cout << "Разносторонний";
                return 0;
            }
        }
    }
    else{
        cout << "не треугольник";
        return 0;
    }
}