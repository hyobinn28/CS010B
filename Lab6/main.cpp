#include "IntVector.h"
#include <iostream>

using namespace std;

int main() {
    IntVector test1(5, 3);          //testing values (not empty)
    IntVector test2(0, 2);          //testing for (empty)

    cout << "Test 1 begin." << endl;            //testing for test1 values
    cout << "Test 1's size: " << test1.size() << endl;
    cout << "Test 1's capacity: " << test1.capacity() << endl;
    cout << "Test 1's emptyness: ";

    if(test1.empty()) {
        cout << "Empty" << endl;
    }
    else {
        cout << "Not empty" << endl;
    }

    cout << endl;

    cout << "Testing at function:" << endl;
    cout << "Value at index 2 in test1: ";

    if(2 < test1.size()) {
        cout << test1.at(2) << endl;
    }
    else {
        cout << "Index is out of range" << endl;
    }

    cout << endl;

    cout << "Testing front function:" << endl;
    if(!test1.empty()) {
        cout << "Front value: " << test1.front() << endl;
    }
    else {
        cout << "Erorr" << endl;
    }

    cout << endl;

    cout << "Testing back function:" << endl;

    if(!test1.empty()) {
        cout <<  "Back value: " << test1.back() << endl;
    }
    else {
        cout << "Error" << endl;
    }

    cout << endl;

    cout << "Test 2 begin." << endl;
    cout << "Test 2's size: " << test2.size() << endl;
    cout << "Test 2's capacity: " << test2.capacity() << endl;
    cout << "Test 2's emptyness: ";

    if(test2.empty()) {                     //testing for test 2 values
        cout << "Empty" << endl;
    }
    else {
        cout << "Not empty" << endl;
    }
    cout << "Testing test 2 at, back, front functions: " << endl;

    cout << endl;

    cout << "At function test: " << endl;

    if(2 < test2.size()) {
        cout << test2.at(2) << endl;
    }
    else {
        cout << "Index is out of range" << endl;
    }

    cout << endl;

    cout << "Front function Test: " << endl;

    if(!test2.empty()) {
        cout << "Front value: " << test2.front() << endl;
    }
    else {
        cout << "Error. Test 2 is empty" << endl;
    }
    
    cout << endl;
    cout << "Back function Test: " << endl;

    if(!test2.empty()) {
        cout <<  "Back value: " << test2.back() << endl;
    }
    else {
        cout << "Error. Test 2 is empty." << endl;
    }
    
    cout << endl;

    return 0;
}