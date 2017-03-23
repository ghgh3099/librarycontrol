#include <iostream>

#include "Book.h"

// Create default user
void createBookDefault(Book bo[], int& bookSize) {
    Book bo1, bo2, bo3;
    bo1 = Book(1, "Lap Trinh Nang Cao", 10, "Hoang Minh Duong", "DHQGHN");
    bo2 = Book(2, "Bi Kip Luyen Rong", 20, "Ho Dac Phuong", "UET");
    bo3 = Book(3, "Ninja luyen code", 30, "Nguyen Ngoc Thai", "VNU");
    bo[0] = bo1;
    bo[1] = bo2;
    bo[2] = bo3;
    bookSize = 3;
}

// print a book
void printfBook(const Book& b) {
    cout << b.bookId << " | " << b.Title << " | " << b.NumOfCopies << " | " << b.NameAuthor << " | "<< b.PublishHouse << endl;
}


// print all book
void printfAllBook(const Book b[], int bookSize) {
    cout << "All Book" << endl;
    cout << "-----------------------------------------------------" << endl;
    for(int i = 0; i < bookSize; i++) {
        printfBook(b[i]);
    }
    cout << "-----------------------------------------------------" << endl;
}

// insert new book to array
void insertBook(Book newBook, int& bookSize, Book bo[]) {
    bo[bookSize++] = newBook;
}

void deleteBook(Book bo[], int &bookSize, string title) {
    int findIndex = -1;
    for(int i = 0; i < bookSize; i++) {
        if(bo[i].title == title) {
            findIndex = i;
        }
    }
    if(findIndex == -1) {
        cout << "Book not exist" << endl;
    } else {
        for(int i = findIndex; i < bookSize - 1; i++){
            bo[i] = bo[i+1];
        }
        bookSize--;
    }
}

void updateBook(Book bo[], const int &bookSize, string title, string newTitle) {
    for(int i = 0; i < bookSize; i++) {
        if(bo[i].title == title) {
            bo[i].title = newTitle;
            break;
        }
    }
}

int searchBook(Book bo[], const int &bookSize, string title) {
    for(int i = 0; i < bookSize; i++) {
        if(us[i].title == title) {
            return bo[i].bookId;
            break;
        }
    }
    return -1;
}

