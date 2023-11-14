#include "Course.h"
#include "DoublyLinkedList.h"
#include "LListWithDummyNode.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void displayMenu();

void handleUserInput(int choice, DoublyLinkedList& nonRegisteredStudents,
    DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses);

void displayListOfNonRegisteredStudents(
    DoublyLinkedList& nonRegisteredStudents);

void displayListOfOfferedCourses(LListWithDummyNode& offeredCourses);

void displayRegisteredStudentsWithCourses(DoublyLinkedList& RegisteredStudents);

void displayCoursesWithRegisteredStudents(LListWithDummyNode& offeredCourses);

void displayRegisteredCoursesForStudent(DoublyLinkedList& RegisteredStudents);

void displayStudentsInCourse(LListWithDummyNode& offeredCourses);

void displayStudentInfo(DoublyLinkedList& RegisteredStudents);

void registerStudent(DoublyLinkedList& nonRegisteredStudents,
    DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses);

void addOrDropStudent(DoublyLinkedList& nonRegisteredStudents, DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses);

int main() {
    DoublyLinkedList nonRegisteredStudents;
    DoublyLinkedList RegisteredStudents;
    LListWithDummyNode offeredCourses;

    ifstream inputFileStudent, inputFileCourse;
    ofstream outputFile;

    inputFileStudent.open("student.txt");

    if (inputFileStudent.fail()) {
        cerr << "student.txt could not open\n";
        return 1;
    }

    inputFileCourse.open("courses.txt");

    if (inputFileCourse.fail()) {
        cerr << "course.txt could not open\n";
        return 1;
    }

    int numberOfStudents;
    inputFileStudent >> numberOfStudents;
    for (int i = 0; i < numberOfStudents; ++i) {
        Student* student = new Student();
        inputFileStudent >> *student;
        nonRegisteredStudents.insertAtEnd(student);
    }
    inputFileStudent.close();

    int numberOfCourses;
    inputFileCourse >> numberOfCourses;
    for (int j = 0; j < numberOfCourses; ++j) {
        Course* course = new Course();
        inputFileCourse >> *course;
        offeredCourses.insertAtEnd(course);
    }
    inputFileCourse.close();

    int choice = 0;
 
    do {
        displayMenu();
        cin >> choice;
        cout << "\n";
        handleUserInput(choice, nonRegisteredStudents, RegisteredStudents,
            offeredCourses);
    } while (0 < choice && choice < 10);
    return 0;
}

void displayMenu() {
    cout << "1. Display the list of non-registered students.\n";
    cout << "2. Display the list of offered courses.\n";
    cout << "3. Display the list of registered students with the registered "
        "courses.\n";
    cout << "4. Display the list of offered courses with the registered "
        "students.\n";
    cout << "5. Display the registered courses for a student.\n";
    cout << "6. Display the list of students registered in a course.\n";
    cout << "7. Display the information related to a specific student.\n";
    cout << "8. Register a student.\n";
    cout << "9. Choose a student to add/drop a course for him/her.\n";
    cout << "10. Quit the application.\n\n";
    cout << "Enter your choice: " ;
}


void handleUserInput(int choice, DoublyLinkedList& nonRegisteredStudents,
    DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses) {

    

    switch (choice) {
    case 1:
        displayListOfNonRegisteredStudents(nonRegisteredStudents);
        break;
    case 2:
        displayListOfOfferedCourses(offeredCourses);
        break;
    case 3:
        displayRegisteredStudentsWithCourses(RegisteredStudents);
        break;
    case 4:
        displayCoursesWithRegisteredStudents(offeredCourses);
        break;
    case 5:
        displayRegisteredCoursesForStudent(RegisteredStudents);
        break;
    case 6:
        displayStudentsInCourse(offeredCourses);
        break;
    case 7:
        displayStudentInfo(RegisteredStudents);
        break;
    case 8:
        registerStudent(nonRegisteredStudents, RegisteredStudents, offeredCourses);
        break;
    case 9:
        addOrDropStudent(nonRegisteredStudents, RegisteredStudents, offeredCourses);
        break;
    case 10:
        break;
    default:
        cout << "Invalid choice. Choose a valid option from the menu";
        return;
    }
}

void displayListOfNonRegisteredStudents(
    DoublyLinkedList& nonRegisteredStudents) {

    cout << "Students that did not register yet:" << endl;
    if (nonRegisteredStudents.isEmpty()) {
        cout << "All students are registered" << endl;
        return;
    }
    cout << "ID\t\t"
        << "Name\t\t"
        << "GPA\t"
        << "Academic Status" << endl;

    nonRegisteredStudents.display(cout);
}

void displayListOfOfferedCourses(LListWithDummyNode& offeredCourses) {

    if (offeredCourses.isEmpty()) {
        cout << "No course are being offered" << endl;
        return;
    }
    int nbOfOfferedCourses = offeredCourses.getmySize();
    cout << "Code\t"
        << "Title\t\t\t\t"
        << "#Credits\t"
        << "Enrolled\t"
        << "Capacity" << endl;

    offeredCourses.display(cout);
}

void displayRegisteredStudentsWithCourses(
    DoublyLinkedList& RegisteredStudents) {
    for (int i = 0; i < RegisteredStudents.size(); i++) {
        Student* student = RegisteredStudents.at(i);
        student->displayStudentWithCourse(cout);
        cout << endl;
    }
}

void displayCoursesWithRegisteredStudents(LListWithDummyNode& offeredCourses) {
    for (int i = 0; i < offeredCourses.getmySize(); i++) {
        Course* course = offeredCourses.at(i);
        course->displayRegisteredStudents(cout);
    }
}

void displayRegisteredCoursesForStudent(DoublyLinkedList& RegisteredStudents) {
    string id;
    cout << "Enter the student id: ";
    cin >> id;

    Student* student = nullptr;
    for (int i = 0; i < RegisteredStudents.size(); ++i) {
        student = RegisteredStudents.at(i);
        if (student->getid() == id) {
            break;
        }
        student = NULL;
    }

    if (student == NULL) {
        cout << "Student not registered in any courses.\n";
        return;
    }

    student->displayStudentWithCourse(cout);

    cout << endl;
}

void displayStudentsInCourse(LListWithDummyNode& offeredCourses) {
    char code[8]{};
    cout << "Enter the course: ";

    for (int i = 0; i < 7; i++) {
        cin >> code[i];
    }
    code[7] = '\0';

    Course* course = nullptr;
    for (int i = 0; i < offeredCourses.getmySize(); ++i) {
        course = offeredCourses.at(i);

        if (course->getCode() == string(code)) {
            break;
        }

        course = NULL;
    }

    if (course == NULL) {
        cerr << "Course does not exist\n";
        return;
    }
    course->displayRegisteredStudents(cout);
}

void displayStudentInfo(DoublyLinkedList& RegisteredStudents) {
    string id;
    cout << "Enter the student ID: ";
    cin >> id;
    Student s;
    s.setid(id);

    Student* student = nullptr;
    for (int i = 0; i < RegisteredStudents.size(); ++i) {
        student = RegisteredStudents.at(i);

        if (student->getid() == id) {
            break;
        }

        student = NULL;
    }

    if (student == NULL) {
        cerr << "Student not found.\n";
        return;
    }

    cout << "Student : \n\tID: " << student->getid()
        << "\n\tName: " << student->getfirstname() << "," << student->getlastname()
        << "\n\tMajor: " << student->getmajor() << "\n\tGPA: " << student->getGPA();

    cout << endl;
}

void registerStudent(DoublyLinkedList& nonRegisteredStudents,
    DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses) {

    string id;
    cout << "Enter the student ID: ";
    cin >> id;

    Student* student = nullptr;

    for (int i = 0; i < nonRegisteredStudents.size(); ++i) {
        student = nonRegisteredStudents.at(i);

        if (student->getid() == id) {
            break;
        }
        student = NULL;
    }

    int pos = nonRegisteredStudents.search(student);
    bool isRegistered = false;

    if (student == NULL) {
        for (int i = 0; i < RegisteredStudents.size(); ++i) {
            student = RegisteredStudents.at(i);

            if (student->getid() == id) {
                break;
            }

            student = NULL;
        }
        isRegistered = true;
        if (student == NULL) {
            cerr << "Student not found\n";
            return;
        }
    }


    while (true) {

        string code;
        cout << "Enter the course code: ";
        cin >> code;

        Course* course = nullptr;
        for (int i = 0; i < offeredCourses.getmySize(); ++i) {
            course = offeredCourses.at(i);

            if (course->getCode() == code) {
                break;
            }
            course = NULL;
        }
        if (course == NULL) {
            cout << "The course is not offered\n";
            continue;
        }

        course->addStudent(student);
        cout << "Student registerd.\n" << endl;

        cout << "Do you need to add more courses [Y] yes or [N] no: ";

        char choice = 'Y';
        cin >> choice;

        if (choice == 'Y' || choice == 'y') continue;
        if (choice == 'N' || choice == 'n') break;
        cout << "Invalid choice, breaking operation";
        break;
    }

    if (!isRegistered) {
        nonRegisteredStudents.deleteAtPos(pos);

        RegisteredStudents.insertAtEnd(student);
    }
}


void addOrDropStudent(DoublyLinkedList& nonRegisteredStudents, DoublyLinkedList& RegisteredStudents,
    LListWithDummyNode& offeredCourses) {
    string id;
    cout << "Enter the student ID: ";
    cin >> id;

    Student* student = nullptr;
    for (int i = 0; i < nonRegisteredStudents.size(); ++i) {
        student = nonRegisteredStudents.at(i);

        if (student->getid() == id) {
            break;
        }
        student = NULL;
    }

    int pos = nonRegisteredStudents.search(student);
    bool isRegistered = false;

    if (student == NULL) {
        for (int i = 0; i < RegisteredStudents.size(); ++i) {
            student = RegisteredStudents.at(i);

            if (student->getid() == id) {
                break;
            }
            student = NULL;
        }
        isRegistered = true;
        if (student == NULL) {
            cerr << "Student not found\n";
            return;
        }
    }

    while (true) {
        char choice;
        cout << "Add course [A] or Drop course [D]: ";
        cin >> choice;

        if (choice == 'A' || choice == 'a') {
            char code[8];
            cout << "Choose course code: ";
            for (int i = 0; i < 7; ++i) {
                cin >> code[i];
            }
            code[7] = '\0';

            Course* course = nullptr;

            for (int i = 0; i < offeredCourses.getmySize(); ++i) {
                course = offeredCourses.at(i);
                if (course->getCode() == string(code)) {
                    break;
                }
                course = NULL;
            }

            if (course == NULL) {
                cout << "Course not found." << endl;
                cout << "Do you want to continue [Y] yes or [N] no: ";
                cin >> choice;

                if (choice == 'Y' || choice == 'y') {
                    continue;
                }
                else {
                    break;
                }
            }

            course->addStudent(student);
            cout << "Course added successfully." << endl;

            if (!isRegistered) {
                nonRegisteredStudents.deleteAtPos(pos);
                RegisteredStudents.insertAtEnd(student);
            }
        }
        else if (choice == 'D' || choice == 'd') {
            char code[8];
            cout << "Choose course code: ";
            for (int i = 0; i < 7; ++i) {
                cin >> code[i];
            }
            code[7] = '\0';

            Course* course = nullptr;

            for (int i = 0; i < offeredCourses.getmySize(); ++i) {
                course = offeredCourses.at(i);

                if (course->getCode() == string(code)) {
                    break;
                }
                course = NULL;
            }

            if (course == NULL) {
                cout << "Course not found." << endl;
                cout << "Do you want to continue [Y] yes or [N] no: ";
                cin >> choice;

                if (choice == 'Y' || choice == 'y') {
                    continue;
                }
                else {
                    break;
                }
            }

            course->dropStudent(student);
            vector<Course*> registered = student->getregisteredcourse();
            if (registered.empty()) {
                pos = RegisteredStudents.search(student);
                RegisteredStudents.deleteAtPos(pos);

                pos = nonRegisteredStudents.size();
                nonRegisteredStudents.insertAtEnd(student);
                isRegistered = false;
            }
        }

        cout << "Do you want to continue [Y] yes or [N] no: ";
        cin >> choice;

        if (choice == 'N' || choice == 'n') {
            break;
        }
    }

}
