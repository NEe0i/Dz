#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout <<endl;
    }

    

    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    int totalSum = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            totalSum += matrix[i][j];
            if (i == j) {
                mainDiagonalSum += matrix[i][j];
            }
            if (i + j == 3 + 1) {
                secondaryDiagonalSum += matrix[i][j];
            }
        }
    }
    cout << "Сумма элементов главной диагонали: " << mainDiagonalSum << endl;
    cout << "Сумма элементов побочной диагонали: " << secondaryDiagonalSum << endl;
    cout << "Сумма всех элементов матрицы: " << totalSum << endl;

    bool isSymmetric = true;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) break;
    }
    
    if (isSymmetric) {
        cout << "Матрица симметричная" << endl;
    } else {
        cout << "Матрица не симметричная" << endl;
    }
    
    return 0;
}