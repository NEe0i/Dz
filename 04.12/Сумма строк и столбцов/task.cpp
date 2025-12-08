#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    srand(time(NULL));
    int N , M;
    cout << "Введите колчиество строк: ";
    cin >> N;
    cout << "Введите количество столбцов: ";
    cin >> M;
    int arr[N][M];
    for(int i =0; i < N; i++){
        for(int j=0; j < M; j++){
            arr[i][j] = 1+rand() % 100;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int sum = 0;
    for(int i =0; i < N; i++){
        for(int j =0; j < N; j++){
            sum += arr[i][j];
        }
        cout << "Сумма элементов " << i+1 <<"-й строки равна: " << sum << endl;
        sum = 0; 
    }
    cout << endl;
    for(int i =0; i < N; i++){
        for(int j =0; j < N; j++){
            sum += arr[j][i];
        }
        cout << "Сумма элементов " << i+1 <<"-й столбца равна: " << sum << endl;
        sum = 0; 
    }
    return 0;
}