#include<iostream>
using namespace std;

int main(){
    int counter;
    string x;
    counter = 3;

    while(counter > 0){
        cout << "Введите пароль" << endl;
        cin >> x;
        if(x == "qwerty"){
            cout << "Пароль Верный" << endl;
            return 0;
        }
        else{
            cout << "Пароль неверный" << endl;
            counter--;
        }
    }
    if (counter <= 0){
        cout << "Попытки закончились";
        return 0;
    }
}