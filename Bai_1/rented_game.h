#ifndef __RENTED_GAME_H__
#define __RENTED_GAME_H__

#include "game_type.h"

class RentedGame : public GameDisk
{
    private:
        Date rentDate;
        Date expiredDate;
        unsigned int rentDays;
    public:
        RentedGame(string name = "N/A", string publisher = "N/A", string genre = "N/A", string code = "N/A", Date releaseDate = {1, 1, 1}, unsigned int price = 0, Date start = {1, 1, 1}, Date end = {1, 1, 1}, unsigned int rentDays = 0) : GameDisk(name, publisher, genre, code, releaseDate, price)
        {
            rentDate = start;
            expiredDate = end;
            this->rentDays = rentDays;
        }
        void getInfor()
        {
            GameDisk::getInfor();
            cout << "Nhap ngay bat dau thue: ";
            cin >> rentDate;
            cout << "Nhap so ngay thue: ";
            cin >> rentDays;
            expiredDate = rentDate + rentDays;
            cin.ignore(10, '\n');
        }
            //Update game's information
        void showInfor() const
        {
            GameDisk::showInfor();
            cout << "\nNgay bat dau thue: " << rentDate;
            cout << "\nNgay het han: " << expiredDate << "\n";
        }
            //Show game's information 

        Date getRentDate()
        {
            return rentDate;
        }
        Date getExpiredDate()
        {
            return expiredDate;
        }
        Date getRentDays()
        {
            return rentDays;
        }

        void setRentDate(unsigned int d, unsigned int m, unsigned int y)
        {
            rentDate.setDate(d, m, y);
        }

        void setExpiredDate(unsigned int d, unsigned int m, unsigned int y)
        {
            rentDate.setDate(d, m, y);
        }

        void setRentDays(unsigned int d)
        {
            rentDays = d;
        }

};

#endif