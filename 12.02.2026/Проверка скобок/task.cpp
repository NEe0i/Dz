#include <iostream>
#include <stack>
#include <string>
#include <map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    map<char, char> bracketMap = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char c : s) {
        if (bracketMap.count(c)) {
            if (!st.empty() && st.top() == bracketMap[c]) {
                st.pop();
            } else {
                return false;
            }
        } 
        else {
            st.push(c);
        }
    }

    return st.empty();
}

int main() {
    string test1 = "({[]})";
    string test2 = "({[})";
    string test3 = "()[]{}";
    string test4 = "(]";

    cout << boolalpha; 
    cout << "Ввод: \"({[]})\" -> Вывод: " << isValid(test1) << endl;
    cout << "Ввод: \"({[})\"  -> Вывод: " << isValid(test2) << endl;
    cout << "Ввод: \"()[]{}\" -> Вывод: " << isValid(test3) << endl;
    cout << "Ввод: \"(]\"      -> Вывод: " << isValid(test4) << endl;

    return 0;
}
