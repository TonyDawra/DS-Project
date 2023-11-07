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


    /***** isEmpty operation *****/
    inline bool isEmpty() const;

    /*----------------------------------------------------------------------
       Check if a DoublyLinkedList is empty.

       Precondition: None

       Postcondition: true is returned if the list is empty, false if not.
    -----------------------------------------------------------------------*/
    

    /***** insert at position operation *****/
    bool insertAtPos(ElementType, int);
    /*----------------------------------------------------------------------
       Insert a value into the list at a given position.
       Precondition: item is the value to be inserted; there is room in
                     the array (mySize < CAPACITY); and the position satisfies
                     o <= pos <= mySize.
       Postcondition: item has been inserted into the list at the position
                     determined by pos (provided there is room and pos is a legal
                     position).
    -----------------------------------------------------------------------*/

    /***** delete at position operation *****/
    bool deleteAtPos(int);
    /*----------------------------------------------------------------------
    Remove a value from the DoublyLinkedList at a given position.
    Precondition: The list is not empty and the position satisfies
    o <= pos < mySize.
    Postcondition: element at the position determined by pos has been
    removed (provided pos is a legal position).
    ----------------------------------------------------------------------*/

    bool insertAtBeginning(ElementType);
    bool insertAtEnd(ElementType);
    int search(ElementType);

    /***** output *****/
    void display(ostream&);
    /*----------------------------------------------------------------------
        Display a list.
    
        Precondition: The ostream out is open.
    Postcondition: The list represented by this List object has been
    inserted into out.
    -----------------------------------------------------------------------*/

private:
    class DNode { // Inner class definition of node structure
    public:
        DNode(const ElementType&);
        ElementType data;
        DNode* next;
        DNode* prev;
    };
    typedef DNode* DNodePtr;

    /********Data Members ********/
    int mySize;
    DNodePtr myFirst;


}; //---- end of List class

//------Prototype of output operator
ostream& operator<<(ostream&, DoublyLinkedList&);
istream& operator>>(istream&, DoublyLinkedList&);
#endif


