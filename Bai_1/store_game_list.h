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

class GameList
{
    private:
        vector<StoreGame> list;
        unsigned int noDisk;
    public:
        GameList();
        ~GameList();
        void addGame();
        void removeGame();
        void ShowList();
        void ShowGame()
        {
            cout << "\n" << list[0].getPrice();
        }
        // Thêm hàm ghi dữ liệu vào file .DAT
        void writeToFile();

        // Thêm hàm đọc dữ liệu từ file .DAT
        void readFromFile();
};

GameList::GameList()
{
    noDisk = 0;
}

GameList::~GameList()
{

}

void GameList::addGame()
{
    StoreGame newGame;
    newGame.getInfor();
    list.push_back(newGame);
    noDisk++;
}

void GameList::ShowList()
{
    for(int i = 0; i < noDisk; i++)
    {
        list[i].showInfor();
        cout << "\n";
    }
}

void GameList::writeToFile()
{
    ofstream outFile("./store_game_list_out.txt");
    string data;


    for(auto game : list)
    {
        data = "";
        data += (game.getName() + "\t");
        data += (game.getPublisher() + "\t");
        data += (game.getGenre() + "\t");
        data += (game.getCode() + "\t");
        Date tempDate = game.getReleaseDate();
        data += (to_string(tempDate.getDay()) + "/" + to_string(tempDate.getMonth()) + "/" + to_string(tempDate.getYear()) + "\t");
        data += (to_string(game.getPrice()) + "\t");
        data += (to_string(game.getInStock()) + "\n");
        outFile << data;
    }
}

void GameList::readFromFile()
{
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
    }

    inFile.close();
    for(auto game : list)
    {
        game.showInfor();
    }
}



#endif