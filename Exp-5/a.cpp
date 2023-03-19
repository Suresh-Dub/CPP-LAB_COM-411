//Activity 5 To add the details of a course using a parameterized constructor of course class.
#include <iostream>
#include <string>
using namespace std;

class Course {
 private:                        // Data members of class course
  std::string course_name;
  std::string course_ID;
  std::string semester;


 public:
  Course(std::string id, std::string n, std::string sem)
  {                                                          //Parameterized Constructor to add the details of course
    semester = sem;
    course_ID = id;
    course_name = n;
  }

  void display()                                         //Member Function to display the details
   {
    std::cout << "\nSemester: " << semester << std::endl;
    std::cout << "Course ID: " << course_ID << std::endl;
    std::cout << "Course Name: " << course_name << std::endl;
  }
};

int main() {
    int n;
    std::string semester;
    cout << "Enter the Semester: ";
    cin >> semester;
    cout << "Enter the number of Subjects: ";
    cin >> n;

    Course*courses[n];
  for (int i = 0; i < n; i++) {
  std::string course_name;
  std::string course_ID;

  std::cout << "\nCourse ID: " ;
  std::cin>> course_ID;

  std::cout << "Course Name: ";
  std::cin>>course_name;

  courses[i] = new Course(course_ID, course_name, semester);
    }

  cout << "\nDetails of course:" << endl;
    for (int i = 0; i < n; i++) {
        courses[i]->display();
    }

  return 0;
}

OUTPUT



