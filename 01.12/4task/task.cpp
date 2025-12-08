#include <iostream>
using namespace std;

int* sum_arrays(int a[], int b[], int n) {
    int* result = new int[n];
    for (int i = 0; i < n; i++) {
        result[i] = a[i] + b[i];
    }
    return result;
}

int main() {
    int m_a;
    cout << "Введите размер массивов: ";
    cin >> m_a;

    int* c = new int[m_a];
    int* d = new int[m_a];

    for (int i = 0; i < m_a; i++) {
        cout << "Введите "<< i+1 << "-й элемент массива a: ";
        cin >> c[i];
    }
    for (int i = 0; i < m_a; i++) {
        cout << "Введите "<<i+1 << "-й элемент массива b: ";
        cin >> d[i];
    }

    int* arr_main = sum_arrays(c, d, m_a);

    cout << "Массивы: ";
    for (int i = 0; i < m_a; i++) {
        cout << arr_main[i] << " " << endl;;
    }

    delete[] c;
    delete[] d;
    delete[] arr_main;

    return 0;
}