#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    int M, N;

    cout << "Введите количество строк: ";
    cin >> M;

    cout << "Введите количество столбцов: ";
    cin >> N;

    int arr[M][N];

    srand(time(0));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = 1 + rand() % 10;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int col = 0; col < N; col++) {
        int temp[N];

        for (int row = 0; row < M; row++)
            temp[row] = arr[row][col];

        sort(temp, temp + M, greater<int>());

        for (int row = 0; row < M; row++)
            arr[row][col] = temp[row];
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
