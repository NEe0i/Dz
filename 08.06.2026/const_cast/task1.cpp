#include <iostream>
using namespace std;

int main() {
    const int x = 10;
    const int* ptr = &x;

    int* nonConstPtr = const_cast<int*>(ptr);

    *nonConstPtr = 20;

    cout << "Оригинальная переменная x: " << x <<endl;
    cout << "Значение через nonConstPtr: " << *nonConstPtr;

    return 0;
}
