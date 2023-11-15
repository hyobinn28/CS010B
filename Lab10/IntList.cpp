#include "IntList.h"

bool IntList::bubbleUp() {
   if(head == nullptr || head->next == nullptr) {   
      return false;                              //set false since no values
   }

   return bubbleUp(head);
}

bool IntList::bubbleUp(IntNode *curr) {
   if(curr == nullptr || curr->next == nullptr) {     //base case
      return false;
   }

   bool switched = false;

   switched = bubbleUp(curr->next);

   if(curr->value > curr->next->value) {        //comparing current value with next
      swap(curr->value, curr->next->value);     //swap
      switched = true;                          //see if its swtiched
   }

   return switched;
}
