#include<iostream>
using namespace std;

int main(){
    int age;
    cout << "Введите свой возраст: ";
    cin >> age;

    if (age < 18){
        cout << "Вам нельзя смотреть фильмы 18+";
        return 0;
    }
    else{
        cout << "Вам можно смотреть фильмы 18+";
        return 0;
    }
}