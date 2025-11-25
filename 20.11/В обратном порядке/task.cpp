#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<short int> h;
    int i = 0;
    while (true) {
        cout << "Введите элемент массива или 0 чтобы закончить: ";
        int a; cin >> a;
        if(a != 0){
        h.push_back(a);
        i++;
        }
        else{
            break;
        }
    }

    reverse(h.begin(), h.end());

    for(auto elem : h) {
        if(elem != 0) {
            cout << elem << " " << endl;
        } 
    }

    return 0;
}