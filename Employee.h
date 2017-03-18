#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

#include "User.h"

using namespace std;

struct Employee {
    int id;
    string name;
    string address;
    string phoneNumber;
    string department;
    Date birthDay;
    string email;
    Gender gender;

    Employee() {}

    Employee(int id, string name, string address, string phoneNumber,
             string department, Date birthDay, string email, Gender gender) {
        this -> id = id;
        this -> name = name;
        this -> address = address;
        this -> phoneNumber = phoneNumber;
        this -> department = department;
        this -> birthDay = birthDay;
        this -> email = email;
        this -> gender = gender;
    }

};

void createEmployeeDefault(Employee e[], int &empSize);
void printEmployee(const Employee &e);
void printAllEmployee(const Employee e[], int empSize);


#endif // EMPLOYEE_H
