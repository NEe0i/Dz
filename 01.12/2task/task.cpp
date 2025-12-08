#include <iostream>
using namespace std;

void unique() {
    int size;
    cout << "Введите размер массива: ";
    cin >> size;
    int* ptr_a = new int[size];
    for(int i = 0; i < size; i++) {
        cout << "Введите " << i+1<< "-й элемент массива: ";
        cin >> ptr_a[i];
    }
    int* ptr_b = new int[size];
    int c = 0;

    for (int i = 0; i < size; i++) {
        bool found = false;
        for (int j = 0; j < c; j++) {
            if (ptr_a[i] == ptr_b[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            ptr_b[c] = ptr_a[i];
            c++;
        }
    }
    for (int i = 0; i < c; i++) {
        cout << ptr_b[i] << " ";
    }
    cout << endl;

    delete[] ptr_a;
    delete[] ptr_b;
}

int main() {
    unique();
    return 0;
}