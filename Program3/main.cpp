#include <iostream>
#include "IntVector.h"

using namespace std;
 
int main() {
    IntVector test1;            //declare empty vecotr

    cout << "TESTING BEGIN" << endl << endl;

    //push back function
    for(int i = 1; i <= 10; ++i) {
        test1.push_back(i * 10);
    }

    cout << "Push back test: ";

    for(unsigned int i = 0; i < test1.size(); ++i) {
        cout << test1.at(i) << " ";
    }

    cout << endl;

    //pop back function
    test1.pop_back();

    cout << "Pop back test: ";

    for(unsigned int i = 0; i < test1.size(); ++i) {
        cout << test1.at(i) << " ";
    }

    cout << endl;

    //erase function
    test1.erase(3);

    cout << "Erase function test: ";

    for(unsigned int i = 0; i < test1.size(); ++i) {
        cout << test1.at(i) << " ";
    }

    cout << endl;

    //size test
    cout << "Size function teset: " << test1.size() << endl;

    //capacity test
    cout << "Capacity function test: " << test1.capacity() << endl;

    //empty test
    cout << "Empty function test: "; 

    if(test1.empty()) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    cout << endl;

    //front function test
    cout << "Front function test: " << test1.front() << endl;

    //back function test
    cout << "Back function test: " << test1.back() << endl;

    //resize function test
    test1.resize(3, 12);

    cout << "Resize function test: ";

    for(unsigned int i = 0; i < test1.size(); ++i) {
        cout << test1.at(i) << " ";
    }

    cout << endl;

    //assign function
    test1.assign(3, 99);

    cout << "Assign function test: ";

    for(unsigned int i = 0; i < test1.size(); ++i) {
        cout << test1.at(i) << " ";
    }
    
    cout << endl;

    //reserve function test;
    test1.reserve(33);

    cout << "Reserve function test: ";

    for(unsigned int i = 0; i < test1.size(); ++i) {
        cout << test1.at(i) << " ";
    }

    cout << endl;

    //insert function test;
    unsigned insertIndex = 2;
    int value = 22;

    if(insertIndex <= test1.size()) {
        test1.insert(insertIndex, value);

        cout << "Insert function test: ";

        for(unsigned int i = 0; i < test1.size(); ++i) {
            cout << test1.at(i) << " ";
        }

        cout << endl;
    }
    else {
        cout << "Invalid index" << endl;
    }

    //clear funciton test
    test1.clear();
    cout << "Clear function test: ";

    for(unsigned int i = 0; i < test1.size(); ++i) {
        cout << test1.at(i) << " ";
    }

    cout << endl << endl;
    cout << "TEST COMPLETE" << endl;

    return 0;
}