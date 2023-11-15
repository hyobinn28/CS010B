#include "IntList.h"
//insert cases 
using namespace std;

IntList::IntList() {            //constructor
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {           //destructor
    clear();
}

void IntList::clear() {         //clear list until the list is empty
    while(!empty()) {
        pop_front();
    }
}

void IntList::push_front(int value) {
    IntNode *newValue = new IntNode(value);     //create new value with given value

    if(empty()) {
        head = tail = newValue;                 //update head and tail to point to new value
    }
    else {                                      //if not empty
        newValue->next = head;                  //new value's next pointer to current head
        head = newValue;
    }
}

void IntList::pop_front() {             //function removes front node of list
    if(head) {                          //if list is not empty,
        IntNode *tempVal = head;    
        head = head ->next;             //updates head to point to next node

        delete tempVal;                 //delete original front node

        if(!head) {                     //if list goes to empty after removal, update to nullptr
            tail = nullptr;
        }
    }
}

bool IntList::empty() const {
    return head == nullptr;             //checks if list is empty
}

const int &IntList::front() const {     //first const for return val and second const for the class
    return head->value;                 //retruns a constant reference to value stored in front
}

const int &IntList::back() const {
    return tail->value;                 //returns constant reference to the value stored in back node
}

ostream &operator<<(ostream &out, const IntList &nums) {
    IntNode *now = nums.head;           //start with head of the nums

    if(now) {                           //checks ptr is not null
        do {
            out << now->value;          //output current node's value

            if(now->next) {             //check if theres next node
                out << " ";
            }

            now = now->next;            //move to next node (updates)
        } while(now);
    }

    return out;
}