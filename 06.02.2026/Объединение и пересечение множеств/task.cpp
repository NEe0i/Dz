#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {

    set<int> set1 = {1, 3, 5, 7, 9};
    set<int> set2 = {2, 3, 5, 7, 11};
    set<int> unionSet, intersectionSet;

    unionSet = set1; 
    unionSet.insert(set2.begin(), set2.end());
    

    for (int num : set1) {
        if (set2.count(num)) {
            intersectionSet.insert(num);
        }
    }
    
    cout << "Объединение: ";
    for (int num : unionSet) {
        cout << num << " ";
    }
    
    cout << "\nПересечение: ";
    for (int num : intersectionSet) {
        cout << num << " ";
    }
    
    return 0;
}
