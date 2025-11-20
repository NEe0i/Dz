#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(0));
    int n = 12, a[n], result[n];

    for (int i = 0; i < n; i++) {
        a[i] = rand() % (0 - 10);
        cout << a[i] << " ";
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            result[index] = a[i];
            index++;
        }
    }

    while (index < n) {
        result[index] = 0;
        index++;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
