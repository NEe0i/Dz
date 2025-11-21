#include<iostream>
using namespace std;

int main(){
    int m, x, element;
    cout << "Введите количество строк: ";
    cin >> m;
    cout << "Введите количество столбов: ";
    cin >> x;
    int arr[m][x];

    for(int i = 0; i< m; i++){
        for(int j=0; j<x; j++){
            arr[i][j] = ((i * i) + (j * j));
        }
    }

    for(int i = 0; i< m; i++){
        for(int j=0; j<x; j++){
            cout << arr[i][j] << " ";
        }
    cout << endl;
}
}