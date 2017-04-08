#include "Borrow.h"
#include "Employee.h"
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

Borrow::Borrow()
{
    //constructor
}

Borrow::Borrow(int B_ID,int E_ID,Date start,Date due, Date real, Status B_Stt)
{
    this->BorrowID = B_ID;
    this->EmployeeID = E_ID;
    this->startDate = start;
    this->dueDate = due;
    this->realDate = real;
    this->BorrowStatus = B_Stt;
}

void Borrow::printStatus()
{
    cout<<(char)179<<setw(14);
    if(this->BorrowStatus == DA_TRA) cout << "DA TRA";
    if(this->BorrowStatus == CHUA_TRA) cout << "CHUA TRA";
    if(this->BorrowStatus == TRA_QUA_HAN) cout << "TRA QUA HAN";
    if(this->BorrowStatus == CHUA_MUON) cout << "CHUA MUON";
}

BorrowManager::BorrowManager()
{
    //ctor
}

BorrowManager::~BorrowManager()
{
    //dtor
}

void BorrowManager::ChucNang(Borrow br[],int& size,const Employee emp[],const int& size_emp)
{
    std::cout << "\n\n\t\tNHAP CHUC NANG BAN MUON SU DUNG:\n";
    std::cout << "\t\t浜様様様様様様様様様様様様様融\n";
    std::cout << "\t\t"<<"^"<<"1. Add Borrow Card          ^\n";
    std::cout << "\t\t"<<"^"<<"2. Print All Borrow Card    ^\n";
    std::cout << "\t\t"<<"^"<<"3. Delete Borrow Card by ID ^\n";
    std::cout << "\t\t"<<"^"<<"4. Find Borrow Card by ID   ^\n";
    std::cout << "\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

    switch(getch())
    {
    case '1':
    {
        this->addA_BorrowCard(size,br,emp,size_emp);
        break;
    }
    case '2':
    {
        this->printAllBorrowCard(br,size);
        break;
    }
    case '3':
    {
        std::cout <<"Nhap vao ID muon xoa: ";
        int ID;
        std::cin >> ID;
        this->deleteA_BorrowCard(br,size,ID);
        break;
    }
    case '4':
    {
        std::cout <<"Nhap vao ID muon tim: ";
        int ID;
        std::cin >> ID;
        this->findBorrowCard(br,size,ID);
    }
    }
}

void BorrowManager::addA_BorrowCard(int& size,Borrow br[],const Employee emp[],const int &size_emp)
{
    Borrow br_;
    cout<<"------------------Nhap Thong Tin Muon Sach--------------------\n";
    br_.BorrowID = this->GetID(br,size);
    bool hasEmp = false;
    do{
    cout<<"Employee ID      : ";
    cin>>br_.EmployeeID;
    for(int i=0; i<size_emp ; i++)
    {
        if(emp[i].EmployeeID == br_.EmployeeID)
            hasEmp = true;
    }
    if(!hasEmp) cout<<"Can't find this Employee. Try against\n";
    }while(!hasEmp);

    br_.startDate=Date(1,2,1990);
    br_.dueDate=Date(1,2,1990);
    br_.realDate=Date(1,1,1990);
    this->UpdateBorrowCard(br_);
    this->insertA_BorrowCard(br,size,br_);
    cout<<"Add Borrow Card Successfully\n";
}

void BorrowManager::insertA_BorrowCard(Borrow br[],int& size, Borrow br_)
{
    br[size++]=br_;
}

void BorrowManager::deleteA_BorrowCard(Borrow br[],int& size,int Br_ID)
{
    int findIndex = -1;
    for(int i=0 ; i<size ; i++)
    {
        if(br[i].BorrowID == Br_ID)
            findIndex = i;
    }
    if(findIndex == -1)
        std::cout <<"Khong tim thay de xoa!"<<std::endl;
    else
    {
        for(int i=findIndex ; i<size ; i++)
        {
            br[i]=br[i+1];
        }
        std::cout<<"DELETE Complete!\n";
    }
    size--;
}

void BorrowManager::printBorrowCard(Borrow br)
{
//    cout<<"---------------------------\n";
//    cout<<"Borrow ID        : "<<br.BorrowID<<endl;
//    cout<<"Employee ID      : "<<br.EmployeeID<<endl;
//    cout<<"Start Date       : ";
//    br.startDate.printDate();
//    cout<<"Due Date         : ";
//    br.dueDate.printDate();
//    cout<<"Real Date        : ";
//    br.realDate.printDate();
//    cout<<"Borrow Status    : ";
//    br.printStatus();

    cout<<std::left<<(char)186<<setw(4);
    cout<<br.BorrowID<<(char)179<<setw(5);
    cout<<br.EmployeeID;
    br.startDate.printDate();
    br.dueDate.printDate();
    br.realDate.printDate();
    br.printStatus();
    cout<<(char)186<<endl;
}

void BorrowManager::printAllBorrowCard(const Borrow br[],const int size)
{
    cout<<"THONG TIN MUON SACH\n";
    if(size == 0)
        cout<<"Khong co phieu muon nao!\n";
    else
    {
        //border tren
    for(int j=0; j<63 ; j++)
    {
        if(j==0 )
            std::cout<<(char)201;
        else if(j==62)
            std::cout<<(char)187;
        else
            std::cout<<(char)205;
    }
    std::cout<<"\n";

        cout<<std::left<<(char)186<<setw(4);
        cout<<"ID"<<(char)179;
        cout<<setw(5)<<"E_ID"<<(char)179;
        cout<<setw(11)<<"StartDate"<<(char)179<<setw(11)<<"DueDate"<<(char)179<<setw(11)<<"RealDate"<<(char)179;
        cout<<setw(14)<<"BorrowStatus"<<(char)186<<std::endl;

        //border giua
        for(int j=0; j<63 ; j++)
        {
            if(j==0 )
                std::cout<<(char)186;
            else if(j==62)
                std::cout<<(char)186;
            else
                std::cout<<(char)205;
        }
        std::cout<<"\n";

        for(int i=0; i<size ; i++)
        {
            printBorrowCard(br[i]);
        }

        //border duoi
    for(int j=0; j<63 ; j++)
    {
        if(j==0 )
            std::cout<<(char)200;
        else if(j==62)
            std::cout<<(char)188;
        else
            std::cout<<(char)205;
    }
    }
}

void BorrowManager::findBorrowCard(const Borrow br[],int size,int ID)
{
    bool finded = false;
    for(int i=0; i<size ; i++)
    {
        if(br[i].BorrowID == ID)
        {
            cout<<std::left<<setw(5);
            cout<<"ID";
            cout<<setw(12)<<"StartDate"<<setw(12)<<"DueDate"<<setw(12)<<"RealDate";
            cout<<setw(15)<<"BorrowStatus"<<std::endl;

            printBorrowCard(br[i]);
            finded = true;
        }
    }
    if(!finded) std::cout << "Khong tim thay!" <<std::endl;
}

int BorrowManager::GetID(Borrow br[],int size)
{
    srand(time(0));
    bool Exist = false;
    int newID ;
    int size_=size+1;
    do
    {
        Exist = false;
        newID = rand()%size_;
        for(int i=0 ; i<size ; i++)
        {
            if(br[i].BorrowID == newID)
                Exist = true;
        }
    }
    while(Exist);

    return newID;
}

void BorrowManager::UpdateBorrowCard(Borrow& br_)
{
    switch(br_.realDate.SosanhDate(br_.realDate,br_.dueDate))
    {
    case 1:
        br_.BorrowStatus = TRA_QUA_HAN;
        break;
    case -1:
        if(br_.realDate.SosanhDate(br_.startDate,br_.realDate) == 1)
            br_.BorrowStatus = CHUA_MUON;
        else br_.BorrowStatus = CHUA_TRA;
        break;
    case 0:
        br_.BorrowStatus = DA_TRA;
        break;
    }
}
