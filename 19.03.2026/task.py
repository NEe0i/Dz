import json
import csv
import logging
import os
from statistics import mean

logging.basicConfig(
    filename="library.log",
    level=logging.INFO,
    format="%(asctime)s - %(levelname)s - %(message)s"
)

library = {}
DATA_FILE = "library.json"

def save_library(filename=DATA_FILE):
    """Сохранение библиотеки в JSON."""
    with open(filename, "w", encoding="utf-8") as file:
        json.dump(library, file, ensure_ascii=False, indent=4)


def load_library(filename=DATA_FILE):
    """Загрузка библиотеки из JSON."""
    global library

    if not os.path.exists(filename):
        library = {}
        save_library(filename)
        return

    try:
        with open(filename, "r", encoding="utf-8") as file:
            library = json.load(file)

    except json.JSONDecodeError:
        print("Файл библиотеки поврежден!")

        while True:
            choice = input(
                "Создать новый файл? (y/n): "
            ).strip().lower()

            if choice == "y":
                library = {}
                save_library(filename)
                break
            elif choice == "n":
                print("Программа завершена.")
                exit()
            else:
                print("Введите y или n.")

def add_book(isbn, title, author, year):
    """Добавление книги."""

    if not (isbn.isdigit() and len(isbn) == 13):
        raise ValueError("ISBN должен состоять из 13 цифр")

    if not (1900 <= year <= 2024):
        raise ValueError("Год должен быть между 1900 и 2024")

    if isbn in library:
        raise ValueError("Книга с таким ISBN уже существует")

    library[isbn] = {
        "title": title,
        "author": author,
        "year": year,
        "available": True,
        "times_borrowed": 0
    }

    save_library()
    logging.info(f"Добавлена книга: {title}")


def search_books(query, search_by="title"):
    """Поиск книг."""

    if search_by not in ("title", "author", "year"):
        raise ValueError("Недопустимое поле поиска")

    results = []

    for isbn, book in library.items():

        if search_by == "year":
            try:
                if book["year"] == int(query):
                    results.append({"isbn": isbn, **book})
            except ValueError:
                pass

        else:
            if query.lower() in book[search_by].lower():
                results.append({"isbn": isbn, **book})

    return results


def borrow_book(isbn):
    """Выдача книги."""

    if isbn not in library:
        raise ValueError("Книга не найдена")

    book = library[isbn]

    if not book["available"]:
        raise ValueError("Книга уже выдана")

    book["available"] = False
    book["times_borrowed"] += 1

    save_library()
    logging.info(f"Выдана книга: {book['title']}")

    return f"Книга '{book['title']}' успешно выдана."


def return_book(isbn):
    """Возврат книги."""

    if isbn not in library:
        raise ValueError("Книга не найдена")

    book = library[isbn]

    if book["available"]:
        raise ValueError("Книга уже находится в библиотеке")

    book["available"] = True

    save_library()
    logging.info(f"Возвращена книга: {book['title']}")

    return f"Книга '{book['title']}' успешно возвращена."


def get_statistics():
    """Статистика библиотеки."""

    total_books = len(library)

    available_books = sum(
        1 for book in library.values()
        if book["available"]
    )

    borrowed_books = total_books - available_books

    if total_books > 0:
        most_popular = max(
            library.values(),
            key=lambda x: x["times_borrowed"]
        )["title"]

        avg_year = round(
            mean(book["year"] for book in library.values()),
            2
        )
    else:
        most_popular = None
        avg_year = 0

    return {
        "total_books": total_books,
        "available_books": available_books,
        "borrowed_books": borrowed_books,
        "most_popular_book": most_popular,
        "average_year": avg_year
    }

def get_top_books(n=5):
    """Топ популярных книг."""

    books = sorted(
        library.items(),
        key=lambda item: item[1]["times_borrowed"],
        reverse=True
    )

    return [
        {"isbn": isbn, **book}
        for isbn, book in books[:n]
    ]


def get_books_by_decade(decade):
    """Книги десятилетия."""

    return [
        {"isbn": isbn, **book}
        for isbn, book in library.items()
        if decade <= book["year"] < decade + 10
    ]


def export_to_csv(filename="catalog.csv"):
    """Экспорт каталога в CSV."""

    with open(filename, "w", newline="", encoding="utf-8") as file:
        writer = csv.writer(file)

        writer.writerow([
            "ISBN",
            "Название",
            "Автор",
            "Год",
            "Доступна",
            "Количество выдач"
        ])

        for isbn, book in library.items():
            writer.writerow([
                isbn,
                book["title"],
                book["author"],
                book["year"],
                book["available"],
                book["times_borrowed"]
            ])

    logging.info("Экспорт каталога в CSV")
    print(f"Каталог экспортирован в {filename}")

def is_cancel(value):
    return value.lower() in ("q", "выход")


def print_books(books):
    if not books:
        print("Ничего не найдено.")
        return

    print("\nНайденные книги:")

    for i, book in enumerate(books, start=1):
        status = "Доступна" if book["available"] else "Выдана"

        print(
            f"{i}. ISBN: {book['isbn']} | "
            f"{book['title']} | "
            f"{book['author']} | "
            f"{book['year']} | "
            f"{status}"
        )

def menu():
    load_library()

    while True:
        print("\n=== Библиотечная система ===")
        print("1. Добавить книгу")
        print("2. Поиск книг")
        print("3. Выдать книгу")
        print("4. Вернуть книгу")
        print("5. Показать статистику")
        print("6. Выйти")

        choice = input(
            "\nВыберите действие (1-6): "
        ).strip()

        try:
            if not choice.isdigit():
                raise ValueError

            choice = int(choice)

            if choice < 1 or choice > 6:
                raise ValueError

        except ValueError:
            print("Некорректный ввод.")
            continue

        if choice == 1:
            print("\nДобавление новой книги:")

            isbn = input("ISBN: ").strip()
            if is_cancel(isbn):
                continue

            title = input("Название: ").strip()
            if is_cancel(title):
                continue

            author = input("Автор: ").strip()
            if is_cancel(author):
                continue

            year_input = input("Год: ").strip()
            if is_cancel(year_input):
                continue

            try:
                year = int(year_input)

                add_book(
                    isbn,
                    title,
                    author,
                    year
                )

                print("Книга успешно добавлена!")

            except Exception as e:
                print("Ошибка:", e)

        elif choice == 2:

            field = input(
                "\nИскать по (title/author/year): "
            ).strip().lower()

            if is_cancel(field):
                continue

            query = input(
                "Введите запрос: "
            ).strip()

            if is_cancel(query):
                continue

            try:
                books = search_books(query, field)
                print_books(books)

            except Exception as e:
                print("Ошибка:", e)

        elif choice == 3:

            isbn = input(
                "\nISBN книги: "
            ).strip()

            if is_cancel(isbn):
                continue

            try:
                print(borrow_book(isbn))

            except Exception as e:
                print("Ошибка:", e)

        elif choice == 4:

            isbn = input(
                "\nISBN книги: "
            ).strip()

            if is_cancel(isbn):
                continue

            try:
                print(return_book(isbn))

            except Exception as e:
                print("Ошибка:", e)

        elif choice == 5:

            stats = get_statistics()

            print("\nСтатистика:")
            print(
                f"Всего книг: "
                f"{stats['total_books']}"
            )

            print(
                f"Доступных: "
                f"{stats['available_books']}"
            )

            print(
                f"Выданных: "
                f"{stats['borrowed_books']}"
            )

            print(
                f"Самая популярная: "
                f"{stats['most_popular_book']}"
            )

            print(
                f"Средний год издания: "
                f"{stats['average_year']}"
            )

        elif choice == 6:
            print("До свидания!")
            break


if __name__ == "__main__":
    menu()