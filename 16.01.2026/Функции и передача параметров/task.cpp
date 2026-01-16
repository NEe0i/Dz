#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int countVowels(const string& str) {
    int count = 0;
    string vowels = "аеёиоуыэюяАЕЁИОУЫЭЮЯ";
    
    for (char c : str) {
        if (vowels.find(c) != string::npos) {
            count++;
        }
    }
    return count;
}

void removeSpaces(string& str) {
    string result;
    for (char c : str) {
        if (!isspace(static_cast<unsigned char>(c))) {
            result += c;
        }
    }
    str = result;
}

bool isPalindrome(const string& str) {
    string cleaned;
    for (char c : str) {
        if (!isspace(static_cast<unsigned char>(c))) {
            cleaned += tolower(static_cast<unsigned char>(c));
        }
    }

    int left = 0;
    int right = cleaned.length() - 1;
    
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    string testStr = "А роза упала на лапу Азора";

    cout << "Исходная строка:" << testStr << endl;
    int vowelCount = countVowels(testStr);
    cout << "Количество гласных букв: " << vowelCount << endl;
    string testStrCopy = testStr;
    cout << "Тестирование удаления пробелов:" << endl;
    removeSpaces(testStrCopy);
    cout << testStrCopy << endl;
    bool palindromeCheck = isPalindrome(testStr);
    if (palindromeCheck) {
        cout << "является палиндромом" << endl;
    } else {
        cout << "не является палиндромом" << endl;
    }

    return 0;
}