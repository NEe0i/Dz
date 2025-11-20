#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int  n = 10,  a [n]; 
    int  i;
    int chet = -1;
    srand (time (NULL));
    for (i = 0; i < n; i++){
        a[i]=rand() % (1 - 100);     
        cout << a [ i ] << " ";   
    }
    cout << " " << endl;
    for (i > 0; i--;){
        cout << a [ i ] << " ";
        if((i % 2) == 0){
            chet += 1;
        }
    }
    cout << " " << endl;
    cout << "Количество четных: " << chet << endl;
    return 0;
} 