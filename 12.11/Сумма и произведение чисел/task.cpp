#include<iostream>
using namespace std;

int main(){
    int n, sum, pro;
    cout << "Введите число: ";
    cin >> n;
    sum = 0;
    pro = 1;
    for(int i = 1; n > i;){
        i++;
        sum = i + sum;
        pro *= i;
    }
    cout << "Сумма " << sum << " И произведение " << pro;
    return 0;
}