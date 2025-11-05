#include <iostream>
using namespace std;

int main() {
    int num;

    cout << "Введите целое число: ";
    cin >> num;

    int prev = num - 1;

    int next = num + 1;

    cout << "The next number for the number " << num << " is " << next << "!" << endl;
    cout << "The previous number for the number" << num << " is " << prev << endl;
    
    return 0;
}