#include "DoublyLinkedList.h"

DoublyLinkedList::DNode::DNode(const ElementType& data)
	: data(data), next(0), prev(0)
{
}
DoublyLinkedList::DoublyLinkedList()
	:myFirst(0), mySize(0)
{
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& orig) {
	if (isEmpty()) {
		DoublyLinkedList();
	}
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

DoublyLinkedList::~DoublyLinkedList()
{
	if (!isEmpty()) {
		DNodePtr tempPtr = myFirst;

		while (tempPtr->next != 0)
		{
			myFirst = myFirst->next;
			delete tempPtr;
			tempPtr = myFirst;
		}
		delete tempPtr;
		mySize = 0;
	}
}
bool DoublyLinkedList::isEmpty() const {
	return mySize == 0;
}

bool DoublyLinkedList::insertAtPos(ElementType data, int p) {
	if (p > mySize || p < 0) {
		cout << "invalid position";
		return false;
	}
	if (isEmpty()) {
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
bool DoublyLinkedList::insertAtBeginning(ElementType data) {
	return insertAtPos(data, 0);
}
bool DoublyLinkedList::insertAtEnd(ElementType data) {
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
			if (p == mySize) {
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

int DoublyLinkedList::search(ElementType data) {
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

void DoublyLinkedList::display(ostream& out)
{
	if (isEmpty()) {
		out << "\nThe list is empty\n";
	}
	else {
		DNodePtr tempPtr = myFirst;
		while (tempPtr != 0) {
			out << tempPtr->data << " ";
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
	ElementType Student;
	for (int i = 0; i < numOfStudents; i++) {
		in >> Student;
		L.insertAtEnd(Student);
	}
	return in;
}