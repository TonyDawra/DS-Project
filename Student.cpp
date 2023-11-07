#include "Student.h"

int Student::nbOfstds=0;

// Default Constructor
Student::Student() : id(""), firstname(""), lastname(""), gpa(0.0) {nbOfstds++;}


// Constructor with all parameters: ID, First Name, Last Name, GPA
Student::Student(const string& id="", const string& firstname="", const string& lastname="", double gpa=0.0) : id(id), firstname(firstname), lastname(lastname), gpa(gpa) {nbOfstds++;}

//Copy Constructor
Student::Student(const Student &other) : Student(other.id, other.firstname, other.lastname, other.gpa) {nbOfstds++;}

// Getter implementations
string Student::getid() const {
    return id;
}

string Student::getfirstname() const {
    return firstname;
}
string Student::getlastname()const{
    return lastname;
}

double Student::getGPA() const {
    return gpa;
}

string Student::getAS() const {
    if (gpa < 2) {
        return "Probation";
    } 
        return "Regular";
    }





//setters implementation

void Student::setid(const string& id){
	this->id=id;
}


void Student::setfirstname(const string& firstname){
	this->firstname=firstname;
}

void Student::setlastname(const string& lastname){
	this->lastname=lastname;
}
void Student::setGPA(double gpa){
	this->gpa=gpa;
	setAS();
}

void Student::setAS(){
    if (gpa < 2) {
        this->academicstatus="probation";
    } 
        this->academicstatus="regular";
}

// Display student information implementation
void Student::display() const {
    cout << "Id: " << getid() << "\n";
    cout << "Name: " << getfirstname() <<getlastname() ;"\n";
    cout << "GPA: " << getGPA() << "\n"; 
}

ostream& operator<<(ostream& out, const Student& student) {
    out << "Id: " << student.getid() << "\n";
    out << "Name: " << student.getfirstname() <<student.getlastname() ;"\n";
    out << "GPA: " << student.getGPA() << "\n";
    return out;
}
