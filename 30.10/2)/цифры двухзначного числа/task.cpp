#include <iostream>
using namespace std;

int main(){
    int a;
    cout << "Введите двухзначное число ";
    cin >> a;
    if (a < 10 or a > 100){
        cout << "число должно быть двухзначным";
        return 0;   
    }

    int x;
    cout << "Введите число: ";
    cin >> x;

    int edin, decytok, sum;
    edin = a / 10;
    decytok = a % 10;
    sum = decytok + edin;

    if (sum >= 10){
        cout << "YES" << endl;        
    }
    else{
        cout << "NO" << endl;
    }

    if (sum > x){
        cout << "YES" << endl;        
    }
    else{
        cout << "NO" << endl;
    }

    if ((sum % 6) == 0){
        cout << "YES" << endl;        
    }
    else{
        cout << "NO" << endl;
    }

    if (decytok > edin){
        cout << "YES" << endl;        
    }
    else{
        cout << "NO" << endl;
    }

    if (((decytok = 4) or (decytok = 7)) or (edin = 4) or (edin = 7)){
        cout << "YES" << endl;        
    }
    else{
        cout << "NO" << endl;
    }
    if (edin = 5){
        cout << "YES" << endl;        
    }
    else{
        cout << "NO" << endl;
    }
}