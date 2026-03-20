//
// Created by nikit on 20.03.2026.
//

#ifndef ZHESTKOZABOTATSMENU_V_TBANK_BOOK_H
#define ZHESTKOZABOTATSMENU_V_TBANK_BOOK_H
#include <bits/stdc++.h>


class Book {
private:
    std::string title;
    std::string author;
    std::string genre;
    int year;
    std::string description;
public:
    Book();
    Book(std::string title, std::string author, std::string genre, int year);
    Book(std::string title, std::string author, std::string genre, int year, std::string description);
    std::string getTitle();
    std::string getAuthor();
    std::string getGenre();
    int getYear();
    std::string getDescription();
};

inline std::ostream& operator<<(std::ostream& os, Book& book) {
    std::string descr = (book.getDescription() == "-" ? "У этой книги нет описания" : book.getDescription());
    return os << "Book's title: " << book.getTitle() << '\n'
              << "Book's author: " << book.getAuthor() << '\n'
              << "Book's genre: " << book.getGenre() << '\n'
              <<"Book's year: " << book.getYear() << '\n'
            << "Book's description: " << descr << '\n'
            << "________________________________________\n";
}


#endif //ZHESTKOZABOTATSMENU_V_TBANK_BOOK_H
