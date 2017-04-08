#ifndef BORROW_H
#define BORROW_H
#include "User.h"
#include "Employee.h"

enum Status
{

    CHUA_TRA = 1, DA_TRA, TRA_QUA_HAN, CHUA_MUON
};

struct Borrow
{
    int BorrowID,EmployeeID;
    Date startDate,dueDate,realDate;
    Status BorrowStatus;
    Borrow();
    Borrow(int,int,Date,Date,Date,Status);
    void printStatus();
};

class BorrowManager
{
        public:
        BorrowManager();
        virtual ~BorrowManager();
        void ChucNang(Borrow br[],int& size,const Employee emp[],const int& size_emp);
        void addA_BorrowCard(int&,Borrow br[],const Employee emp[],const int &size_emp);
        void insertA_BorrowCard(Borrow br[],int& size, Borrow br_);
        void deleteA_BorrowCard(Borrow br[],int& size,int Br_ID);
        void printBorrowCard(Borrow br);
        void printAllBorrowCard(const Borrow br[],const int size);
        void findBorrowCard(const Borrow br[],int size,int ID);
        int GetID(Borrow br[],int size);
        void UpdateBorrowCard(Borrow& br_);
};


#endif // BORROW_H
