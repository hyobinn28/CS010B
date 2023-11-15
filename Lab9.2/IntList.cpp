#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream &operator<<(ostream &out, const IntList &list) {
   if(list.head) {
      out << list.head->value;
         if (list.head->next) {
            out << " ";
         }
      operator<<(out, list.head->next);
   }
   
   return out;
}

//helper funciton operator<<
ostream &operator<<(ostream &out, IntNode *node) {
   if(node) {
      out << node->value;

      if (node->next) {
         out << " ";
      }
      operator<<(out, node->next);
   }

   return out;
}


//helper function exists 
bool IntList::exists(IntNode *node, int value) const {
   if(node) {
      if (node->value == value) {
         return true;
      }

     return exists(node->next, value);
   }

   return false;
}


bool IntList::exists(int value) const {
   return exists(head, value);
}