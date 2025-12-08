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
    int summa = 0;
    int arr[N][M];
    for(int i =0; i < N; i++){
        for(int j=0; j < M; j++){
            arr[i][j] = 1+rand() % 100;
            cout << arr[i][j] << " ";
            summa += arr[i][j];
        }
        cout << endl;
    }
    cout << "Сумма всех элементов равна: " << summa;
    return 0;
}


