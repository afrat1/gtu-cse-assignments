#include <iostream>
#include <algorithm>
#include "PFArray.h"
#include "PFArray.cpp"

using namespace std;
int main() {

    cout << "Testing Empty() and Size() functions!" << endl << endl;

    pf::PFArray<int> my_array;

    if (my_array.empty()) {
        cout << "Array is empty" << endl;
    }
    else{
        cout << "Array is not empty" << endl;
    }

    cout << "Array size: " << my_array.size() << endl << endl;

    cout << "After adding element to in using move semantic functions!" << endl;

    my_array.push_back(512);
    my_array.push_back(17);
    my_array.push_back(0);
    my_array.push_back(75);
    my_array.push_back(7548);
    my_array.push_back(215);
    my_array.push_back(918);

    // Iterate through the array using iterators
    cout << "Elements in the array with begin() & end() using iterators:" << endl;

    for (auto it = my_array.begin(); it != my_array.end(); ++it) {
    cout << *it << " ";
}
    cout << endl << endl;

    cout << "Testing Empty() and Size() functions again!" << endl << endl;

    if (my_array.empty()) {
        cout << "Array is empty" << endl;
    }
    else{
        cout << "Array is not empty" << endl;
    }

    cout << "Array size: " << my_array.size() << endl << endl;

    
    cout << "Testing Erase() function that takes iterator: [begin()+4]!" << endl;
    pf::PFArray<int>::iterator it = my_array.begin();
    it = it + 4; // it now points to the element with coordinate 5
    
    my_array.erase(it); // Removes the element with coordinate 5
    
    for (pf::PFArray<int>::iterator it = my_array.begin(); it != my_array.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;
    
    cout << "Elements in the array with erase(): [value = 75] " << endl;
    my_array.erase(75);
    for (pf::PFArray<int>::iterator it = my_array.cbegin(); it != my_array.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    cout << "Elements in the array with range based for loops: " << endl;
    for (int x : my_array) {
        cout << x << " ";
    }
    cout << endl << endl;

    cout << "Elements in the array with for_each: " << endl;
    for_each(my_array.begin(), my_array.end(), [](int x) {
        cout << x << " ";
    });
    cout << endl << endl;

    my_array.sort();
    cout << "Elements in the array with sort(): " << endl;
    for (pf::PFArray<int>::iterator it = my_array.begin(); it != my_array.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    cout << "The usage of find: [value = 215]" << endl;
    auto ita = std::find(my_array.begin(), my_array.end(), 215);
    if (ita != my_array.end()) {
        cout << "Element found at position " << distance(my_array.begin(), ita);
    } else {
        cout << "Element not found";
    }
    cout << endl << endl;
    cout << "Elements in the array with cbegin() & cend(): " << endl;
    for (pf::PFArray<int>::iterator it = my_array.cbegin(); it != my_array.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl << endl;

    cout << "Testing clear() function: " << endl;
    my_array.clear();


    if (my_array.empty()) {
        cout << "Array is empty" << endl;
    } else {
        cout << "Array is not empty" << endl;
    }
    cout << "Array size: " << my_array.size() << endl;
    
    return 0;
}
