//
// Created by nikit on 20.03.2026.
//

#include "Book.h"

Book::Book() {}

Book::Book(std::string title, std::string author, std::string genre, int year) {
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->year = year;
    this->description = "";
}

Book::Book(std::string title, std::string author, std::string genre, int year, std::string description) {
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->year = year;
    this->description = description;
}

std::string Book::getTitle() {
    return this->title;
}

std::string Book::getAuthor() {
    return this->author;
}

std::string Book::getGenre() {
    return this->genre;
}

int Book::getYear() {
    return this->year;
}

std::string Book::getDescription() {
    return this->description;
}

