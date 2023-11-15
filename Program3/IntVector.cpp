#include "IntVector.h"

using namespace std;

//set both size and capacity of the IntVector to the value of the capacicy
//argument passed in or the default value of 0 if no argument is passed in
IntVector::IntVector(unsigned capacity, int value) {
    _size = 0;
    _capacity = 0;
    _data = nullptr;

    if(capacity > 0) {
        _data = new int[capacity];
        _capacity = capacity;
        _size = capacity;

        for(unsigned i = 0; i < _capacity; ++i) {
            _data[i] = value;
        }
    }
}

//destructor used to clean up
IntVector::~IntVector() {
    delete[] _data;
}

//returns the current size of IntVector object
unsigned IntVector::size() const {
    return _size;
}

//returns the current capacity of IntVector object
unsigned IntVector::capacity() const {
    return _capacity;
}

//returns whether the IntVector is empty
bool IntVector::empty() const {
    return _size == 0;
}

//function returns the value stored at the passed index position
//function thorws out of range exception if index is beyond the size
const int &IntVector::at(unsigned index) const {
    if(index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }

    return _data[index];
}


int &IntVector::at(unsigned index) {
    if(index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }

    return _data[index];
}

//function inserts data at position index -> all values currently at position index 
//and greater are shifted to the right by 1
//size increase by 1, however size will become larger than capacity
void IntVector::insert(unsigned index, int value) {
    if(index > _size) {
        throw out_of_range("IntVector::insert_range_check");
    }

    if(_size >= _capacity) {
        expand();
    }

    for(unsigned int i = _size; i > index; --i) {
        _data[i] = _data[i - 1];
    }

    _data[index] = value;

    ++_size;
}

//function removes value at position index and shifts all values at position
//greater than index to the left by one
//size decrease by 1
void IntVector::erase(unsigned index) {
    if(index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }

    for(unsigned int i = index; i < _size - 1; ++i) {
        _data[i] = _data[i + 1];
    }

    --_size;
}

const int &IntVector::front() const {
    return _data[0];
}

//function exactly the same thing the accessor version of at does
int &IntVector::front() {
    return _data[0];
}

const int &IntVector::back() const {
    return _data[_size - 1];
}

//function does the same thing the accessor back does
int &IntVector::back() {
    return _data[_size - 1];
}

void IntVector::assign(unsigned n, int value) {
    if(n > _capacity) {
        expand();

        if(n > _capacity) {
            expand(n - _capacity);
        }
    }

    _size = n;
    
    for(unsigned int i = 0; i < n; ++i) {
        _data[i] = value;
    }
}

void IntVector::push_back(int value) {
    if(_size >= _capacity) {
        expand();
    }

    _data[_size] = value;

    ++_size;
}

//decrease size by 1
//never throw exception
void IntVector::pop_back() {
    if(_size > 0) {
        --_size;
    }
}

//reduces the size of the vector to 0
void IntVector::clear() {
    _size = 0;
}

//resizes the vector to contain size elements
//if size smaller, the curr size, function reduces the value of _size to size
//if size greater, than curr size, appropriate number of elements are inserted at end 
//of vector, giving all new elements the value passed in through the 2nd parameter
void IntVector::resize(unsigned n, int value) {
    if(n > _capacity) {
        expand();
        if(n > _capacity) {
            expand(n - _capacity);
        }
    }

    if(_size > n) {
        _size = n;
    }
    else if(_size < n) {
        for(unsigned int i = _size; i < n; ++i) {
            _data[i] = value;
        }
    }

    _size = n;
} 

void IntVector::reserve(unsigned n) {
    if(n > _capacity) {
        expand(n - _capacity);
    }
}

//function will double the capacity of the vector
//should reallocate memory for the dynamically allocated array and update the value of capacity
void IntVector::expand() {
    if(_capacity == 0) {
        expand(1);
    }

    else {
        expand(_capacity);
    }
}

//expand the capacity of the vector by amount passed in
void IntVector::expand(unsigned amount) {
    if(amount == 0) {
        amount = 1;
    }

    int *newValue = new int[_capacity + amount];

    for(unsigned int i = 0; i < _size; ++i) {
        newValue[i] = _data[i];
    }

    delete[] _data;
    _data = newValue;
    _capacity = _capacity + amount;
}