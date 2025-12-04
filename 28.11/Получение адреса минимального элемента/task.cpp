#include <iostream>
using namespace std;

int main() {
    int massiv;
    cout << "Введите размер массива: ";
    cin >> massiv;
    int mas[massiv];
    int mas0;
    for(int i = 0; i != massiv; i++) {
        cout << "Введите " << i +1 << "-й элемент массива: ";
        cin >> mas[i];
        mas0 = mas[i];
    }
    int j = 0;
    for(char i : mas) {
        if(i < mas0) {
            mas0 = i;
            ++j;
        }
    }
    cout <<  "Число: " << mas0 << " " << "Индекс: " << j;
    return 0;
}