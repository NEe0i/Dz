#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int arr[10];
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;

    int max = arr[0];
    int min = arr[0];
    double sum = 0;
    
    for (int i = 0; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    
        sum += arr[i];
    }

    cout << "Максимальный элемент: " << max << endl;
    cout << "Минимальный элемент:  " << min << endl;
    cout << "Среднее арифметическое: " << sum / 10 << endl;
    
    return 0;
}