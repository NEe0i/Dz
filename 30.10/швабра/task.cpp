#include <iostream>
using namespace std;

int main(){
    double a, b, c;
    cout << "Введите первую цену ";
    cin >> a;

    cout << "Введите вторую цену ";
    cin >> b;

    cout << "Введите третью цену ";
    cin >> c;

    if (a >= 1000 and b >= 1000 and c >= 1000){
        cout << "ошибка цены больше чем 1000";
        return 0;
    }

    if(a <= b and  a<= c){
        double resultat = 1000 - a;
        cout << resultat;
        return 0;
    }

    if(b <= a and  b<= c){
        double resultat = 1000 - b;
        cout << resultat;
        return 0;
    }
    
    if(c <= b and  c<= a){
        double resultat = 1000 - c;
        cout << resultat;
        return 0;
    }
}