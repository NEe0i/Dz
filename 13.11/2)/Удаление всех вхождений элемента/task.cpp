#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 15, a[n];

    for(int i = 0;i < n; i++){
        a[i]= 1 + rand() % (1 - 20);
        cout << a[i] << " ";
    }
    cout << endl;

    int y;
    cout << "Введите число которое хотите удалить от 1 до 20: ";
    cin >> y;

    for(int i = 0; i < n; i++){
        if(a[i] != y){
            cout << a[i] << " ";
        }
    }
    return 0;
}