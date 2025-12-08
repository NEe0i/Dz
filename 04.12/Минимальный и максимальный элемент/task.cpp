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
    int min = 100, max = 0;
    int arr[N][M];
    for(int i =0; i < N; i++){
        for(int j=0; j < M; j++){
            arr[i][j] = 1+rand() % 100;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int index_i1 =0, index_j1=0, index_i2=0, index_j2=0;
    for(int i =0; i < N; i++){
        for(int j=0; j < M; j++){
            if(min > arr[i][j]){
                min = arr[i][j];
                index_i1 = i;
                index_j1 = j;
            }
            if(max < arr[i][j]){
                max = arr[i][j];
                index_i2 = i;
                index_j2 = j;
            }
        }
    }
    cout << "Самый минимальный элемент: " << min << " Его координаты (строка и столбец)" << index_j1 << " " << index_i1 << endl;
    cout << "Самый максимальный элемент: " << max << " Его координаты (строка и столбец)" << index_j2 << " " << index_i2 << endl;
    return 0;
}

