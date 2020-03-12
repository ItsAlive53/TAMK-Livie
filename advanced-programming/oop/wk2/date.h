#pragma once

class Date {
public:
    Date();
    Date(int year);
    Date(int year, int month);
    Date(int year, int month, int day);

    ~Date();

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

    void init(int year, int month, int day);


};
