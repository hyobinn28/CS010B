#include "IntVector.h"                  //contain class delcaration 

using namespace std;

IntVector::IntVector(unsigned capacity, int value) {    //capacity = size of vector, value = user value
    _size = capacity;
    _capacity = capacity;
    
    if(capacity == 0) {
        _data = nullptr;        //nullptr = not point
    }

    else {                               //if capacity isnt 0, it initialize each element with specifed vlaue
        _data = new int[capacity];

        for(unsigned int i = 0; i < capacity; ++i) {
            _data[i] = value;
        }
    }
}

//The destructor is used to clean up (delete) any
//remaining dynamically-allocated memory. For this class,
//that will be the array pointed to by the int pointer named _data.
IntVector::~IntVector() {      
    delete[] _data;
}

//function retunrs current size
unsigned IntVector::size() const {
    return _size;
}

//function returns current capacity (maximum array size)
unsigned IntVector::capacity() const {
    return _capacity;
}

//returns whether the IntVector is empty
bool IntVector::empty() const {
    return _size == 0;
}

//return the value stored in element at the passed index position
//but returns out of range when input invalid index
const int &IntVector::at(unsigned num) const {          //num == specified index val
    if(num >= _size) {
        throw out_of_range("IntVector::at_range_check");             //throwing an excpetion
    }

    return _data[num];              //fine value at specified index
}

const int &IntVector::front() const {       //finds for very first value
    return _data[0];
}

const int &IntVector::back() const {        //finds for very last value
    return _data[_size - 1];
}