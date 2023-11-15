#include "IntList.h"

using namespace std;

//constructor//
IntList::IntList() : head(nullptr), tail(nullptr) {}

//destructor//
IntList::~IntList() {
    clear();
}

//clears the lists//
void IntList::clear() {
    while(!empty()) {
        pop_front();
    }
}

//pushes the new value to the front of the list
void IntList::push_front(int value) {
    IntNode *frontNode = new IntNode(value);

    if(empty()) {                       //if list is empty, new node becomes head and tail 
        head = tail = frontNode;
    }
    else if(!empty()) {
        frontNode->next = head;
        head = frontNode;
    }
}

//deletes the front value
void IntList::pop_front() {
    if(!empty()) {
        IntNode *hold = head;
        head = head->next;

        if(head == nullptr) {
            tail = nullptr;
        }
        
        delete hold;
    }
}

//chekcs if the list is empty by looking if the first value is nullptr
bool IntList::empty() const {
    return head == nullptr;
}

//gets the first value of the list
const int &IntList::front() const {
    return head->value;
}

//gets the last value of the list
const int &IntList::back() const {
    return tail->value;
}

/*the copy constructor. Make sure this performs deep copy.*/
IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    IntNode *currVal = cpy.head;        //pointer to traverse list

    while(currVal != nullptr) {
        IntNode *newVal = new IntNode(currVal->value);

        //if first node added to the list, update head and tail
        if(tail == nullptr) {
            head = tail = newVal;
        }
        else {                          //or new value to end of the lsit
            tail->next = newVal;
            tail = newVal;
        }

        currVal = currVal->next;        //move to the next value in the list
    }

}

/*the overloaded assignment operator. Make sure this performs deep copy.*/
IntList &IntList::operator=(const IntList &rhs) {
    if(this != &rhs) {
        clear();

        IntNode *currVal = rhs.head;

        while(currVal != nullptr) {
            push_back(currVal->value);
            currVal = currVal->next;
        }
    }

    return *this;
}

/*Inserts a data value (within a new node) at the back end of the list.*/
void IntList::push_back(int value) {
    IntNode *backNode;
    backNode = new IntNode(value);

    if(empty()) {
        head = tail = backNode;
    }
    else if(!empty()) {
        tail->next = backNode;
        tail = backNode;
    }
}

/*Sorts the integers in the list into ascending order.
Do NOT move the nodes, just the integers.*/
void IntList::selection_sort() {
    if(head == nullptr || head == tail) {       //checks if list is empty or contains only one value
        return;
    }

    IntNode *inOrderHead = nullptr;
    IntNode *inOrderTail = nullptr;

    while(head != nullptr) {
        //looks for smallest value and its previous 
        IntNode *smallest = head;
        IntNode *prevVal = nullptr;
        IntNode *prevSmallVal = nullptr;
        IntNode *currVal = head;

        while(currVal != nullptr) {
            if(currVal->value < smallest->value) {
                prevSmallVal = prevVal;
                smallest = currVal;
            }

            prevVal = currVal;
            currVal = currVal->next;
        }

        //removing smallest node from original place
        if(prevSmallVal != nullptr) {
            prevSmallVal->next = smallest->next;
        }
        else {
            head = head->next;
        }

        if(inOrderTail != nullptr) {
            inOrderTail->next = smallest;
        }
        else {
            inOrderHead = smallest;
        }

        //add smallest node to sorted list
        inOrderTail = smallest;
        smallest->next = nullptr;
    }

    //update head and tail 
    head = inOrderHead;
    tail = inOrderTail;
}

/*function loops through the list until if finds the correct position for the new data
value and then inserts the new IntNode in that location. This function may NOT ever sort the list.*/
void IntList::insert_ordered(int value) {
    IntNode *newVal = new IntNode(value);

    if(empty() || head->value >= value) {
        newVal->next = head;            //insert new value to start of the list
        head = newVal;

        if(tail == nullptr) {           //if list is empty, change tail value
            tail = newVal;
        }

        return;
    }

    IntNode *prevVal = nullptr;
    IntNode *currVal = head;

    while(currVal != nullptr && value > currVal->value) {
        prevVal = currVal;
        currVal = currVal->next;
    }

    //insert new node to the right place
    if(prevVal) {
        newVal->next = prevVal->next;
        prevVal->next = newVal;
    }
    else {
        newVal->next = head;
        head = newVal;
    }

    //update the tail if new node is inserted at the end
    if(currVal == nullptr) {
        tail = newVal;
    }
}

/*Removes all duplicate data values(actually removes the nodes that contain the values)
within the list. Always remove just the later value within the list when a duplicate is found.
This function may NOT ever sort the list.*/
void IntList::remove_duplicates() {         
    if(empty() || head == tail) {       //checks if list is empty or have only one value
        return;
    }

    IntNode *currVal = head;

    for(IntNode *i = head; i != nullptr; i = i->next) {     //outer loop
        for(IntNode *j = i->next, *prevJ = i; j != nullptr;) {  //inner loop (compare)
            if(j->value == i->value) {        //if duplicate
                prevJ->next = j->next;      
                delete j;                    //delete duplicate node
                j = prevJ->next;             //move the node to the next node after the deleted 
            }
            else {                  //when duplicate is not found
                prevJ = j;          //update previous pointer
                j = j->next;        //moving j to next node
            }
        }
    }

    while(currVal->next != nullptr) {       //updating the tail pointer to point the last not null node
        currVal = currVal->next;
    }

    tail = currVal;
}


/*
 A global friend function that outputs to the stream all of the integer values within the list on a single line,
 each separated by a space. This function does NOT send to the stream a newline or space at the end.
 */
ostream &operator<<(ostream &out, const IntList &rhs) {
    if(rhs.empty()) {
        return out;
    }
    else {
        IntNode *currVal = rhs.head;
        out << currVal->value;

        while(currVal->next != nullptr) {
            currVal = currVal->next;
            out << " " << currVal->value;
        }
    }

    return out;
}