#include<iostream>
using namespace std;

struct Point{
    double x1, y1;
    double x2, y2;
};

void printPoint(Point p){
    cout << "(" << p.x1 << "; " << p.y1 << ")";
}

int main(){
    Point p1 = {5.4 , 12.1};
    Point p2 = {7.3, 9.2};

    cout << "Первай точка: "; 
    printPoint(p1);
    cout << endl;
    cout << "Вторая точка: "; 
    printPoint(p2);
}