#ifndef __GAME_DISK_TYPE_H__
#define __GAME_DISK_TYPE_H__

#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <cstdlib>   //.exit()

#include "date.h"

using namespace std;

class GameDisk
{
    private:
        string name;            //game's name
        string code;            //game's unique code
        string publisher;       //game's publisher
        string genre;           //game's genre
        Date releaseDate;       //game's release date
        unsigned int price;     //game's price  
    
    public:
        GameDisk(string name, string publisher, string genre, string code,  Date releaseDate , unsigned int price);
            //constructor
        virtual void getInfor();
            //Update game's information
        virtual void showInfor() const;
            //Show game's information 
        string getName() const;
            //return game's name
        string getPublisher() const;
            //game's publisher
        string getGenre() const;
            //game's genre 
        unsigned int getPrice() const;
            //return number of items in stock
        string getCode() const;
            //return game's code
        Date getReleaseDate() const;
            //return game's release date

        void setName(string n);
            //set game's name
        void setPublisher(string p);
            //set game's publisher
        void setGenre(string g);
            //set game's genre
        void setPrice(unsigned int p);
            //set game's price
        void setCode(string c);
            //set game's code
        void setReleaseDate(unsigned int d, unsigned int m, unsigned int y);
            //set game's release date
            
        //bool operator == (const GameDisk& other);
};




GameDisk::GameDisk(string name = "N/A", string publisher = "N/A", string genre = "N/A", string code = "N/A", Date releaseDate = {1, 1, 1}, unsigned int price = 0)
{
    this->name = name;
    this->publisher = publisher;
    this->genre = genre;
    this->code = code;
    this->releaseDate = releaseDate;
    this->price = price;
}

void GameDisk::getInfor()
{
    cout << "\nNhap ten game: ";
    getline(cin, name);
    cout << "Nhap ma san pham: ";
    getline(cin, code);
    cout << "Nhap nha phat hanh: ";
    getline(cin, publisher);
    cout << "Nhap the loai: ";
    getline(cin, genre);
    cout << "Nhap ngay phat hanh (dd/mm/yyyy): ";
    cin >> releaseDate;
    cout << "Nhap gia: ";
    cin >> price;
    cin.ignore(10, '\n');
}

void GameDisk::showInfor() const
{
    cout << "\nTen game: " << name;
    cout << "\nChe do choi: " << code;
    cout << "\nNha phat hanh: " << publisher;
    cout << "\nThe loai: " << genre;
    cout << "\nNgay phat hanh (dd/mm/yyyy): " << releaseDate;
    cout << "\nGia: " << price;
}

unsigned int GameDisk::getPrice() const
{
    return price;
}

string GameDisk::getName() const
{
    return name;
}

string GameDisk::getPublisher() const
{
    return publisher;
}      
string GameDisk::getGenre() const
{
    return genre;
}         
string GameDisk::getCode() const
{
    return code;
}         

Date GameDisk::getReleaseDate() const
{
    return releaseDate;
}

void GameDisk::setName(string n)
{
    name = n;
};

void GameDisk::setPublisher(string p)
{
    publisher = p;
}

void GameDisk::setPublisher(string p)
{
    publisher = p;
}

void GameDisk::setGenre(string g)
{
    genre = g;
}

void GameDisk::setPrice(unsigned int p)
{
    price = p;
}

void GameDisk::setCode(string c)
{
    code = c;
}

void GameDisk::setReleaseDate(unsigned int d, unsigned int m, unsigned int y)
{
    releaseDate.setDate(d, m, y);
}

/* bool GameDisk::operator == (const GameDisk& other)
        {
    return (code == other.code);
} */

#endif