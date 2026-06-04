#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Book {
private:
    string title;       
    string author;      
    int year;           
    bool is_borrowed;   

public:
    Book() {
        title = "";
        author = "";
        year = 0;
        is_borrowed = false;
    }

    Book(string b_title, string b_author, int b_year) {
        title = b_title;
        author = b_author;
        year = b_year;
        is_borrowed = false;
    }

    string get_title() const { return title; }
    string get_author() const { return author; }
    int get_year() const { return year; }
    bool get_is_borrowed() const { return is_borrowed; }

    void set_is_borrowed(bool borrowed) { is_borrowed = borrowed; }
};

class Library {
private:
    Book books[100];     
    int book_count;      

public:
    Library() {
        book_count = 0;
    }

    void add_book(const Book& book) {
        if (book_count >= 100) {
            cout << "[Ошибка]: Библиотека заполнена! Максимум 100 книг.\n";
            return;
        }
        books[book_count] = book;
        book_count++;
        cout << "[Успех]: Книга \"" << book.get_title() << "\" успешно добавлена в каталог.\n";
    }

    void borrow_book(const string& title) {
        for (int i = 0; i < book_count; ++i) {
            if (books[i].get_title() == title) {
                if (books[i].get_is_borrowed()) {
                    cout << "[Инфо]: Книга \"" << title << "\" уже выдана другому читателю.\n";
                    return;
                }
                books[i].set_is_borrowed(true);
                cout << "[Успех]: Вы успешно взяли книгу \"" << title << "\".\n";
                return;
            }
        }
        cout << "[Ошибка]: Книга \"" << title << "\" отсутствует в нашей библиотеке.\n";
    }

    void return_book(const string& title) {
        for (int i = 0; i < book_count; ++i) {
            if (books[i].get_title() == title) {
                if (!books[i].get_is_borrowed()) {
                    cout << "[Инфо]: Книга \"" << title << "\" уже на полке в библиотеке.\n";
                    return;
                }
                books[i].set_is_borrowed(false);
                cout << "[Успех]: Книга \"" << title << "\" успешно возвращена в фонд.\n";
                return;
            }
        }
        cout << "[Ошибка]: Книга \"" << title << "\" не принадлежит нашей библиотеке.\n";
    }

    void list_available() const {
        cout << "\n--- Доступные книги в наличии ---\n";
        bool any_available = false;
        for (int i = 0; i < book_count; ++i) {
            if (!books[i].get_is_borrowed()) {
                cout << "- \"" << books[i].get_title() << "\" (Автор: " << books[i].get_author() << ", Год: " << books[i].get_year() << ")\n";
                any_available = true;
            }
        }
        if (!any_available) {
            cout << "  (в данный момент все книги выданы или библиотека пуста)\n";
        }
        cout << "---------------------------------\n";
    }

    void find_by_author(const string& author) const {
        cout << "\n--- Результаты поиска для автора \"" << author << "\" ---\n";
        bool found = false;
        for (int i = 0; i < book_count; ++i) {
            if (books[i].get_author() == author) {
                string status = books[i].get_is_borrowed() ? "[На руках]" : "[Доступна]";
                cout << "- \"" << books[i].get_title() << "\" (" << books[i].get_year() << ") — " << status << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "  Книг данного автора не найдено.\n";
        }
        cout << "-------------------------------------------\n";
    }
};

int GetValidatedInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        }
        cout << "[Ошибка]: Введите корректное число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    Library lib;

    while (true) {
        cout << "\n==== МЕНЮ УПРАВЛЕНИЯ БИБЛИОТЕКОЙ ====\n"
             << "1. Добавить новую книгу\n"
             << "2. Взять книгу по названию\n"
             << "3. Вернуть книгу по названию\n"
             << "4. Показать все доступные книги\n"
             << "5. Найти книги по автору\n"
             << "6. Выйти из системы\n";

        int choice = GetValidatedInt("Выберите действие (1-6): ");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 6) {
            cout << "\nСессия завершена. До свидания!\n";
            break;
        }

        switch (choice) {
            case 1: {
                string title, author;
                int year;

                cout << "Введите название книги: ";
                getline(cin, title);
                cout << "Введите автора книги: ";
                getline(cin, author);
                year = GetValidatedInt("Введите год издания: ");
                
                lib.add_book(Book(title, author, year));
                break;
            }
            case 2: {
                string title;
                cout << "Какую книгу вы хотите взять?: ";
                getline(cin, title);
                lib.borrow_book(title);
                break;
            }
            case 3: {
                string title;
                cout << "Какую книгу вы хотите вернуть?: ";
                getline(cin, title);
                lib.return_book(title);
                break;
            }
            case 4:
                lib.list_available();
                break;
            case 5: {
                string author;
                cout << "Введите имя автора для поиска: ";
                getline(cin, author);
                lib.find_by_author(author);
                break;
            }
            default:
                cout << "[Ошибка]: Неверный пункт меню. Повторите попытку.\n";
                break;
        }
    }

    return 0;
}
