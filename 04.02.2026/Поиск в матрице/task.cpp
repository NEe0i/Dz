#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int N, M;
    cout << "Введите количество строк:";
    cin >> N;
    cout << "Введите количество столбцов:";
    cin >> M;
    int matrix[N][M];
    cout << "первая матрица" << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            matrix[i][j] =  -50 + rand() % (50 - (-50) + 1);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    int min = matrix[1][1], max= matrix[1][1];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(min > matrix[i][j]){
                min = matrix[i][j];
            }
            if(max < matrix[i][j]){
                max = matrix[i][j];
            }
        }
    }
    cout << "самое маленькое число: " << min << endl;
    cout << "Самое большое число: " << max << endl;
    int plus = 0, minus = 0, null = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(matrix[i][j] > 0){
                plus++;
            }
            if(matrix[i][j] < 0){
                minus++;
            }
            if(matrix[i][j] == 0){
                null++;
            }
        }
    }
    cout << "Количество положительных чисел: " << plus << endl;
    cout << "Количество отрицательных чисел: " << minus << endl;
    cout << "Количество нулевых чисел: " << null << endl;

}