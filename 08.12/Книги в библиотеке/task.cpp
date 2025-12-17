#include<iostream>
using namespace std;

struct Book{
    string title;
    string author;
    int year;
    int pages;
};

void printBookInfo(Book b){
    cout << "Название: " << b.title << endl;
    cout << "Автор: " << b.author << endl;
    cout << "Год издания: " << b.year << endl;
    cout << "Количество страниц: " << b.pages<< endl;
    cout << endl;
}

int main(){
    Book libraly[4] = {
        {"Война и мир","Лев Толстой", 1869, 1023},
        {"Властелин колец", "Дж. Р. Р. Толкин", 1955, 416},
        {"Маленький принц", "Антуан де Сент-Экзюпери", 1943, 109},
        {"Преступление и наказание", "Федор Достоевский", 1866, 243}};

    cout << "Книги в библеотеке: ";
    for(int i = 0; i < 4; i++){
        printBookInfo(libraly[i]);
    }
}