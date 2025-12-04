#include <iostream>
using namespace std;

int main() {
    int mas;
    cout << "Введите размерномть массива: ";
    cin >> mas;
    int arr[mas];
    for(int i = 0; i < mas; i++) {
        cout << "Введите "<< i + 1 << "-й элемент массива: ";
        cin >> arr[i];
    }
    int *j = arr;
    int sred = 0;
    int a = 0;
    int b = 0;
    for(char i : arr) {
        if(i < 0) {
            a++;
        }
        else if(i >= 0) {
            b++;
        }
        sred += i;
    }
    int jast = sred / mas;
    cout << "Отрицательных чисел: " << a << endl;
    cout << "Положительных чисел: " << b << endl;
    cout << "Среднее арифметичесвое: " << jast << endl;
    return 0;
}