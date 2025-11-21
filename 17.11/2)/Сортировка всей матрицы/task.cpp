#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int M, N;

    cout << "Введите количество строк: ";
    cin >> M;

    cout << "Введите количество столбцов: ";
    cin >> N;

    int matrix[M][N];
    int arr[10000];
    int index = 0;

    srand(time(0));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 1 + rand() % 50;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            arr[index++] = matrix[i][j];
        }
    }

    sort(arr, arr + index);

    index = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = arr[index++];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
