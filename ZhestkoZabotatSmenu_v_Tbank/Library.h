//
// Created by nikit on 20.03.2026.
//

#ifndef ZHESTKOZABOTATSMENU_V_TBANK_LIBRARY_H
#define ZHESTKOZABOTATSMENU_V_TBANK_LIBRARY_H


#include "Book.h"
#include "Properties.h"

struct CMP {
    bool operator()(Book a, Book b) const {
        return a.getYear() > b.getYear();
    }
};


class Library {
private:
    std::map<Book, Properties, CMP> books;
    static bool titleCmp(Book a, Book b);
    static bool authorCmp(Book a, Book b);
    static bool genreCmp(Book a, Book b);
public:


    Library();
    void addBook(Book book);
    void removeBook(Book book);
    void changeFavouriteStatus(Book book);
    void changeReadStatus(Book book);
    std::vector<Book> getBookList();
    std::vector<Book> getFavouriteBooks();
    std::vector<Book> getReadBooks();
    std::vector<Book> sortListByTitle(std::vector<Book> b);
    std::vector<Book> sortListByAuthor(std::vector<Book> b);
    std::vector<Book> sortListByGenre(std::vector<Book> b);
    std::vector<Book> sortListByReadStatus(std::vector<Book> b);
    std::vector<Book> findBooks(std::string key_words);
    std::map<Book, Properties, CMP> getBooks();
};


#endif //ZHESTKOZABOTATSMENU_V_TBANK_LIBRARY_H
