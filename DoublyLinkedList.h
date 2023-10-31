#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef Student ElementType;

class DoublyLinkedList {
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
public:
    DoublyLinkedList();
    DoublyLinkedList(const LinkedList&);
    virtual ~DoublyLinkedList();
    bool isEmpty() const;
    bool insertAtPos(ElementType, int);
    bool deleteAtPos(int);
    bool insertAtBeginning(ElementType);
    void displayStudents(ostream&);
};
ostream& operator<<(ostream&, DoublyLinkedList&);
istream& operator>>(istream&, DoublyLinkedList&);
#endif



