#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Course;

class Student {

public:
    // Default constructor
    Student();

    // Constructor with ID, first name, last name, GPA and registered status
    Student(const string& id, const string& firstname, const string& lastname, double gpa,string major);
    
    //Copy Constructor
    Student(const Student& other);
    //destructor
    virtual~Student();
    // Getters
    string getfirstname() const;
    string getlastname()const;
    string getid() const;
    double getGPA() const;
    string getAS() const;
    bool isreg()const;
    string getmajor()const;
    //setters
    void setfirstname(const string &);
    void setlastname(const string &);
    void setid(const string &);
    void setGPA(double);
    void setAS();
    void setreg(bool);
    void setmajor(string);
    
    
    // Display student information
    void displayall(const Student&) const;
    void display(const Student&) const;

    friend ostream& operator<<(ostream& , const Student&);
    
    
	//course related functions
	void registercourse(Course* );
	void displayregisteredcourses()const;
	void dropcourse(Course*)const;
	
private:
    static int nbOfstds;
    string id;
    string firstname;
    string lastname;
    double gpa;
    bool reg;
    string major;
    string academicstatus;
    //course class data fields
    vector<Course*> registeredcourses;


    
};

#endif 

    
