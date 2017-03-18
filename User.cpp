#include <iostream>

#include "User.h"

// Create default user
void createUserDefault(User us[], int& userSize) {
    User us1, us2, us3;
    us1 = User(1, "Hoang Ngoc Thai", "thaihn1", "abc123", "thaik59uet@gmail.com",
                    Date(17, 03, 1996), MALE, "01699950125");
    us2 = User(2, "Hoang Ngoc Thai", "thaihn2", "abc123", "thaik59uet@gmail.com",
                    Date(17, 03, 1996), MALE, "01699950125");
    us3 = User(3, "Hoang Ngoc Thai", "thaihn3", "abc123", "thaik59uet@gmail.com",
                    Date(17, 03, 1996), MALE, "01699950125");
    us[0] = us1;
    us[1] = us2;
    us[2] = us3;
    userSize = 3;
}

// print a user
void printfUser(const User& u) {
    cout << u.id << " | " << u.name << " | " << u.username << " | " << u.email << " | "<< endl;
}


// print all user
void printfAllUser(const User u[], int userSize) {
    cout << "All User" << endl;
    cout << "-----------------------------------------------------" << endl;
    for(int i = 0; i < userSize; i++) {
        printfUser(u[i]);
    }
    cout << "-----------------------------------------------------" << endl;
}

// insert new user to array
void insertUser(User newUser, int& userSize, User us[]) {
    us[userSize++] = newUser;
}

void deleteUser(User us[], int &userSize, string username) {
    int findIndex = -1;
    for(int i = 0; i < userSize; i++) {
        if(us[i].username == username) {
            findIndex = i;
        }
    }
    if(findIndex == -1) {
        cout << "Account not exist" << endl;
    } else {
        for(int i = findIndex; i < userSize - 1; i++){
            us[i] = us[i+1];
        }
        userSize--;
    }
}

void updateUser(User us[], const int &userSize, string userName, string newName) {
    for(int i = 0; i < userSize; i++) {
        if(us[i].username == userName) {
            us[i].name = newName;
            break;
        }
    }
}

int searchUser(User us[], const int &userSize, string userName) {
    for(int i = 0; i < userSize; i++) {
        if(us[i].username == userName) {
            return us[i].id;
            break;
        }
    }
    return -1;
}






