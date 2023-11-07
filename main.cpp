#include <iostream>
#include <fstream>
#include "Student.h"
#include "Course.h"
#include "DoublyLinkedList.h"
#include "LListWithDummyNode.h"

using namespace std;

int main(){
    ifstream inputFile;
    ofstream outputFile; 
    inputFile.open("")
    int choice=0;
    while(choice!=10){
        cout<<"\nMenu:\n";
        cout<<"1. Display the list of non-registered students.";
        cout<<"2. Display the list of offered courses.";
        cout<<"3. Display the list of registered students with the registered courses.";
        cout<<"4. Display the list of offered courses with the registered students.";
        cout<<"5. Display the registered courses for a student.";
        cout<<"6. Display the list of students registered in a course.";
        cout<<"7. Display the information related to a specific student.";
        cout<<"8. Register a student.";
        cout<<"9. Choose a student to add/drop a course for him/her.";
        cout<<"10. Quit the application.";

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
            case 10:
            cout<<" Adios ";
            break;
            default:
            cout<<"Invalid choice. Choose a valid option from the menu";
            break;
        }   
    }
    return 0;
}