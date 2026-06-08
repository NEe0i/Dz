#include <iostream>
using namespace std;

int main() {
    void* ptr = malloc(sizeof(int));
    int* value = static_cast<int*>(ptr);

    *value = 42;

    cout << *value << endl;
    return 0;
}
