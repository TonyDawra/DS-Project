#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;

class Student {

public:
    // Default constructor
    Student();


    // Constructor with ID, first name, last name, GPA and registeration status
    Student(const string& id, const string& firstname, const string& lastname, double gpa,bool reg);
    
    //Copy Constructor
    Student(const Student& other);
    
    // Getters
    string getfirstname() const;
    string getlastname()const;
    string getid() const;
    double getGPA() const;
    string getAS() const;
    bool isreg()const;
    
    //setters
    void setfirstname(const string &);
    void setlastname(const string &);
    void setid(const string &);
    void setGPA(double);
    void setAS();
    void setreg(bool);
    
    // Display student information
    void display(const Student&) const;

    friend ostream& operator<<(ostream& , const Student&);

private:
    static int nbOfstds;
    string id;
    string firstname;
    string lastname;
    double gpa;
    bool reg;
    

    
};

#endif // STUDENT_H
