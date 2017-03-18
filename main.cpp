#include <iostream>

#include "User.h"
#include "Employee.h"

using namespace std;

int main(){

    int currentUserId = 0, currentEmpId = 0, currentUserSize = 0, currentEmpSize = 0;
    int currentSize = 0;
    // create array
    User us[100];
    Employee e[100];
    // create data default
    createUserDefault(us, currentUserSize);
    createEmployeeDefault(e, currentEmpSize);

    printfAllUser(us, currentUserSize);
    printAllEmployee(e, currentEmpSize);

    currentUserId  = currentUserSize;
    currentEmpId  = currentEmpSize;


    //User us1 = User(++currentUserId, "Thai", "thaihn4", "abc123", "ngocthaihn2@gmail.com",
    //                 Date(8, 3, 2017), MALE, "0123456789");
    //User us2 = User(++currentUserId, "Thai", "thaihn5", "abc123", "ngocthaihn2@gmail.com",
    //                 Date(8, 3, 2017), MALE, "0123456789");
    //User us3 = User(++currentUserId, "Thai", "thaihn6", "abc123", "ngocthaihn2@gmail.com",
     //                Date(8, 3, 2017), MALE, "0123456789");
    //insertUser(us1, currentSize, us);
    //insertUser(us2, currentSize, us);
    //insertUser(us3, currentSize, us);
    //printfAllUser(us, currentSize);
    //deleteUser(us, currentSize, "thaihn4");
    //(us, currentSize, "thaihn5", "Thai Ngoc Hoang");
    //cout << "after edit" << endl;
    //printfAllUser(us, currentSize);

    //int searchResult = searchUser(us, currentSize, "thaihn4");
    //cout << "search result : " << searchResult << endl;

    //cout << "current  size " << currentSize << "Current id = " << currentID << endl;

    return 0;
}
