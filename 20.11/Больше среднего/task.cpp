#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int a, sum =0, counter = 0;
    while(true){
        cout << "Введите элемент массива или введите 0 тобы законить: ";
        cin >> a;
        if(a != 0){
            sum += a;
            counter++;
            v.push_back(a);
        }
        else{
            break;
        }
    }
    int counter_cr = 0;
    int cr_number = sum / counter;
    for(int i= 0; i < counter; i++){
        if(v[i] > cr_number){
            counter_cr++;
        }
        else{
            v.erase(v.begin() + i);
        }
    }
    cout << counter_cr << endl;
    for(int ve : v){
        cout << ve << " ";
    }
    cout << endl;
}