#include "IntList.h"

#include <stdexcept>
using namespace std;

/* Initializes an empty list.
*/
IntList::IntList() : head(nullptr) {}

/* Inserts a data value to the front of the list.
*/
void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }  
}

const int &IntList::at(unsigned index) const {
   IntNode *current = head;

   unsigned currIndex = 0;

   while(current != nullptr && currIndex < index) {
      current = current->next;
      ++currIndex;
   }

   if(current == nullptr || currIndex != index)  {
      throw out_of_range("IntList::at_range_check") ;
   }

   return current->value;
}

int &IntList::at(unsigned index) {
   IntNode *current = head;

   unsigned currIndex = 0;

   while(current != nullptr && currIndex < index) {
      current = current->next;
      ++currIndex;
   }

   if(current == nullptr || currIndex != index)  {
      throw out_of_range("IntList::at_range_check") ;
   }

   return current->value;
}



