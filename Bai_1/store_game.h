#ifndef __STORE_GAME_H__
#define __STORE_GAME_H__

#include "game_type.h"

class StoreGame : public GameDisk
{
    private:
        unsigned int inStock;
    
    public:
        StoreGame(string name = "N/A", string publisher = "N/A", string genre = "N/A", string code = "N/A", Date releaseDate = {1, 1, 1}, unsigned int price = 0, unsigned int inStock = 0) : GameDisk(name, publisher, genre, code, releaseDate, price)
        {
            this->inStock = inStock;
        }
        void getInfor()
        {
            GameDisk::getInfor();
            cout << "Nhap so luong trong kho: ";
            cin >> inStock;
            cin.ignore(10, '\n');
        }
            //Update game's information
        void showInfor() const
        {
            GameDisk::showInfor();
            cout << "\nSo luong trong kho: " << inStock << "\n";
        }
            //Show game's information 

        unsigned int getInStock() const
        {
            return inStock;
        }
            //return number of items in stock

        void addStock(unsigned int quantity)
        {
            inStock += quantity;
        }
        void removeStock(unsigned int quantity)
        {
            inStock -= quantity;
        }

        void setInstock(unsigned int quantity)
        {
            inStock = quantity;
        }
};

#endif