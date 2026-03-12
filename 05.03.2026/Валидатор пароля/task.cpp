#include<iostream>
#include<string>
#include <cctype>
#include <stdexcept>
using namespace std;

int passworld_Check(const string& password){
    if (password.length()< 8){
        throw length_error("Ошибка: пароль слишком короткий (минимум 8 символов)");
    }

    bool number = false;
    bool zaglav = false;
    bool stroch = false;

    for(char ch : password){
        if(isdigit(ch)){
            number = true;
        }
        if(isupper(ch)){
            zaglav = true;
        }
        if(islower(ch)){
            stroch = true;
        }
    }

    if (!number){
        cout << "Ошибка в пароле должно быть минимум одна цифра: " << endl;
    }
    if (!zaglav){
        cout << "Ошибка в пароле должна быть минимум одна заглавная буква: " << endl;
    }
    if (!stroch){
        cout << "Ошибка в пароле должна быть минимум одна строчная буква: " << endl;
    }}


int main(){
    string password;
    cout << "Введите пароль: ";
    cin >> password;
    try {
        passworld_Check(password);
        cout << "Пароль корректный!" << endl;
    }
    
    catch (const length_error& e) {
        cout << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;

}