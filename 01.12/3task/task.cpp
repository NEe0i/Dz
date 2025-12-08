#include <iostream>
using namespace std;

int* naturals(int n) {
    int* ptr_main = new int[n];
    return(n, ptr_main);
    delete[] ptr_main;
}

int main() {
    int n;
    cout << "Введите число n: ";
    cin >> n;
    int* ptr = naturals(1);
    for(int i = 0; i < n; i++) {
        cout << "Введите "<< i+1 <<"-й элемент массива: ";
        cin >> ptr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
    return 0;
}