#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()

#include "Library.h"

void onEnable(Library& library) {
    ifstream in("BooksMoment.txt");
    string s;
    while (getline(in, s)) {
        stringstream ss(s);
        vector<string> params;
        string x;
        while (ss >> x) {
            params.push_back(x);
        }
        Book book(params[0], params[1], params[2], stoi(params[3]), params[4]);
        Properties prop(stoi(params[5]), stoi(params[6]));
        library.addBook(book);
        if (prop.getIsFavourite()) library.changeFavouriteStatus(book);
        if (prop.getIsRead()) library.changeReadStatus(book);
    }
    in.close();
}

void onDisable(Library& library) {
    ofstream out("BooksMoment.txt");
    if (!out.is_open()) {
        cerr << "Error: Could not open file for writing\n";
        return;
    }

    map<Book, Properties, CMP> els = library.getBooks();
    for (auto& el : els) {
        Book book = el.first;
        out << book.getTitle() << ' '
            << book.getAuthor() << ' '
            << book.getGenre() << ' '
            << book.getYear() << ' '
            << book.getDescription() << ' ';

        Properties prop = el.second;
        out << (prop.getIsFavourite() ? 1 : 0) << ' '
            << (prop.getIsRead() ? 1 : 0) << '\n';
    }
    out.close();
}

Book getBook() {
    string title, author, genre;
    cout << "Choose title for your book\n";
    cin >> title;
    cout << "Write the author\n";
    cin >> author;
    cout << "Write the genre\n";
    cin >> genre;
    int year;
    cout << "Write the year\n";
    cin >> year;
    string descr;
    cout << "Write description(in other case whrite '-')\n";
    cin >> descr;
    if (descr == "-") descr = "-";
    Book book(title, author, genre, year, descr);
    return book;
}

void printSort(Library& library, vector<Book> books) {
    cout << "If you want to sort list print sort\n"
            "another case write something else\n";
    string srt;
    cin >> srt;
    if (srt == "sort") {
        cout << "1. Sort by title\n";
        cout << "2. Sort by author\n";
        cout << "3. Sort by genre\n";
        cout << "4. Sort by year(default)\n";
        cout << "5. Sort by read status\n";
        int sorting_operation;
        cin >> sorting_operation;

        switch (sorting_operation) {
            case 1: {
                vector<Book> sortBooks = library.sortListByTitle(books);
                for (auto& book : sortBooks) {
                    cout << book;
                }
                break;
            }
            case 2: {
                vector<Book> sortBooks = library.sortListByTitle(books);
                for (auto& book : sortBooks) {
                    cout << book;
                }
                break;
            }
            case 3: {
                vector<Book> sortBooks = library.sortListByGenre(books);
                for (auto& book : sortBooks) {
                    cout << book;
                }
                break;
            }
            case 4: {
                for (auto& book : books) {
                    cout << book;
                }
                break;
            }
            case 5: {

                vector<Book> sortBooks = library.sortListByReadStatus(books);
                for (auto& book : sortBooks) {
                    cout << book;
                }
                break;
            }
            default: {
                cout << "Invalid operation\n";
                cout << "Sort by default(operation 4)\n";
                for (auto& book : books) {
                    cout << book;
                }
                break;
            }
        }

    } else {
        for (auto& book : books) {
            cout << book;
        }
    }
}

int main() {
    Library library;
    onEnable(library);
    cout << "Welcome to the library\n";
    cout << "We provide some operations:\n";
    cout << "1. Add book in the library\n";
    cout << "2. Remove book from the library\n";
    cout << "3. Show list of books\n";
    cout << "4. Add to favourites\n";
    cout << "5. Change read status book(read/not read)\n";
    cout << "6. Search book by key words\n";
    cout << "7. Show favourites\n";
    cout << "8. To stop library operation\n";
    string op;
    while (true) {
        cout << "Choose operation\n";
        int operation;
        cin >> operation;
        switch (operation) {
            case 1: {
                cout << "You choose 1st operation\n";
                cout << "if you made mistake and want back print '<-'\n";
                cout << "in other case write something else\n";
                cin >> op;
                if (op == "<-") break;
                Book book = getBook();
                library.addBook(book);
                break;
            }
            case 2: {
                cout << "You choose 2nd operation\n";
                cout << "if you made mistake and want back print '<-'\n";
                cout << "in other case write something else\n";
                cin >> op;
                if (op == "<-") break;
                Book book = getBook();
                library.removeBook(book);
                break;
            }
            case 3: {
                cout << "You choose 3rd operation\n";
                cout << "if you made mistake and want back print '<-'\n";
                cout << "in other case write something else\n";
                cin >> op;
                if (op == "<-") break;
                printSort(library, library.getBookList());
                break;
            }
            case 4: {
                cout << "You choose 4th operation\n";
                cout << "if you made mistake and want back print '<-'\n";
                cout << "in other case write something else\n";
                cin >> op;
                if (op == "<-") break;
                Book book = getBook();
                library.changeFavouriteStatus(book);
                break;
            }
            case 5: {
                cout << "You choose 5th operation\n";
                cout << "if you made mistake and want back print '<-'\n";
                cout << "in other case write something else\n";
                cin >> op;
                if (op == "<-") break;
                Book book = getBook();
                library.changeReadStatus(book);
                break;
            }
            case 6: {
                cout << "You choose 6th operation\n";
                cout << "if you made mistake and want back print '<-'\n";
                cout << "in other case write something else\n";
                cin >> op;
                if (op == "<-") break;
                string key_word;
                cout << "Write key word to search books\n";
                cin >> key_word;
                vector<Book> foundBooks = library.findBooks(key_word);
                for (auto& book : foundBooks) {
                    cout << book;
                }
                break;
            }
            case 7: {
                cout << "You choose 7th operation\n";
                cout << "if you made mistake and want back print '<-'\n";
                cout << "in other case write something else\n";
                cin >> op;
                if (op == "<-") break;
                printSort(library, library.getFavouriteBooks());
                break;
            }
            case 8: {
                cout << "Bye bye\n";
                onDisable(library);
                return 0;
            }
            default: {
                cout << "You choose invalid operation\n";
            }
        }
    }
}