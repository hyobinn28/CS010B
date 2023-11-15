#include <iostream>
#include <stdexcept>
using namespace std;

#include "IntList.h"


void display(const IntList &list, unsigned size) {
   if (size != 0) {
      cout << list.at(0);
   }
   for (unsigned i = 1; i < size; ++i) {
      cout << ' ' << list.at(i);
   }  
}


int main() {

   int testNum;
   
   cout << "Enter test number: ";
   cin >> testNum;
   cout << endl;
   
   if (testNum == 1) {
      IntList test1;
      test1.push_front(-3);
      test1.push_front(-2);
      test1.push_front(-1);
      test1.push_front(11);
      test1.push_front(1);
      test1.push_front(2);
      test1.push_front(3);
      test1.push_front(4);
      cout << "at(0): " << test1.at(0) << endl; 
      cout << "at(1): " << test1.at(1) << endl; 
      cout << "at(2): " << test1.at(2) << endl; 
      cout << "at(3): " << test1.at(3) << endl; 
      cout << "at(4): " << test1.at(4) << endl; 
      cout << "at(5): " << test1.at(5) << endl; 
      cout << "at(6): " << test1.at(6) << endl; 
      cout << "at(7): " << test1.at(7) << endl; 
   }
   
   if (testNum == 2) {
      IntList test2;
      test2.push_front(3);
      test2.push_front(4);
      test2.push_front(6);
      test2.push_front(1);
      test2.push_front(7);
      test2.push_front(15);
      cout << "Before: "; display(test2, 6); cout << endl;
      test2.at(0) = test2.at(1);
      cout << "After : "; display(test2, 6); cout << endl;  
   }

   return 0;
}
