#ifndef __DATE_H_INCLUDED__
#define __DATE_H_INCLUDED__

class Date {
public:
    Date(int year, int month, int day);

    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);

    int getYear();
    int getMonth();
    int getDay();

    void printDate();

    void readDateFromInput();
    void incrementDay();


private:
    int year;
    int month;
    int day;


};

#endif
