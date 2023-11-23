#ifndef __CUSTOMER_TYPE_H__
#define __CUSTOMER_TYPE_H__

#include <iostream>
#include <string>
#include <vector>
#include "rented_game_list.h"
using namespace std;


class customer
{
    private:
        string fullName;
        string phoneNo;
        string ID;      //so cccd
        string address;
        RentedGameList rentedList;


    public:
        customer()
        {
            fullName = "";
            phoneNo = "";
            ID = "";
            address = "";
        }

        customer(string name, string phone, string id, string addr) : rentedList()
        {
            fullName = name;
            phoneNo = phone;
            ID = id;
            address = addr;
        }

        void showInfo()
        {
            cout << "\nHo ten: " << fullName;
            cout << "\nSo dien thoai: " << phoneNo;
            cout << "\nSo CCCD: " << ID;
            cout << "\nDia chi: " << address;
            cout << "\nDanh sach cac game da thue: ";
            rentedList.ShowList();
        }


        void getInfor()
        {
            cout << "\nNhap ho ten: "; getline(cin, fullName);
            cout << "Nhap so dien thoai: "; getline(cin, phoneNo);
            cout << "Nhap CCCD: "; getline(cin, ID);
            cout << "Nhap dia chi: "; getline(cin, address);
        }

        void rentGame()
        {
            rentedList.addGame();
        }

        void  returnGame()
        {
            rentedList.removeGame();
        }   

};


#endif