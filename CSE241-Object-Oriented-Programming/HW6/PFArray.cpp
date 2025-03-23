#include <iostream>
#include <memory>
#include <iterator>
#include "PFArray.h"

using namespace std;

namespace pf {

template <typename T>
PFArray<T>::PFArray() : size_(0), the_data(nullptr) {}

template <typename T>
PFArray<T>::PFArray(int size) : size_(size), the_data(new T[size]) {}

template <typename T>
PFArray<T>::PFArray(const PFArray& other) : size_(other.size_), the_data(new T[other.size_]) {
        copy(other.the_data.get(), other.the_data.get() + size_, the_data.get());
    }

template <typename T>
bool PFArray<T>::empty() const {
        return size_ == 0;
    }    

template <typename T>
int PFArray<T>::size() const {
        return size_;
    }

template <typename T>
void PFArray<T>::clear() {
        the_data.reset();
        size_ = 0;
    }

template <typename T>
T& PFArray<T>::operator[](int index) {
        if (index < 0 || index >= size_) {
            throw out_of_range("PFArray subscript out of range");
        }
        return the_data[index];
    }

template <typename T>
const T& PFArray<T>::operator[](int index) const {
        if (index < 0 || index >= size_) {
            throw out_of_range("PFArray subscript out of range");
        }
        return the_data[index];
    }

template <typename T>
void PFArray<T>::push_back(const T& element) {
        shared_ptr<T> new_data(new T[size_ + 1], default_delete<T[]>());
        for (int i = 0; i < size_; ++i) {
            new_data.get()[i] = the_data.get()[i];
        }
        new_data.get()[size_] = element;
        the_data = new_data;
        ++size_;
    }

template <typename T>
void PFArray<T>::push_back(T&& element) {
        shared_ptr<T> new_data(new T[size_ + 1], default_delete<T[]>());
        for (int i = 0; i < size_; ++i) {
            new_data.get()[i] = move(the_data.get()[i]);
        }
        new_data.get()[size_] = move(element);
        the_data = new_data;
        ++size_;
    }

template <typename T>
void PFArray<T>::pop_back() {
        if (size_ > 0) {
            shared_ptr<T> new_data(new T[size_ - 1], default_delete<T[]>());
            for (int i = 0; i < size_ - 1; ++i) {
                new_data.get()[i] = the_data.get()[i];
            }
            the_data = new_data;
            --size_;
        }
    }

template <typename T>
PFArray<T>::iterator::iterator(T* p) : pointer(p) {}

template <typename T>
T& PFArray<T>::iterator::operator*() { return *pointer; }

template <typename T>
const T& PFArray<T>::iterator::operator*() const{ return *pointer; }

template <typename T>
T* PFArray<T>::iterator::operator->() {return pointer;}

template <typename T>
typename PFArray<T>::iterator& PFArray<T>::iterator::operator=(const iterator& other) {
            pointer = other.pointer;
            return *this;
        }

template <typename T>
bool PFArray<T>::iterator::operator==(const iterator& other) const {
    return pointer == other.pointer;
}

template <typename T>
bool PFArray<T>::iterator::operator!=(const iterator& other) const {
    return pointer != other.pointer;
}

template <typename T>
bool PFArray<T>::iterator::operator<(const iterator& other){
    return pointer < other.pointer;
}

template <typename T>
void PFArray<T>::erase(const T& value) {
        int newSize = 0;
        for (int i = 0; i < size_; ++i) {
            if (the_data.get()[i] != value) {
                the_data.get()[newSize++] = the_data.get()[i];
            }
        }
        size_ = newSize;
    }

template <typename T>
typename PFArray<T>::iterator PFArray<T>::cbegin() const {
        return iterator(the_data.get());
    }

template <typename T>
typename PFArray<T>::iterator PFArray<T>::cend() const {
        return iterator(the_data.get() + size_);
    }
}