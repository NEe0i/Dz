#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int  n;
    cout << "Введите длину массива: ";
    cin >> n;
    int  a [n]; 
    int  i;

    srand (time (NULL));
    for (i = 0; i < n; i++){
        a[i]=rand() % (1 - 100);     
        cout << a [i] << " ";   
    }
    cout << " " << endl;

    int j;

    cout << "Введите индекс который вы хотите удалить от 0 до " << n - 1 << " : ";
    cin >> j;

    for (i = 0; i < n; i++){
        if(i != j){
        cout << a [i] << " ";} 
    }
    return 0;
} 