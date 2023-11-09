#include "Student.h"
#include "Course.h"
int Student::nbOfstds=0;

// Default Constructor
Student::Student() : id(""), firstname(""), lastname(""), gpa(0.0) ,major(""){nbOfstds++;}


// Constructor with all parameters: ID, First Name, Last Name, GPA, and Major
Student::Student(const string& id="", const string& firstname="", const string& lastname="", double gpa=0.0, string major="") : id(id), firstname(firstname), lastname(lastname), gpa(gpa),major(major) {nbOfstds++;}

//Copy Constructor
Student::Student(const Student &other) : Student(other.id, other.firstname, other.lastname, other.gpa,other.major) {nbOfstds++;}

//Destructor
Student::~Student(){
    for (int i = 0; i < registeredcourses.size(); ++i) {
        delete registeredcourses[i]; 
    }
}
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
    if (this->gpa < 2) {
        return "Probation";
    } 
        return "Regular";
    }

bool Student::isreg()const{
return reg;
}

string Student::getmajor()const{
return major;
}


//setters implementation

void Student::setid(const string& id){
	if(id[0]=='A' || id[0]=='a' && id.size()==8){//checking if the id is format is valid starting with A and has 8 characters
	this->id=id;
	}
	else cerr<<"invalid id";
	}
	
void Student::setfirstname(const string& firstname){
	this->firstname=firstname;
}

void Student::setlastname(const string& lastname){
	this->lastname=lastname;
}
void Student::setGPA(double gpa1){
	if(gpa1<0.0){//check if gpa is valid
	gpa=0.0;}
	else if(gpa1>4.0){
		gpa=4.0;
	}
	else this->gpa=gpa1;
	setAS();
}

void Student::setAS(){
    if (gpa < 2) {
        this->academicstatus="probation";
    } 
        this->academicstatus="regular";
}

void Student::setreg(bool choice){
	this->reg=choice;
}

void Student::setmajor(string maj){
	this->major=maj;
}

// Display student information implementation
void Student::displayall( const Student& student) const {
    cout << student.getid() << "\t"<< student.getlastname()<<", "<<student.getfirstname()<<"\t\t"<<student.getGPA()<<"    "<<student.getAS()<<endl;
}
void Student::display( const Student& student)const{
	cout << student.getid() <<"  "<< student.getlastname()<<","<<student.getfirstname();
}

ostream& operator<<(ostream& out, const Student& student) {
    out << "Id: " << student.getid() << "\n";
    out << "Name: " << student.getfirstname() <<student.getlastname() ;"\n";
    out << "GPA: " << student.getGPA() << "\n";
    return out;
}


//course related functions
void Student::registercourse(Course* course) {
    registeredcourses.push_back(course);
}

void Student::displayregisteredcourses() const {
    for (int i = 0; i < registeredcourses.size(); ++i) {
        cout << "- " << registeredcourses[i]->getcourseName() << endl;
    }
}

void Student::dropcourse(Course* course) {
    auto it = find(registeredcourses.begin(), registeredcourses.end(), course);
    if (it != registeredcourses.end()) {
        registeredcourses.erase(it);
        cout<<"Course dropped successfully"<<endl;
		}
     else {
        cout << "Course not found." << endl;
    }
}
