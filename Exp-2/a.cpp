// To allocate appropriate access specifiers to data members of student and course class along with justification in comments.
#include<iostream>
using namespace std;
// Creation of a class name student
class student
{
//Main feature of Oops is data hiding which refers to restricting access to data members of a class. This is to prevent other functions and classes from tampering with the class data. Declaring the data members of student class are hidden using private keyword
private:
//Here all the data members are private
    int rollno;
    char name[50];
    int eng_marks, math_marks, sci_marks, lang2_marks, cs_marks;
    double average;
    char grade;
 public:
// the member functions are made accessible using the public keyword.
     student ();                            // Creation of Constructor
    ~student();                           //Destructor
    void getdata();                    // Declaration of Member function to insert data
    void showdata() const;       // Declaration of Member function to display data
    void calculate();                 // Declaration of Member function for calulating marks
    int retrollno() const;
};
//class ends here


// Creation of a course class
class Course 
{
// Declaring the data members of course class are hidden using private keyword and accessed only by public class
  private:
  string course_name;
  string course_ID;
  int semester;
  string coursetype;
// the member functions are made accessible using the public keyword.
 public:
     course ();                            // Creation of Constructor
    ~course();                           //Destructor
    void getdata();                    // Declaration of Member function to insert data
    void showdata();       // Declaration of Member function to display data
    void calculate();                 // Declaration of Member function for calulating marks
};
