#include <iostream>
#include <memory>
#include <iterator>

#ifndef PFARRAY_h
#define PFARRAY_h
namespace pf{


template <typename T>
class PFArray {
public:
    PFArray();

    // Constructor with size
    PFArray(int size);

    // Copy constructor
    PFArray(const PFArray& other);

    // Destructor
    ~PFArray() {
        the_data.reset();
    }

    bool empty() const; // Returns true if the array is empty

    int size() const; // Returns the size

    void clear(); // Clears the array,.

    T& operator[](int index);

    const T& operator[](int index) const;

    void push_back(const T& element); // Adds an element 

    void push_back(T&& element);  // Adds an element

    void pop_back(); // Removes the last element

    class iterator : public std::iterator <std::forward_iterator_tag, T> {
    public:
        iterator(T* p); // Constructor

        T& operator*();
        const T& operator*() const;

        // Prefix increment operator
        iterator& operator++() {++pointer;
            return *this;
        }

         // Postfix increment operator
        iterator operator++(int) {
            iterator temp = *this;
            ++pointer;
            return temp;
        }

        // Prefix decrement operator
        iterator& operator--() {--pointer;
            return *this;
        }

        // Postfix decrement operator
        iterator operator--(int) {
            iterator temp = *this;
            --pointer;
            return temp;
        }

        T* operator->(); // Arrow operator
        iterator& operator=(const iterator& other); // Assignment operator
        bool operator==(const iterator& other) const;  // Comparison operator (equal)
        bool operator!=(const iterator& other) const; // Comparison operator (not equal)
        bool operator<(const iterator& other); // Comparison operator (less than)
        int operator-(const iterator& other) {return pointer - other.pointer;} // Calculates the distance between two iterators
        
        iterator operator+(int n){ // Adds an integer value to the iterator
            iterator result(*this);
            result.pointer += n;
            return result;
        }
    private:
        T* pointer;
    };

    iterator begin(){ // Returns an iterator to the beginning of the array
        return iterator(the_data.get());
    }

    iterator end(){ // Returns an iterator to the end of the array
        return iterator(the_data.get()+size_);
    }

    void erase(iterator it) {
        std::move(it + 1, end(), it);
        --size_;
    }

    void erase(const T& value); // Removes specified value from the array

    iterator cbegin() const;
     
    iterator cend() const; 

    // Sorts the elements 
    void sort(){
        for (iterator i = begin(); i != end(); ++i){
            for (iterator j = i; j != end(); ++j){
                if (*j < *i){
                T temp = *i;
                *i = *j;
                *j = temp;
                }
            }
        }
    }
private:
    int size_;
    std::shared_ptr<T> the_data;
};

}
#endif