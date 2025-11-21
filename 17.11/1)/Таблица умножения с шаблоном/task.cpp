#include <iostream>
using namespace std;

int main() {
    int arr[6][6];
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            int y = i * j;

            if (y % 3 == 0)
                cout << y << " ";
            else
                cout << "-" << " ";
        }
        cout << endl;
    }

    return 0;
}