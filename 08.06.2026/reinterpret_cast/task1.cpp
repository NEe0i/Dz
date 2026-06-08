#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int number = 100;
    int* ptr = reinterpret_cast<int*>(static_cast<uintptr_t>(number));

    int restored_number = static_cast<int>(reinterpret_cast<uintptr_t>(ptr));
    cout << "Адрес (указатель): " << ptr<< endl;
    cout << "Значение обратно:   " << restored_number ;

    return 0;
}
