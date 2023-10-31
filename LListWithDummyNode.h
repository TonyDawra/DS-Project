
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
typedef Course Elementtype;
class LListWithDummyNode{
    /*** Node class ***/
    private:
        class Node { // Inner class definition of node structure
            public:
                Node(const Elementtype&);
                Elementtype data;
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
    LListWithDummyNode(const Elementtype&);
    ~LListWithDummyNode();
    set
    bool isEmpty();
    bool isFull();
    bool insertAtPosition(const Elementtype&,int);
    bool deleteAtPosition(const Elementtype&,int);
    void display(ostream&);
    
}
ostream& operator<<(ostream&,Elementtype&);
istream& operator>>(istream&,Elementtype&);
#endif /* ARRAYLIST_H */