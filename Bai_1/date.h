#ifndef __DATE_H__
#define __DATE_H__

#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
    private:
        unsigned int day, month, year;

        int daysInMonth(int m, int y) const {
            static const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int daysInMonth = days[m];

            
            if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))) {               //leaf year
                daysInMonth = 29;
        }

        return daysInMonth;
    }
    public:
        Date(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {};
        Date(Date const &other)
        {
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;
        }

        Date operator = (Date const &other) 
        {
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;
            return *this;
        }

        friend istream& operator >> (istream& inp, Date& date)
        {
            inp >> date.day;
            inp.ignore(1, '/');
            inp >> date.month;
            inp.ignore(1, '/');
            inp >> date.year;
            return inp;
        }

        void setDate(unsigned int day, unsigned int month, unsigned int year)
        {
            this->day = day;
            this->month = month;
            this->year = year;
        }


        friend ostream& operator << (ostream& out, Date const &date)
        {
            out << setfill('0') << setw(2) << date.day << '/' << setw(2) << date.month << '/' <<setw(2) << date.year;
            return out;
        }

        bool operator == (Date const &other)
        {
            return (day == other.day && month == other.month && year == other.year);
        }

        Date operator + (unsigned int days)
        {
            Date result = *this; 
            result.day += days;

            while (result.day > daysInMonth(result.month, result.year)) {
                result.day -= daysInMonth(result.month, result.year);
                result.month++;

                if (result.month > 12) {
                    result.month = 1;
                    result.year++;
                }
            }
            return result;
        }

        unsigned int getDay() const
        {
            return day;
        }

        unsigned int getMonth() const
        {
            return month;
        }

        unsigned int getYear() const
        {
            return year;
        }
};

#endif