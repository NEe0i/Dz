#include <iostream>
using namespace std;
int main() {
    auto sum = [](int a, int b) {
        return a + b;
    };

    int result = sum(20, 22);
    cout << result << endl;
    return 0;
}
