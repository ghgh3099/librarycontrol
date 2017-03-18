
#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

enum Gender{
    MALE = 1,
    FEMALE = 2
};

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

struct User{
    int id;
    string name;
    string username;
    string password;
    string email;
    Date birthDate;
    Gender gender;
    string phone;

    User() {}

    User(int id, string name, string username, string password,
         string email, Date birthDay, Gender gender, string phone) {
             this -> id = id;
             this -> name = name;
             this -> username = username;
             this -> password = password;
             this -> email = email;
             this -> birthDate = birthDay;
             this -> gender = gender;
             this -> phone = phone;
    }

};

void createUserDefault(User us[], int& userSize);
void printfUser(const User& u);
void printfAllUser(const User u[], int userSize);
void insertUser(User newUser, int& userSize, User us[]);
void deleteUser(User us[], int &userSize, string username);
void updateUser(User us[], const int &userSize, string userName, string newName);
int searchUser(User us[], const int &userSize, string userName);

#endif // USER_H
