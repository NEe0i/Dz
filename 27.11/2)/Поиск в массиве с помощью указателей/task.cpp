#include <iostream>
using namespace std;

int main() {
    int a[10];
    for(int i = 0; i < 10; i++) {
        cout << "Ввдеите " << i + 1 << "-й массива: ";
        cin >> a[i];
    }
    int* ptr = a;
    for(int i = 0; i < 10; i++) {  
        if(*ptr < 0) {
            cout << *ptr << " " << i << endl;
            break;
        }
        ptr++;
    }
    return 0;
}