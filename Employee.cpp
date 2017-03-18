#include <iostream>

#include "Employee.h"

void createEmployeeDefault(Employee e[], int &empSize) {
    Employee e1, e2, e3;
    e1 = Employee(1, "Nguyen Van A", "Cau Giay - Ha Noi", "0999999999", "Ba Vi", Date(24, 11, 1999), "gmail.com.vn", MALE);
    e2 = Employee(2, "Nguyen Van A", "Cau Giay - Ha Noi", "0999999999", "Ba Vi", Date(24, 11, 1999), "gmail.com.vn", MALE);
    e3 = Employee(3, "Nguyen Van A", "Cau Giay - Ha Noi", "0999999999", "Ba Vi", Date(24, 11, 1999), "gmail.com.vn", MALE);
    e[0] = e1;
    e[1] = e2;
    e[2] = e3;
    empSize = 3;
}

void printEmployee(const Employee &e) {
    cout << e.id << " | " << e.name << " | " << e.email << " | " << endl;
}

void printEmployeeAllInfor(const Employee &e) {
    cout << "Id : " << e.id
    << "\nName : " << e.name
    << "\nAddress : " << e.address
    << "\nPhone : " << e.phoneNumber
    << "\nDepartment : " << e.department
    << "\nBirthday : " << e.birthDay.day << "-" << e.birthDay.month << "-" << e.birthDay.year
    << "\nEmail : " << e.email
    << "\nGender : " << e.gender;
    cout << "\n";
}

void printAllEmployee(const Employee e[], int empSize) {
    cout << "All Employee" << endl;
    cout << "-----------------------------------------------------" << endl;
    for(int i = 0; i < empSize; i++) {
        printEmployee(e[i]);
    }
    cout << "-----------------------------------------------------" << endl;
}

/*
Insert new employee
Input : an employee
Output :
*/
void insertEmployee(Employee newEmployee, int& empSize, Employee e[]) {
    e[empSize++] = newEmployee;
}

/*
Delete employee
Input : Employee id
Output : status delete
*/
int deleteEmployee(Employee e[], int &empSize, int idEmp) {
    int findIndex = -1;
    for(int i = 0; i < empSize; i++) {
        if(e[i].id == idEmp) {
            findIndex = i;
        }
    }
    if(findIndex == -1) {
        return 0;
    } else {
        for(int i = findIndex; i < empSize - 1; i++){
            e[i] = e[i+1];
        }
        empSize--;
        return 1;
    }
}

void updateUser(Employee e[], const int &empSize, int id, string newName) {
    for(int i = 0; i < empSize; i++) {
        if(e[i].id == id) {
            e[i].name = newName;
            break;
        }
    }
}

/*
Search employee by employee id
Input : id of employee
Output : position of employee, not exist will return -1
*/
int searchEmployee(Employee e[], const int &empSize, int id) {
    int findIndex = -1;
    for(int i = 0; i < empSize; i++) {
        if(e[i].id = id) {
            findIndex = i;
            break;
        }
    }
    return findIndex;
}




