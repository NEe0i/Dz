#include<iostream>
using namespace std;

int main(){
    int N , M;
    cout << "Введите колчиество строк: ";
    cin >> N;
    cout << "Введите количество столбцов: ";
    cin >> M;
    int arr[N][M];
    for(int i =0; i < N; i++){
        for(int j=0; j < M; j++){
            arr[i][j] = 0;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}