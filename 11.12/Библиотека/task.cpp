#include <iostream>
#include <string>

using namespace std;

class LibraryItem {
protected:
    int id;
    string title;
    int year;
public:

    LibraryItem(int id, string title, int year) : id(id), title(title), year(year) {
        cout << "Конструктор LibraryItem";
    }

    virtual void printDescription() const {
        cout << "ID: " << id
             << ", Название: " << title
             << ", Год: " << year << endl;
    }

    virtual ~LibraryItem() {
        cout << "Деструктор LibraryItem\n";
    }
};

class Book : public LibraryItem {
protected:
    string author;
    int pageCount;
public:

    Book(int id, string title, int year, string author, int pageCount): LibraryItem(id, title, year), author(author), pageCount(pageCount) {
        cout << "Конструктор Book";
    }

    void printDescription() const override { // вызов версии родителя
        cout << "Автор: " << author << ", Страниц: " << pageCount << endl;
    }

    ~Book() override {
        cout << "Деструктор Book";
    }
};

class ScientificBook : public Book {
private:
    string field;

public:

    ScientificBook(int id, string title, int year,string author, int pageCount, string field): Book(id, title, year, author, pageCount), field(field) {
        cout << "Конструктор ScientificBook";
    }

    void printDescription() const override {
        Book::printDescription();
        cout << "Область науки: " << field << endl;
    }

    ~ScientificBook() override {
        cout << "Деструктор ScientificBook\n";
    }
};

int main() {
    cout << "Создание LibraryItem ";
    LibraryItem item(1, "Общий каталог", 2000);
    item.printDescription();

    cout << "Создание Book ";
    Book book(2, "Война и мир", 1869, "Л. Толстой", 1225);
    book.printDescription();

    cout << "Создание ScientificBook";
    ScientificBook sciBook(3, "Квантовая механика", 2015, "Ландау", 800, "Физика");
    sciBook.printDescription();

    cout << "Завершение программы";
    return 0;
}