#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[8];
    for(int i = 0; i < 8; i++) {
        cout << "Введите " << i + 1 << "-й массива: ";
        cin >> a[i];
    }
    reverse(begin(a), end(a));  
    for(int i=0;i < 8;i++){
        cout << a[i] << " ";
    }
    return 0;
}