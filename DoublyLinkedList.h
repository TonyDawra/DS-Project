/*-DoublyLinkedList.h--------------------------------------------------------------------

  Author: Kayan Abdelbaki

  This header file defines the DoublyLinkedList data type.
  Basic operations:
    no-arg constructor         : Constructs a default DCList
    copy constructor           : Constructs a new DCList using existing DCList parameter
    destructor                 : Deletes a DCList
    isEmpty					   : Checks whether or not DCList is empty
    search                     : Checks whether inputted data exists in DCList
    insertAtPosition           : Inserts data at certain position of DCList
    insertAtBeginning		   : Inserts data at beginning of DCList
    insertAtEnd                : Inserts data at end of DCList
    deleteAtPosition           : Deletes data at inputted posiiont
    deleteAValue               : Deletes first occurence of inputted data
    deleteBeforeAnElement      : Deletes first occurence of element before inputted data
    findAndDelete              : Deletes all occurences of inputted data
    removeFirst                : Cuts & returns data of first node
    removeLast                 : Cuts & returns data of last node
    deleteDuplicates           : Deletes duplicate elements in the DCList
    display                    : Displays content of the DCList
---------------------------------------------------------------------------------------*/


#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
using namespace std;

typedef int ElementType;

class DoublyLinkedList
{

public:
    /******** Function Members *********/
        /***** No-Arg Constructor *****/
    DoublyLinkedList();
    /*------------------------------------------------------------------------------
      Constructs a new DoublyLinkedList object

      Precondition: None
      Post-Condition: An empty DoublyLinkedList object is constructed;
                      myFirst points to NULL; and mySize is 0.
     -------------------------------------------------------------------------------*/

     /***** Destructor *****/
    virtual ~DoublyLinkedList();
    /*------------------------------------------------------------------------------
       Destroys a DoublyLinkedList object

       Precondition: The life of a List object is over.
       Post-Condition: The DoublyLinkedList is empty;
                       myFirst points to NULL; and mySize is 0.
    -------------------------------------------------------------------------------*/

    /***** Copy Constructor *****/
    DoublyLinkedList(const DoublyLinkedList&);

    /*----------------------------------------------------------------------------------
      Construct a copy of a DoublyLinkedList object.

      Precondition: A copy of origList is needed; origList is a const reference
                    parameter.
      Post-Condition: A DoublyLinkedList object is constructed with myFirst, mySize and
                      DoublyNodes equal to the parameter's
    ----------------------------------------------------------------------------------*/





    /***************************** Is Empty method *******************************
    * Checks if the Doubly
    *
    * Precondition: None
    * Post-Condition: Returns true if the list is empty, false if it's not
    *******************************************************************************/
    bool isEmpty() const;


    bool insertAtPos(ElementType, int);
    bool deleteAtPos(int);
    bool insertAtBeginning(ElementType);
    bool insertAtEnd(ElementType);
    int search(ElementType);
    void display(ostream&);

private:
    class DNode { // Inner class definition of node structure
    public:
        DNode(const ElementType&);
        ElementType data;
        DNode* next;
        DNode* prev;
    };
    typedef DNode* DNodePtr;
    int mySize;
    DNodePtr myFirst;


};
ostream& operator<<(ostream&, DoublyLinkedList&);
istream& operator>>(istream&, DoublyLinkedList&);
#endif


