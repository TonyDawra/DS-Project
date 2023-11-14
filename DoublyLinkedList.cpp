/*--List.cpp------------------------------------------------------------
This file implements DoublyLinkedList member functions.
-------------------------------------------------------------------------*/

#include "DoublyLinkedList.h"
#include <exception>
#include <stdexcept>

DoublyLinkedList::DNode::DNode(const DLLType& data)
    : data(data), next(0), prev(0) {}

DoublyLinkedList::DoublyLinkedList() : myFirst(0), mySize(0) {}

int DoublyLinkedList::size() const {
    return mySize;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& orig) {
    if (!orig.isEmpty()) {
        myFirst = new DNode(orig.myFirst->data);
        DNodePtr tempPtr = orig.myFirst->next;
        DNodePtr loopingNode = myFirst;
        while (tempPtr != 0) {
            loopingNode->next = new DNode(tempPtr->data);
            loopingNode->next->prev = loopingNode;
            tempPtr = tempPtr->next;
            loopingNode = loopingNode->next;
        }
        mySize = orig.mySize;
    }
}

DoublyLinkedList::~DoublyLinkedList() {
    if (!isEmpty()) {
        DNodePtr tempPtr = myFirst;
        while (tempPtr->next != 0) {
            myFirst = myFirst->next;
            delete tempPtr;
            tempPtr = myFirst;
        }
        delete tempPtr;
        mySize = 0;
    }
}

bool DoublyLinkedList::insertAtPos(DLLType& data, int p) {
    if (p > mySize || p < 0) {
        cout << "invalid position";
        return false;
    }
    if (isEmpty()) {
        cout << data;
        myFirst = new DNode(data);
    }
    else {
        DNodePtr tempNode = new DNode(data);
        if (p == 0) {
            tempNode->next = myFirst;
            myFirst->prev = tempNode;
            myFirst = tempNode;

        }
        else {
            DNodePtr tempPtr = myFirst;

            for (int i = 0; i < p - 1; i++) {
                tempPtr = tempPtr->next;
            }
            if (mySize == p) {
                tempPtr->next = tempNode;
                tempNode->prev = tempPtr;
            }
            else {
                tempNode->next = tempPtr->next;
                tempPtr->next = tempNode;
                tempNode->next->prev = tempNode;
                tempNode->prev = tempPtr;
            }
        }
    }
    mySize++;
    return true;
}
bool DoublyLinkedList::insertAtBeginning(DLLType& data) {
    return insertAtPos(data, 0);
}
bool DoublyLinkedList::insertAtEnd(DLLType& data) {
    return insertAtPos(data, mySize);
}

bool DoublyLinkedList::deleteAtPos(int p) {
    if (p > mySize || p < 0) {
        cout << "invalid position";
        return false;
    }
    else if (isEmpty()) {
        cout << "The list is empty";
        return false;
    }
    else {
        if (p == 0 && mySize == 1) {
            delete myFirst;
        }
        else if (p == 0) {
            myFirst = myFirst->next;
            delete myFirst->prev;
        }
        else {
            DNodePtr PredPtr = myFirst;
            for (int i = 0; i < p - 1; i++) {
                PredPtr = PredPtr->next;
            }
            if (p == mySize - 1) {
                delete PredPtr->next;
            }
            else {
                PredPtr->next = PredPtr->next->next;
                delete PredPtr->next->prev;
                PredPtr->next->prev = PredPtr;
            }
        }
    }
    mySize--;
    return true;
}

int DoublyLinkedList::search(DLLType data) {
    DNodePtr tempPtr = myFirst;
    int i = 0;
    while (tempPtr != 0) {
        if (tempPtr->data == data) {
            return i;
        }
        i++;
        tempPtr = tempPtr->next;
    }
    return -1;
}

DLLType DoublyLinkedList::at(int pos) {
    if (pos >= size() || pos < 0) {
        cerr << "Position out of bounds";
        return NULL;
    }

    DNodePtr temp = myFirst;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    return temp->data;
}

void DoublyLinkedList::display(ostream& out) {
    if (isEmpty()) {
        out << "\nThe list is empty\n";
    }
    else {
        DNodePtr tempPtr = myFirst;
        while (tempPtr != 0) {
            out << *(tempPtr->data) << " \n";
            tempPtr = tempPtr->next;
        }
        out << endl;
    }
}
ostream& operator<<(ostream& out, DoublyLinkedList& L) {
    L.display(out);
    return out;
}
istream& operator>>(istream& in, DoublyLinkedList& L) {
    int numOfStudents;
    cout << "Enter the number of courses you want to add: ";
    cin >> numOfStudents;
    DLLType Student = nullptr;
    for (int i = 0; i < numOfStudents; i++) {
        in >> *Student;
        L.insertAtEnd(Student);
    }
    return in;
}
