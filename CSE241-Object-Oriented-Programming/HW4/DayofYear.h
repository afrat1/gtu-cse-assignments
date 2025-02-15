#include <iostream>
#include <list>
#include <vector>
using namespace std;

#ifndef DAYOFYEAR
#define DAYOFYEAR

class DayofYearSet{
public:
    class DayofYear{
    public:
        DayofYear(int monthValue, int dayValue); //Initializes the month and day to arguments.
        DayofYear(int monthValue); //Initializes the date to the first of the given month.
        DayofYear(); //default constructor   
        int getMonthNumber(){return month;};
        int getDay(){return day;};
        bool testDate();
        ~DayofYear();
    private:
        int month;
        int day;
        
    };
    
    DayofYearSet(const list <DayofYear>& days);
    DayofYearSet(int a);//copy consturctor
    int size() const{ return _size;}
    void add(DayofYear &D);
    void remove(DayofYear& d);
    bool is_it_contains(DayofYear& d);
    DayofYear* arr_a;
    friend ostream& operator<<(ostream& os,const DayofYearSet& dt);
    DayofYearSet operator^(const DayofYearSet& set);
    DayofYearSet operator-(const DayofYearSet& set);   
    DayofYearSet operator+(const DayofYearSet& set);  
    DayofYearSet operator!();
    DayofYear operator[](int index) const;

private:
   DayofYear* arr_d;
   int _size;

};
   
    bool operator==(DayofYearSet::DayofYear& d1, DayofYearSet::DayofYear& d2);
    bool operator!=(DayofYearSet::DayofYear& d1, DayofYearSet::DayofYear& d2);

#endif