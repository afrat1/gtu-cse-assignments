#include "DayofYear.cpp"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    DayofYearSet::DayofYear d1(5,19),d2(3,12),d3(1,1),d4(12,3),d5(10,29),d6(4,26),d7(10,2),d8(7,5),d9(3,12);
    //d2,d6,d8,d3,d4
    list <DayofYearSet::DayofYear> my_list = {d1,d2,d4,d6,d8};
    list <DayofYearSet::DayofYear> otherList = {d1,d3,d5,d6,d7};
    

    DayofYearSet set1(my_list);
    DayofYearSet set2(otherList);


    cout << "TEST - Overloaded stream insertion operator operator <<" << endl << endl; //operator<<
    cout << "SET1: " << endl;
    cout << my_list << endl;
    cout << "SET2: " << endl;
    cout << otherList << endl;

    cout << "TEST - Overloaded operator ==" << endl << endl; //operator==
    if(d2 == d9){
       cout << "The date2 and date9 sets are equal regardless of the keeping order." << endl << endl;
    }

    cout << "TEST - Overloaded operator !=" << endl << endl; //operator!=
    if(d1!=d4){
        cout << "The date1 and date4 sets are not equal." << endl;
    }    
    if(d2!=d6){
        cout << "The date2 and date6 sets are not equal." << endl << endl;
    }
    
    cout << "TEST - Remove()" << endl << endl; //remove()
    set1.remove(d4); //d1,d2,d6,d8
    cout << "The thirth element is removed from the list!" << endl << endl;

    cout << "TEST - Union Set - operator+" << endl << endl;
    DayofYearSet set3 = set1+set2; 
    cout << set3 << endl;

    int current_size;
    current_size = set1.size(); //size
    cout << "TEST - size()" << endl;
    cout << "The current size of set is " << current_size << endl << endl;

    cout << "TEST - Remove()" << endl << endl; //remove()
    set1.remove(d1); //d2,d6,d8
    cout << "The first element is removed from the list!" << endl << endl;

    cout << "TEST - Intersection Set - operator^" << endl << endl; //operator^
    set3 = set1^set2; 
    cout << set3 << endl;

    current_size = set1.size();
    cout << "TEST - size()" << endl; //size
    cout << "The current size of set is " << current_size << endl << endl;
    
    cout << "TEST -  Adds an element to the set" << endl << endl;
    set1.add(d3); //bunu operator + a çevir, //d2,d3,d6,d8
    cout << "Date 3 is added to list" << endl << endl;

    cout << "TEST - Difference Set - operator-" << endl << endl;
    set3 = set1-set2; 
    cout << set3 << endl;

    set1.add(d4); //bunu operator + a çevir //d2,d3,d4,d6,d8
    cout << "Date 4 is added to list" << endl << endl;

    cout << "TEST - Union Set - operator+" << endl << endl; //operator + set1:d2,d3,d4,d6,d8 set2:d1,d3,d5,d6,d7
    set3 = set1+set2; //set3: d1,d2,d3,d4,d5,d6,d7,d8
    cout << set3 << endl;

    cout << "TEST - Difference Set - operator-" << endl << endl; //operator-
    set3 = set1-set2; //set4: d2,d4,d8
    cout << set3 << endl;

    cout << "TEST - Intersection Set - operator^" << endl << endl; //operator^
    set3 = set1^set2; //set5: d3,d6
    cout << set3 << endl;

    cout << "TEST - Complement Set - operator!" << endl << endl; //operator !
    set3 = !set2;
    cout << set3 << endl;
    
    cout << "TEST - operator[]" << endl << endl; //operator []
    cout << "First element of set1: Month: " <<set1[0].getMonthNumber() << " Day: " << set1[0].getDay() << endl;
    cout << "Thirth element of set2: Month: " <<set1[2].getMonthNumber() << " Day: " << set1[2].getDay() << endl << endl << endl;
    
    return 0;
}