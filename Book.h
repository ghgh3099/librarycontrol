#ifndef BOOK_H
#define BOOK_H

#include <iostream>

using namespace std;


struct Date {
    int day;
    int month;
    int year;

    // Constructor default
    Date() {
        this -> day = 17;
        this -> month = 3;
        this -> year = 1996;
    }

    Date(int day, int month, int year) {
        this -> day = day;
        this -> month = month;
        this -> year = year;
    }
};

struct Book{
    int bookId;
    string title;
    int NumOfCopies;
    string NameAuthor;
    string PublishHouse;

    Book() {}

    User(int id, string title, int NumOfCopies, string NameAuthor,
         string PublishHouse) {
             this -> bookIdid = bookId;
             this -> title = title;
             this -> NumOfCopies = NumOfCopies;
             this -> NameAuthor = NameAuthor;
             this -> PublishHouse = PublishHouse;
    }

};

void createBookDefault(Book bo[], int& bookSize);
void printfBook(const Book& b);
void printfAllBook(const Book bo[], int bookSize);
void insertBook(Book newBook, int& bookSize, Book bo[]);
void deleteBook(Book bo[], int &bookSize, string title);
void updateBook(Book bo[], const int &bookSize, string title, string newTitle);
int searchBook(Book bo[], const int &bookSize, string title);

#endif // BOOK_H

