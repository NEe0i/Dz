#include <iostream>
#include <string>
#include <vector>
using namespace std;

string compress_rle(const string& input) {
    if (input.empty()) return "";

    string compressed = "";
    int n = input.length();

    for (int i = 0; i < n; i++) {
        int count = 1;
        while (i + 1 < n && input[i] == input[i + 1]) {
            count++;
            i++;
        }
        compressed += input[i];
        compressed += to_string(count);
    }
    return compressed;
}

string decompress_rle(const string& input) {
    if (input.empty()) return "";

    string decompressed = "";
    int n = input.length();

    for (int i = 0; i < n; i++) {
        char symbol = input[i];
        string countStr = "";
        
        i++;
        while (i < n && isdigit(input[i])) {
            countStr += input[i];
            i++;
        }
        i--;

        int count = stoi(countStr);
        decompressed.append(count, symbol);
    }
    return decompressed;
}

int main() {
    string original = "WWWWWWWWWWWWBWWWWWWWWWWWWBBB";
    string compressed = compress_rle(original);
    cout << "Исходная:  " << original << endl;
    cout << "Сжатая:    " << compressed << endl;
    string decompressed = decompress_rle(compressed);
    cout << "Распаковка: " << decompressed << endl;
    if (original == decompressed) {
        cout << "[Успех] Строки идентичны!" << endl;
    }

    return 0;
}
