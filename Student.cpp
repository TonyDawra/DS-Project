#include "Student.h"

int Student::nbOfstds=0;

// Default Constructor
Student::Student() : id(""), firstname(""), lastname(""), gpa(0.0) ,reg(false){nbOfstds++;}


// Constructor with all parameters: ID, First Name, Last Name, GPA and registeration status
Student::Student(const string& id="", const string& firstname="", const string& lastname="", double gpa=0.0,bool reg=false) : id(id), firstname(firstname), lastname(lastname), gpa(gpa),reg(reg) {nbOfstds++;}

//Copy Constructor
Student::Student(const Student &other) : Student(other.id, other.firstname, other.lastname, other.gpa,other.reg) {nbOfstds++;}

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


bool Student::isreg()const{
return reg;
}



//setters implementation

void Student::setid(const string& id){
	if(id[0]=='A' || id[0]=='a' && id.size()==8){
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
	if(gpa1<0.0){
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
// Display student information implementation
void Student::display( const Student& student) const {
    cout << student.getid() << "\t"<< student.getlastname()<<", "<<student.getfirstname()<<"\t\t"<<student.getGPA()<<"    "<<student.getAS()<<endl;

}

ostream& operator<<(ostream& out, const Student& student) {
    out << "Id: " << student.getid() << "\n";
    out << "Name: " << student.getfirstname() <<student.getlastname() ;"\n";
    out << "GPA: " << student.getGPA() << "\n";
    return out;
}
