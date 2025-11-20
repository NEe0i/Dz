#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    srand (time (NULL));
    int n = 15, a[n];
    int i;
    for(i = 0; i < n; i++){
        a[i]=rand() % (1 - 20);     
        cout << a [i] << " ";
    }
    cout << " " << endl;
    for(i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] == a[j]){
                a[j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

}