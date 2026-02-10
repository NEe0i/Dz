#include<iostream>
using namespace std;

int main(){
    int N;
    cout << "Введите сколько стольцоб и строк будут в матрицы: ";
    cin >> N;
    int matrix[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j){
                matrix[i][j] = 1;
                cout << matrix[i][j] << " ";
            }
            else{
                matrix[i][j] = 0;
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    int number = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            number++;
            cout << number << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matrix[i][j] = (i + j) % 2;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}