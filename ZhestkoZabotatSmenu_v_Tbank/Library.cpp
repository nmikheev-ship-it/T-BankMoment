//
// Created by nikit on 20.03.2026.
//

#include "Library.h"
#include "Properties.h"
#include "Book.h"

Library::Library() {
    this->Library::books = {};
}

bool Library::titleCmp(Book a, Book b) {
    return a.getTitle() < b.getTitle();
}

bool Library::authorCmp(Book a, Book b) {
    return a.getAuthor() < b.getAuthor();
}

bool Library::genreCmp(Book a, Book b) {
    return a.getGenre() < b.getGenre();
}


void Library::addBook(Book book) {
    Properties properties = Properties();
    books[book] = properties;
}

void Library::removeBook(Book book) {
    books.erase(book);
}

void Library::changeFavouriteStatus(Book book) {
    if (books.find(book) == books.end()) return;
    books[book].changeFavourite();
}

void Library::changeReadStatus(Book book) {
    if (books.find(book) == books.end()) return;
    books[book].changeReadStatus();
}

std::vector<Book> Library::getBookList() {
    std::vector<Book> bookList;
    for (auto& [book, prop] : books) {
        bookList.emplace_back(book);
    }
    return bookList;
}

std::vector<Book> Library::getFavouriteBooks() {
    std::vector<Book> favouriteList;
    for (auto& [book, prop] : books) {
        if (prop.getIsFavourite()) favouriteList.emplace_back(book);
    }
    return favouriteList;
}

std::vector<Book> Library::getReadBooks() {
    std::vector<Book> readList;
    for (auto& [book, prop] : books) {
        if (prop.getIsRead()) readList.emplace_back(book);
    }
    return readList;
}

std::vector<Book> Library::sortListByTitle(std::vector<Book> b) {
    std::sort(b.begin(), b.end(), titleCmp);
    return b;
}

std::vector<Book> Library::sortListByAuthor(std::vector<Book> b) {
    std::sort(b.begin(), b.end(), authorCmp);
    return b;
}

std::vector<Book> Library::sortListByGenre(std::vector<Book> b) {
    std::sort(b.begin(), b.end(), genreCmp);
    return b;
}

std::vector<Book> Library::sortListByReadStatus(std::vector<Book> b) {
    std::sort(b.begin(), b.end(), [this](Book a, Book b) -> bool {
        return books[a].getIsRead() < books[b].getIsRead();
    });
    return b;
}

std::vector<Book> Library::findBooks(std::string key_words) {
    std::vector<Book> findBook;
    for (auto& pair : books) {
        Book book = pair.first;
        std::string s = book.getTitle() + " "
                      + book.getAuthor() + " "
                      + book.getGenre() + " "
                      + std::to_string(book.getYear());
        if (s.find(key_words) != s.npos) findBook.emplace_back(book);
    }
    return findBook;
}

std::map<Book, Properties, CMP> Library::getBooks() {
    return this->books;
}



