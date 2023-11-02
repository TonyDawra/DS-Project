
/*-- LListWithDummyNode.h ---------------------------------------------------------------
This header file defines the data type Time for processing time. 
Basic operations are:
Constructor
Deconstructor
...
-------------------------------------------------------------------------*/
#ifndef LLISTWITHDUMMYNODE_H
#define LLISTWITHDUMMYNODE_H
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
    }
    typedef Node* NodePtr;
    /*** List's data members ***/
    NodePtr myFirst;
    int mySize;

    public:
    /*** List's function members ***/
    LListWithDummyNode();
    /********************************************************************
            * Purpose: 
            * Precondition: 
            * Postcondition: 
            ********************************************************************/
    LListWithDummyNode(const LListWithDummy&);
    ~LListWithDummyNode();
    set
    bool isEmpty()const;
    bool insertAtEnd(const ElementType&)
    bool insertAtPosition(const ElementType&,int);
    bool deleteAtPosition(const ElementType&,int);
    void display(ostream&);
    
}
ostream& operator<<(ostream&,ElementType&);
istream& operator>>(istream&,ElementType&);
#endif /* ARRAYLIST_H */