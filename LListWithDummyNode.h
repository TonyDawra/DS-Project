
/*-- LListWithDummyNode.h ---------------------------------------------------------------
This header file defines the data type Time for processing time. 
Basic operations are:
Constructor
Deconstructor
...
-------------------------------------------------------------------------*/
#ifndef LLISTWITHDUMMYNODE_H
#define LLISTWITHDUMMYNODE_H
#include "Course.h"
#include <iostream>
using namespace std;
typedef Course ElementType;
class LListWithDummyNode{
    /*** Node class ***/
    private:
        class Node { // Inner class definition of node structure
            public:
                Node(const ElementType&);
                ElementType data;
                Node* next;  
                // Some Node function members        
    };
    typedef Node* NodePtr;
    /*** List's data members ***/
    NodePtr myFirst;
    int mySize;

    public:
    /*** List's function members ***/
    LListWithDummyNode();
    /********************************************************************
            * Purpose: Construct a Linked List With Dummy object
            * Precondition: none
            * Postcondition: an empty Linked List with Dummy object has been constructed; mySize=0
            ********************************************************************/
    LListWithDummyNode(const LListWithDummyNode&);
    /********************************************************************
            * Purpose: 
            * Precondition: 
            * Postcondition: 
            ********************************************************************/
    ~LListWithDummyNode();
    /********************************************************************
            * Purpose: 
            * Precondition: 
            * Postcondition: 
            ********************************************************************/
    int getmySize();
    /********************************************************************
            * Purpose: 
            * Precondition: 
            * Postcondition: 
            ********************************************************************/
    bool isEmpty()const;
    /********************************************************************
            * Purpose: check if the Linked list with dummy is enoty
            * Precondition: none
            * Postcondition: true is returned if the linked list with dummy is empty , false if not
            ********************************************************************/
    bool insertAtEnd(const ElementType&);
    /********************************************************************
            * Purpose: insert a value into the linked list at the end
            * Precondition: course is the object to be inserted; there is n
            * Postcondition: 
            ********************************************************************/
    int search(const ElementType&);
    /********************************************************************
            * Purpose: 
            * Precondition: 
            * Postcondition: 
            ********************************************************************/
    ostream& display(ostream&);
    /********************************************************************
            * Purpose: display the linked list with dummy
            * Precondition: the ostream out is open 
            * Postcondition: the courses represented by the LListWithDummy object has been inserted into out
            ********************************************************************/
    
};// end of LListWithDummy class
// Prototype of output operator
ostream& operator<<(ostream&,ElementType&);
// Prototype of input operator
istream& operator>>(istream&,ElementType&);
#endif /* ARRAYLIST_H */