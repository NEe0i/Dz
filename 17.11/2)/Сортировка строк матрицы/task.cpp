#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
    srand(time(NULL));
    int m, n;
    cout << "Введите количество строк: ";
    cin >> m;

    cout << "Введите количество столбов: ";
    cin >> n;

    int arr[m][n];
    for(int i = 0; i < m; i++){
        for(int j =0; j < n; j++){
            arr[i][j] = 1 + rand()%(1-10);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j =0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Сортированный массив" << endl;

    for (int i = 0; i < m; i++) {
        sort(arr[i], arr[i] + n);
    }

    for(int i = 0; i < m; i++){
        for(int j =0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}