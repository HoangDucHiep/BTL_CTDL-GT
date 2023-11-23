#ifndef __STORE_GAME_LIST_H__
#define __STORE_GAME_LIST_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <iomanip>
#include <cstdlib>   //.exit()
#include <vector>
#include <functional>

#include "rented_game.h"

class RentedGameList
{
    private:
        vector<RentedGame> list;
        unsigned int noDisk;
        void writeToFile();
        void readFromFile();
    public:
        RentedGameList();
        ~RentedGameList();
        void addGame();
        void removeGame();
        void ShowList();
        void ShowGame();
        void SortbyName(bool ascending = true);

        void SortbyCode(bool ascending = true);

/* 
        RentedGame search(string Code)
        {
            SortbyCode();
        } */


};

RentedGameList::RentedGameList()
{
    readFromFile();
}

RentedGameList::~RentedGameList()
{
    writeToFile();
}

void RentedGameList::addGame()
{
    RentedGame newGame;
    newGame.getInfor();
    list.push_back(newGame);
    noDisk++;
}

void RentedGameList::ShowList()
{
    for(int i = 0; i < noDisk; i++)
    {
        list[i].showInfor();
        cout << "\n";
    }
}

void RentedGameList::writeToFile()
{
    ofstream outFile("./rented_list_test.txt");

    for(auto game : list)
    {
        outFile << (game.getName() + "\t");
        outFile << (game.getPublisher() + "\t");
        outFile << (game.getGenre() + "\t");
        outFile << (game.getCode() + "\t");
        Date tempDate = game.getReleaseDate();
        outFile << (to_string(tempDate.getDay()) + "/" + to_string(tempDate.getMonth()) + "/" + to_string(tempDate.getYear()) + "\t");
        tempDate = game.getRentDate();
        outFile << (to_string(tempDate.getDay()) + "/" + to_string(tempDate.getMonth()) + "/" + to_string(tempDate.getYear()) + "\t");
        tempDate = game.getExpiredDate();
        outFile << (to_string(tempDate.getDay()) + "/" + to_string(tempDate.getMonth()) + "/" + to_string(tempDate.getYear()) + "\t");
        outFile << game.getRentDays() << "\n";
    }
}

void RentedGameList::readFromFile()
{
    noDisk = 0;
    ifstream inFile("./rented_list_test.txt");
    string s;
    while(inFile)   
    {
        getline(inFile, s);
        if(!inFile)         //detect end of file
            break;
        
        stringstream sts(s);

        RentedGame newGame;

        string temp;
        getline(sts, temp, '\t');   //read from sts to temp, read until '\t'
        newGame.setName(temp);

        getline(sts, temp, '\t');   //read from sts to temp, read until '\t'
        newGame.setPublisher(temp);

        getline(sts, temp, '\t');   //read from sts to temp, read until '\t'
        newGame.setGenre(temp);

        getline(sts, temp, '\t');   //read from sts to temp, read until '\t'
        newGame.setCode(temp);

        unsigned int d, m, y;
        getline(sts, temp, '/');
        d = stoi(temp);
        getline(sts, temp, '/');
        m = stoi(temp);
        getline(sts, temp, '\t');
        y = stoi(temp);
        newGame.setReleaseDate(d, m, y);

        getline(sts, temp, '/');
        d = stoi(temp);
        getline(sts, temp, '/');
        m = stoi(temp);
        getline(sts, temp, '\t');
        y = stoi(temp);
        newGame.setRentDate(d, m, y);
        
        getline(sts, temp, '/');
        d = stoi(temp);
        getline(sts, temp, '/');
        m = stoi(temp);
        getline(sts, temp, '\t');
        y = stoi(temp);
        newGame.setExpiredDate(d, m, y);

        getline(sts, temp, '/');
        newGame.setRentDays(stoi(temp));

        list.push_back(newGame);
        noDisk++;
    }

    inFile.close();
}

void RentedGameList::ShowGame()
{
    cout << "\n" << list[0].getPrice();
}

/* void RentedGameList::SortbyName(bool ascending = true)
        {
            sort(list.begin(), list.end(), [ascending](const RentedGame& game1, const RentedGame& game2) {
                if (ascending) {
                    return game1.getName() < game2.getName();
                } else {
                    return game1.getName() > game2.getName();
                }
            });
        }

void RentedGameList::SortbyCode(bool ascending = true)
{
    sort(list.begin(), list.end(), [ascending](const RentedGame& game1, const RentedGame& game2) {
        if (ascending) {
            return game1.getCode() < game2.getCode();
        } else {
            return game1.getCode() > game2.getCode();
        }
    });
} */

#endif