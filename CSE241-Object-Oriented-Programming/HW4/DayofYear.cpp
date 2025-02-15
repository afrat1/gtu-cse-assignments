#include "DayofYear.h"
#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
using namespace std;

DayofYearSet::DayofYearSet(const list <DayofYear>& days){
    _size = days.size();
     arr_d = new DayofYear[size()];
 
    int a = 0;
    for(auto b = days.begin(); a< size() && b!=days.end() ; ++a, ++b){ 
        arr_d[a] = *b;
    }
}

DayofYearSet::DayofYearSet(int a){
    for(auto i = 0;i<_size;i++){
        arr_a[i] = arr_d[i];
    }
}

ostream& operator<<(ostream& os,const DayofYearSet& set){
    for(auto i = 0; i < set.size() ; i++){
        os << "Month: " << set.arr_d[i].getMonthNumber() << " Day: " << set.arr_d[i].getDay() << endl;
    }
    return os;
}

bool operator==(DayofYearSet::DayofYear& d1, DayofYearSet::DayofYear& d2){
    int flag = 0;
    if((d1.getDay() == d2.getDay()) && (d1.getMonthNumber() == d2.getMonthNumber())){
        flag = 1;
    }
    if(flag)
        return true;
    else
        return false;
}

bool operator!=(DayofYearSet::DayofYear& d1, DayofYearSet::DayofYear& d2){
    int flag = 0;
    if((d1.getDay() == d2.getDay()) && (d1.getMonthNumber() == d2.getMonthNumber())){
        flag = 1;
    }
    if(flag)
        return false;
    else
        return true;
}

void DayofYearSet::add(DayofYear &D){ //to add an element to set
    int i,j;
    DayofYear *tmp;
    tmp=new DayofYear [_size+1];

    for(i=0;i<_size;i++){
        tmp[i]=arr_d[i];
    }

    tmp[_size] = D;
    _size++;

    delete[]arr_d;

    arr_d = tmp; 

    for(int i=0;i<_size;i++){
        cout << "Month: "<< arr_d[i].getMonthNumber() << " Day: " << arr_d[i].getDay() << endl;
    }
    cout << endl;
}

DayofYearSet DayofYearSet::operator^(const DayofYearSet& set){ //it returns intersect set
    list <DayofYearSet::DayofYear> my_list;

    for(auto i = 0;i<size();i++){
        for(auto j =0;j<set.size();j++){
            if(arr_d[i] == set.arr_d[j]){
                my_list.push_back(arr_d[i]);  
            }      
        }
    }

    DayofYearSet intersect(my_list);
    return intersect;
}

DayofYearSet DayofYearSet::operator-(const DayofYearSet& set){ //it finds the difference
    list <DayofYearSet::DayofYear> my_list;
    int flag = 1;
    DayofYearSet intersection = *this ^ set; //a kesişim b bulundu
    for(auto i = 0; i < size(); i++){
        flag = 1;
        for(auto j = 0; j < intersection.size() && flag; j++){
            if(arr_d[i] == intersection.arr_d[j]){
                flag =0;
            }
        }           
        if (flag)
        my_list.push_back(arr_d[i]);
        
    }

    DayofYearSet difference(my_list);
    return difference; 
}

DayofYearSet DayofYearSet::operator+(const DayofYearSet& set){ //it returns union set
    list <DayofYearSet::DayofYear> my_list;
    DayofYearSet difference = *this - set;

    for(auto i = 0; i < difference.size(); i++){
            my_list.push_back(difference.arr_d[i]);
    }
    for(auto i = 0; i < set.size(); i++){
            my_list.push_back(set.arr_d[i]);
    }


    DayofYearSet add(my_list);
    return add; 
}

DayofYearSet DayofYearSet::operator!(){ //returns the complement set
    list <DayofYearSet::DayofYear> my_list;
    
    for (int m = 1; m <= 12; m++){
        for (int d = 1; d <= 31; d++){
            DayofYear day(m, d);
            if (day.testDate() && !(is_it_contains(day))) {
                my_list.push_back(day);
            }
        }
    }
    
    DayofYearSet complement(my_list);
    return complement; 
}

bool DayofYearSet::is_it_contains(DayofYear& d){ 
    int flag = 0;
    for (int i = 0; i < this->size(); i++){
        if(this->arr_d[i].getDay() == d.getDay() && this->arr_d[i].getMonthNumber() == d.getMonthNumber()){
            flag = 1;
        }
    }
    if(flag)
        return true;
    else    
        return false;
}


DayofYearSet::DayofYear DayofYearSet::operator[](int index) const { //returning the element at given position.
      return arr_d[index];
    }

void DayofYearSet::remove(DayofYear& d){ //to remove an element
    DayofYearSet::DayofYear* temp_array;
    _size = _size - 1;
    temp_array = new DayofYear[_size];

    int removeIndex;
    int flag = 1;
    for(auto i = 0 ; i <_size+1 && flag;i++){
        if(arr_d[i].getDay()==d.getDay() && arr_d[i].getMonthNumber()==d.getMonthNumber()){
            removeIndex = i;
            flag = 0;
        }
    }
    int j = 0;
    for(auto i = 0; i < _size;){
        if(i!=removeIndex){
            temp_array[i] = arr_d[j];
            i++;
            j++;
        }
        else{
            removeIndex = -1;
            j++;
        }
    }
    delete []arr_d;
    arr_d = temp_array;
    for(int i=0;i<_size;i++){
        cout << "Month: "<< arr_d[i].getMonthNumber() << " Day: " << arr_d[i].getDay() << endl;
    }

}

//DayofYear functions
DayofYearSet::DayofYear::DayofYear(int monthValue, int dayValue) : month(monthValue), day(dayValue){testDate();}

DayofYearSet::DayofYear::DayofYear(int monthValue) : month(monthValue), day(1){testDate();}

DayofYearSet::DayofYear::DayofYear() : month(1), day(1){}

bool DayofYearSet::DayofYear::testDate(){
     //checking if day and month are valid
      if (day < 1 || day > 31 || month < 1 || month > 12) {
        return false;
      }
      //checking if day is valid for the month
      if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
      }
      if (month == 2 && day > 29) {
        return false;
      }
      return true;
    }

DayofYearSet::DayofYear::~DayofYear(){} //destructors 