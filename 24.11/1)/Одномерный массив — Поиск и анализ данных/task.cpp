#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    srand(time(NULL));
    int n[10];
    for(int i =0; i<10; i++){
        n[i] = -50+rand()% (-50 - 50);
        cout << n[i] << " ";
    }
    cout << endl;
    int min = n[1], max = n[1];
    int sum = 0;

    for(int i=0; i<10; i++){
        if(max < n[i]){
            max = n[i];
        }
        if(min > n[i]){
            min = n[i];
        }
        sum += n[i];
    }
    cout << "Минимальное число: " << min << endl;
    cout << "Максимальное число: " << max << endl;
    cout << "Среднеее число: " << sum / 10 << endl;
    int cr_counter = 0;
    for(int i=0; i < 10; i++){
        if (n[i] > sum / 10){
            cr_counter++;
        }
    }
    cout << "Количество чисел больше среднего: " << cr_counter << endl;
}