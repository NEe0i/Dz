#include <iostream>
using namespace std;

int main() {
    float f = 3.14f;
    float* fPtr = &f;

    int* intPtr = reinterpret_cast<int*>(fPtr);
    cout << "Значение int: " << *intPtr;

}
