#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cout << "Введите количество элементов: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Введите индекс K для удаления: ";
    cin >> k;

    if (k < 0 || k >= n) {
        cout << "Ошибка: индекс вне диапазона!";
        return 0;
    }

    for (int i = k; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    arr.pop_back();

    cout << "Результат:\n";
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
