#include <iostream>
#include <fstream>
#include "Student.h"
#include "Course.h"
#include "DoublyLinkedList.h"
#include "LListWithDummyNode.h"

using namespace std;

int main(){
    DoublyLinkedList<Student> nonRegisteredStudents;
    DoublyLinkedList<Student> RegisteredStudents;
    LListWithDummyNode<Course> offeredCourses;

    ifstream inputFileStudent,inputFileCourse;
    ofstream outputFile; 

    inputFileStudent.open("student.txt");
    inputFileCourse.open("course.txt");

    int numberOfStudents;
    inputFileStudent>>numberOfStudents;
    for(int i=0;i<numberOfStudents;++i){
        Student student;
        inputFileStudent>>student;
        nonRegisteredStudents.insertAtEnd(student);
    }
    inputFileStudent.close();

    int numberOfCourses;
    inputFileCourse>>numberOfCourses;
    for(int j=0;j<numberOfCourses;++j){
        Course course;
        inputFileCourse>>course;
        offeredCourses.insertAtEnd(course);
    }
    inputFileCourse.close();

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
            cout<<"Students that did not register yet:"<<endl;
            if(nonRegisteredStudents.isEmpty()){
                cout<<"All students are registered"<<endl;
            }else{
                int nbOfNonRegistredStudent=nonRegisteredStudents.getmySize();//make getmysize
                cout<<"ID\t"<<"Name\t"<<"GPA\t"<<"Academic Status"<<endl;
                for(int i=0;i<nbOfNonRegistredStudent;++i){
                  student.displayall();
            }
            break;
            case 2:
            if(offeredCourses.isEmpty()){
                cout<<"No course are being offered"<<endl;
            }else{
                int nbOfOfferedCourses=offeredCourses.getmySize();
                cout<<"Code\t"<<"Title\t"<<"#Credits\t"<<"Enrolled\t"<<"Capacity"<<endl;
                for(int i=0;i<nbOfOfferedCourses;++i){
                  course.displayCourse();
            }
            }
            break;

            case 3:
                int nbOfRegisteredStudents=RegisteredStudents.getmySize();
                for(int i=0;i<nbOfRegisteredStudents;i++){
                cout<<"Student:";
                student.display();
                cout << endl;

            }
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
}