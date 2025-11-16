#include<iostream>
using namespace std;

int main(){
    int x;
    cout << "Введиде число от 0 до 100";
    cin >> x;

    if (0 <= x and x <= 59){
            cout << "F";
            return 0;
    }

    if (60 <= x and x <= 69){
        cout << "D";
        return 0;
        }
        
    if (70 <= x and x <= 79){
        cout << "C";
        return 0;
        }
    
    if (80 <= x and x <= 89){
        cout << "B";
        return 0;
    }
    if(90 <= x and x <= 100){
        cout << "A";
        return 0;
    }
    return 0;
    }
