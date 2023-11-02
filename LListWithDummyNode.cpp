#include "LListWithDummy.h"
#include <iostream>
using namespace std;

LListWithDummy::Node::Node(const ElementType& data){
    this->data=data;
    this->next=NULL;

}
LListWithDummy::LListWithDummy(){
    this->myFirst=new Node (const ElementType& course)
    this->myFirst->next=NULL;
    this->mySize=0;
}
LListWithDummy::LListWithDummy(const LListWithDummy& orig){
    NodePtr loopingNode = orig.myFirst;
    while (loopingNode != NULL) 
	{
        insertAtEnd(loopingNode->data);
        loopingNode = loopingNode->next;
    }
}
LListWithDummy::~LListWithDummy(){
    
    NodePtr tempPtr;

    while (this->myFirst->next != NULL) 
	{
        tempPtr = this->myFirst;
        this->myFirst = this->myFirst->next;
        delete tempPtr;
        this->mySize--;
}
}
LListWithDummy::isEmpty()const{
    return this->mySize==0;
}
LListWithDummy::insertAtEnd(const ElementType& course){
    NodePtr newPtr = new Node (course);
    if(isEmpty()){
        this->myFirst=newPtr;
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
LListWithDummy::insertAtPosition(const ElementType& course, int position){
    

}

