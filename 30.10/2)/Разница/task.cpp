#include <iostream> 
using namespace std;

int main() {
    int a, b, c;

    cout << "Введите три числа: ";
    cin >> a >> b >> c;

    int maxNum = a;
    int minNum = a;

    if (b > maxNum) maxNum = b;
    if (c > maxNum) maxNum = c;

    if (b < minNum) minNum = b;
    if (c < minNum) minNum = c;

    int diff = maxNum - minNum;

    cout << diff << endl;

    return 0;
}
