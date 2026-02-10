#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int N;
    cout << "Введите сколько стольцоб и строк будут в матрицы: ";
    cin >> N;
    int matrix[N][N];
    cout << "первая матрица" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matrix[i][j] = 1+rand()%10;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int matrix2[N][N];
    cout << "вторая матрица" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matrix2[i][j] = 1+rand()%10;
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    int matrix3[N][N];
    cout << "Сумма матриц" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matrix3[i][j] = matrix[i][j] + matrix2[i][j];
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }
    int x;
    cout << "Введите ччисло на которое будет умножееего число: ";
    cin >> x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix3[i][j] *= x;
            cout << matrix3[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += matrix3[i][j];
            cout << "Сумма строки " << i + 1 << ": " << rowSum << endl;
        }
    }
    for (int j = 0; j < N; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++){
             colSum += matrix3[i][j];
        cout << "Сумма столбца " << j + 1 << ": " << colSum << endl;
    }
    }
}