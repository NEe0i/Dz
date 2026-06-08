#include <iostream>
using namespace std;

void process(int* data) {
    cout << "Внутри process. Значение: " << *data << endl;
}

int main() {
    const int value = 5;
    process(const_cast<int*>(&value));

    return 0;
}
