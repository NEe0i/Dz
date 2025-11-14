#include <iostream>
using namespace std;

int main(){
    int age;
    cout << "Введите свой возраст ";
    cin >> age;

    if (age <= 6){
        cout << "Baby";
        return 0;
    }

    if (7 <= age and age <= 17){
        cout << "SChOOLCHILD";
        return 0;
    }

    if (18 <= age and age <= 64){
        cout << "ADULT";
        return 0;
    }

    if (65 <= age and age <= 120){
        cout << "ELDER";
        return 0;
    }

    if (age > 120){
        cout << "GHOST";
        return 0;
    }
}