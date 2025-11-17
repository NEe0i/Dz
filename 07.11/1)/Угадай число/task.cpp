#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int x;
    x = x;
    int randomNumber = 1 + rand() % 100;
    cout << "Угадайте задуманное число" << endl;

    while (x != randomNumber){
        cin >> x;
        if (x < randomNumber){
            cout << "больше" << endl;
        }

        if (x > randomNumber){
            cout << "Меньше" << endl;
        }
        
    }
    cout << "Вы угадали задуманное число " << randomNumber << endl;
    return 0;
}