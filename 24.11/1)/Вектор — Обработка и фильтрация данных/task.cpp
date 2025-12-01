#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    vector<int>vec(20);
    for(int x : vec){
        x = 1+rand()% 20 - 1;
        cout << x << " ";
    }
    cout << endl;

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    cout << "После удаления дубликатов: ";
    for (int x : vec){
        cout << x << " ";
    }
    cout << endl;
    sort(vec.begin(), vec.end());

    cout << "Отсортированный вектор: ";
    for (int x : vec) cout << x << " ";
    cout << endl;

    vector<int> even, odd;
    for (int x : vec) {
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    cout << "Четные: ";
    for (int x : even) cout << x << " ";
    cout << endl;

    cout << "Нечетные: ";
    for (int x : odd) cout << x << " ";
    cout << endl;

    cout << "Медиана вектора: "  << endl;

    return 0;
}
