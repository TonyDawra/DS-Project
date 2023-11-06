#include "LListWithDummyNode.h"
#include <iostream>
using namespace std;

LListWithDummyNode::Node::Node(const ElementType& data){
    this->data=data;
    next=NULL;

}
LListWithDummyNode::LListWithDummyNode(){
    myFirst=new Node (ElementType& course);
    myFirst->next=NULL;
    mySize=0;
}
LListWithDummyNode::LListWithDummyNode(const LListWithDummyNode& orig){
    if(isEmpty()){
        LListWithDummyNode()
    }
    myFirst = new Node(orig.myFirst->data)
    NodePtr tempPtr = orig.myFirst->next;
    NodePtr loopingNode = myFirst;
    while (tempPtr != NULL) {
        loopingNode->next = new Node(tempPtr->data);
        tempPtr=tempPtr->next;
        loopingNode=loopingNode->next;
    }
    mySize=orig.mySize;
}
LListWithDummyNode::~LListWithDummyNode(){
    if(!isEmpty()){
    NodePtr tempPtr=myFirst->next;

    while (tempPtr->next != NULL) {
        myFirst->next = tempPtr->next;
        delete tempPtr;
        tempPtr = myFirst->next;
    }
    delete tempPtr;
    mySize=0;
}
}
bool LListWithDummyNode::isEmpty()const{
    return myFirst->next==NULL;
}
int LListWithDummyNode::getmySize(){
    return mySize;
}
bool LListWithDummyNode::insertAtPosition(const ElementType& course,int pos){
    if(pos>mySize || pos<0){
        cout<<"invalid position";
        return false
    }
    if(isEmpty()&&pos==0){
        NodePtr newPtr=new Node(course);
        myFirst->next=newPtr;
        mySize++;
        return true;
    }
    if(pos==0){
        NodePtr newPtr=new Node(course);
        newPtr->next= myFirst->next;
        myFirst->next=newPtr;
        mySize++;
        return true;
    }
    NodePtr tempPtr=myFirst->next;
    for (int i = 0; i < pos - 1; i++) {
		tempPtr = tempPtr->next;
        if(tempPtr->next==NULL){
            return false;
        }
}
    NodePtr newPtr=new Node(course);
    newPtr->next=tempPtr->next;
    tempPtr->next=newPtr;
    mySize++;
    return true;

}
bool LListWithDummyNode::insertAtEnd(const ElementType& course){
    return insertAtPosition(course,mySize);
}
bool LListWithDummyNode::insertAtBeginning(const ElementType& course){
    return insertAtPosition(course,0);
}
int LListWithDummyNode::search(const ElementType& course){
    NodePtr tempPtr= myFirst->next;
    int pos=0;
    while(tempPtr!= NULL){
        if(tempPtr->data==course){
            return pos;
        }
        tempPtr=tempPtr->next;
        pos++;
    }
    return -1;
}
ostream& LListWithDummyNode::display(ostream& out){
    if(isEmpty()){
        cout<<"Empty List";
    }else{
        NodePtr current = myFirst->next;
        cout << "The list is: ";
        while (current != NULL) {
            out << "The list is: " << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    return out;
}
ostream& operator<<(ostream& out,const LListWithDummyNode& course){
    return course.display(out);
}
istream& operator>>(istream in ,const LListWithDummyNode& course){
    int numCourses;
    cout<<"Enter the number of courses you want to add: ";
    cin>>numCourses;
    ElementType course;
    for(int i=0;i<numCourses;i++){
        in>>course;
        course.insertAtEnd(in);
}
return in;
}