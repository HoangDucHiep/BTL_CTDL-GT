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

#include "store_game.h"

class StoreGameList
{
    private:
        vector<StoreGame> list;
        unsigned int noDisk;
        void writeToFile();
        void readFromFile();
    public:
        StoreGameList();
        ~StoreGameList();
        void addGame();
        void removeGame();
        void ShowList();
        void ShowGame();
        void SortbyName(bool ascending = true);

        void SortbyCode(bool ascending = true);

/* 
        StoreGame search(string Code)
        {
            SortbyCode();
        } */


};

StoreGameList::StoreGameList()
{
    readFromFile();
}

StoreGameList::~StoreGameList()
{
    writeToFile();
}

void StoreGameList::addGame()
{
    StoreGame newGame;
    newGame.getInfor();
    list.push_back(newGame);
    noDisk++;
}

void StoreGameList::ShowList()
{
    for(int i = 0; i < noDisk; i++)
    {
        list[i].showInfor();
        cout << "\n";
    }
}

void StoreGameList::writeToFile()
{
    ofstream outFile("./store_game_list.txt");

    for(auto game : list)
    {
        outFile << (game.getName() + "\t");
        outFile << (game.getPublisher() + "\t");
        outFile << (game.getGenre() + "\t");
        outFile << (game.getCode() + "\t");
        Date tempDate = game.getReleaseDate();
        outFile << (to_string(tempDate.getDay()) + "/" + to_string(tempDate.getMonth()) + "/" + to_string(tempDate.getYear()) + "\t");
        outFile << (to_string(game.getPrice()) + "\t");
        outFile << (to_string(game.getInStock()) + "\n");
    }
}

void StoreGameList::readFromFile()
{
    noDisk = 0;
    ifstream inFile("./store_game_list.txt");
    string s;
    while(inFile)   
    {
        getline(inFile, s);
        if(!inFile)         //detect end of file
            break;
        
        stringstream sts(s);

        StoreGame newGame;

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

        getline(sts, temp, '\t');   //read from sts to temp, read until '\t'
        newGame.setPrice(stoi(temp));

        getline(sts, temp, '\t');   //read from sts to temp, read until '\t'
        newGame.setInstock(stoi(temp));

        list.push_back(newGame);
        noDisk++;
    }

    inFile.close();
}

void StoreGameList::ShowGame()
{
    cout << "\n" << list[0].getPrice();
}

void StoreGameList::SortbyName(bool ascending = true)
        {
            sort(list.begin(), list.end(), [ascending](const StoreGame& game1, const StoreGame& game2) {
                if (ascending) {
                    return game1.getName() < game2.getName();
                } else {
                    return game1.getName() > game2.getName();
                }
            });
        }

void StoreGameList::SortbyCode(bool ascending = true)
{
    sort(list.begin(), list.end(), [ascending](const StoreGame& game1, const StoreGame& game2) {
        if (ascending) {
            return game1.getCode() < game2.getCode();
        } else {
            return game1.getCode() > game2.getCode();
        }
    });
}

#endif