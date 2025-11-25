#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a;
    cout << "Введите размер масива: ";
    cin >> a;
    vector<int> n(a);
    for(int i = 0; i < a; i++) {
        cout << "Введите " << i + 1 << "-й  элемент: ";
        cin >> n[i];
    }
    for(int i = 0; i < a; i++) {
        if(n[i] % 2 == 0) {
            cout << n[i] << " ";
        }
    }
    for(int i = 0; i < a; i++) {
        if(n[i] % 2 == 1) {
            cout << n[i] << " ";
        }
    }

    return 0;
}