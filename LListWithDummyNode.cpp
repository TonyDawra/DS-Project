#include "LListWithDummyNode.h"
#include <iostream>
using namespace std;

LListWithDummyNode::Node::Node(const ElementType& data){
    this->data=data;
    this->next=NULL;

}
LListWithDummyNode::LListWithDummyNode(){
    this->myFirst=new Node (ElementType& course);
    this->mySize=0;
}
LListWithDummyNode::LListWithDummyNode(const LListWithDummyNode& orig){
    NodePtr loopingNode = orig.myFirst;
    while (loopingNode != NULL) 
	{
        insertAtEnd(loopingNode->data);
        loopingNode = loopingNode->next;
    }
}
LListWithDummyNode::~LListWithDummyNode(){
    
    NodePtr tempPtr;

    while (this->myFirst->next != NULL) 
	{
        tempPtr = this->myFirst;
        this->myFirst = this->myFirst->next;
        delete tempPtr;
        this->mySize--;
}
}
bool LListWithDummyNode::isEmpty()const{
    return this->mySize==0;
}
int LListWithDummyNode::getmySize(){
    return this->mySize;
}
bool LListWithDummyNode::insertAtEnd(const ElementType& course){
    NodePtr newPtr = new Node (course);
    if(isEmpty()){
        this->myFirst->next=newPtr;
        this->mySize++;
        return true;
    }else{
        NodePtr tempPtr= this->myFirst;
        while(tempPtr->next!=NULL){
            tempPtr=tempPtr->next;
        }
        tempPtr->next=newPtr;
        this->mySize++;
        return true;
    }
    return false;
}
int LListWithDummyNode::search(const ElementType& course){
    NodePtr tempPtr= this->myFirst->next;
    int pos=0;
    while(tempPtr!= NULL){
        if(tempPtr->data==course){
            return pos;
        }
        tempPtr=tempPtr->next;
        pos++
    }
    return -1;
}
ostream& LListWithDummyNode::display(ostream& out){
    if(isEmpty()){
        cout<<"Empty List";
    }else{
        NodePtr current = this->myFirst->next;
        cout << "The list is: ";
        while (current != NULL) {
            out << "The list is: " << current->data << " ";
            this->current = current->next;
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