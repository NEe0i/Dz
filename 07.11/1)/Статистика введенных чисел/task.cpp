#include<iostream>
using namespace std;

int main(){
    int x, sum, counter, min, max;
    max = 0;
    sum = 0;
    counter = 0;
    while(x != 0){
        cout << "Введите любое число или напишите 0 чтобы закончить" << endl;
        cin >> x;
        if (x == 0){
            break;
        }
        else{
            sum += x;
            counter++;
            if (min > x and x != 0){
                min = x;
            }
            if (max < x){
                max = x;
            }
        }
    }

    cout << "Количество чисел: " << counter << endl;
    cout << "Сумма Чисел равна: " << sum << endl;
    cout << "Среднее число равно: " << sum / counter << endl;
    cout << "Минимальное число " <<  min << endl;
    cout << "Максимальное число " <<  max << endl;
    return 0;
}