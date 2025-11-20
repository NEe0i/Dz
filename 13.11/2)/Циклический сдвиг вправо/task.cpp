#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    srand(time(NULL));
    int n=8, a[n], y;
    for(int i=0; i < n;i++){
        a[i]= 1+rand() % (1- 10);
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Введите на сколько сдвигов хотите сдвинуть вправо: ";
    cin >> y;

    int temp[n];

    for (int i = 0; i < n; i++) {
        temp[(i + y) % n] = a[i];
    }

    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
