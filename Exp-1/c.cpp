To create a course class, its constructor, destructor and member functions
#include<iostream>
using namespace std;
// Creation of a class course
class course
{
// declaring data members
int credits; 
char course_name[50];
char course_code[50];
     public:
     course ();                                                       //Constructor
    ~course();                                                      //Destructor
    void getdata();
    void showdata() const;
    //void calculate();
    };
//class ends here
course :: course()
{
        cout<<"\nThis is Course Details constructor called..........."<<endl;
}
void course::getdata()        // member function to get user input
{
    cout<<"Enter the Course Code: ";
    cin>>course_code;
    cout<<"Enter Course name: ";
    cin.ignore();
    cin.getline(course_name,50);
    cout<<"Enter credits:";
    cin>>credits;
}
void course::showdata() const      // member function to display the information
{
    cout<<"\nCourse Code: "<<course_code;
    cout<<"\nCourse Name : "<<course_name;
    cout<<"\nCredits : "<<credits;
}
course :: ~course()
{
        cout<<"\n\nStudent Detail is Closed.............\n";
}
int main()
{
    course c;                 // Creating the object of a class course
    c.getdata ();
    c.showdata ();
   return 0;
}
