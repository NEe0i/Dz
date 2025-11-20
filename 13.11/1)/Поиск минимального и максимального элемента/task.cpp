#include<iostream>
using namespace std;

int main(){
    int x; 
    int a[x];
    int i;
    cout << "Введите размер массива: ";
    cin >> x;
    int min = a[0], max = a[0];

    int index1 = 0;
    int index2 = 0;

    for(i = 0; i < x; i++){
        cout << "Введите " << i + 1 << "-е число массива: ";
        cin >> a[i];
        cout << a[i] << endl;
    }

    for(int j = 0; j < x; j++) {
        if(a[j] < min) {
            min = a[j];
            index1 = j;
        }
        if(a[j] > max) {
            max = a[j];
            index2 = j;
        }
    }
    cout << min << " " << index1 + 1 << endl;
    cout << max << " " << index2 + 1 << endl;
    return 0;
}