#include<iostream>
using namespace std;

int main(){
    int x;
    cout << "Введите число от 0 до 23 ";
    cin >>  x;

    if (0 <= x and x <= 5){
        cout << "Ночь";
        return 0;
    }
    else{
        if (6 <= x and x <= 11){
            cout << "Утро";
            return 0;
        }
        else{
            if (12 <= x and x <= 17){
                cout << "День";
                return 0;
            }
            else{
                if (18 <= x and x <= 23){
                    cout << "Вечер";
                    return 0;
                }
                else{
                    cout << "Число должно быть от 0 до 23";
                    return 0;
                }
            }
        }
    }
}