#include <iostream>
using namespace std;

int main() {
    int num1;
    cout << "Введите число: ";
    cin >> num1;
    int* ptr_num1 = &num1;
    int sqt = *ptr_num1 * *ptr_num1;
    cout << sqt << endl;
    return 0;
}