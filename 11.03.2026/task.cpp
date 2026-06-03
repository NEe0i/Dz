#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int binaryToDecimal(const string& bin) {
    int decimal = 0;
    for (int i = 0; i < 8; ++i) {
        if (bin[i] == '1') {
            decimal += pow(2, 7 - i);
        }
    }
    return decimal;
}

int main() {
    string binaryInput = "0110101100110100"; 
    cout << "Исходная строка (2сс): " << binaryInput << endl;

    vector<int> decimalArray;
    
    for (size_t i = 0; i < binaryInput.length(); i += 8) {
        string byteStr = binaryInput.substr(i, 8);
        int decimalValue = binaryToDecimal(byteStr);
        decimalArray.push_back(decimalValue);
    }

    cout << "Массив int (10сс): ";
    for (int num : decimalArray) {
        cout << num << " ";
    }
    cout << endl;
    map<int, char> asciiMap;
    for (int i = 32; i < 127; ++i) {
        asciiMap[i] = static_cast<char>(i);
    }
    string resultText = "";
    for (int code : decimalArray) {
        // Ищем код в нашей карте
        if (asciiMap.find(code) != asciiMap.end()) {
            resultText += asciiMap[code];
        } else {
            resultText += '?';
        }
    }

    cout << "Полученный текст: " << resultText << endl;

    return 0;
}
