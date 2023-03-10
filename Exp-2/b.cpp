// To add the details of a student using a parameterized constructor of student class.
#include <iostream>
#include <string>
using namespace std;
// creating a class
class Student {
 private:
  std::string name;
  int roll_no,dd, mm, yy, subject;
  std::string father_name;
  std::string phne_no;
  std::string semester;

 public://Access Modifier
    //Entering details through Parameterized Constructor
  Student(std::string n, std::string fn, std::string p, int r, int d, int m, int y, int sub, std::string sem)
  {                                                                          
    name = n;
    father_name = fn;
    phne_no = p;
    roll_no = r;
    dd = d;
    mm = m;
    yy = y;
    subject = sub;
    semester = sem;

  }

  void display()                //Member Function for displaying the data
   {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Father Name: " << father_name << std::endl;
    std::cout << "Phone Number: " << phne_no << std::endl;
    std::cout << "Date of Birth: " <<dd<<" - "<<mm<<" - "<<yy << std::endl;
    std::cout << "Roll No: " << roll_no << std::endl;
    std::cout << "Semester: " << semester << std::endl;
    std::cout << "Number of Subjects: " << subject << std::endl;

  }
};  //Class ends here

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student *students[n];  // object of a student class is creating

  for (int i = 0; i < n; i++) {
  std::string name;
  int roll_no, dd, mm, yy, subject ;
  std::string father_name;
  std::string phne_no;
  std::string semester;

  std::cout << "Enter the name of the student: ";
  std::cin >> name;

  std::cout << "Enter Father Name: ";
  std::cin >> father_name;

  std::cout << "Enter Phone Number: ";
  std::cin >> phne_no;

  std::cout << "Enter Date of Birth: ";
  std::cin >> dd>>mm>>yy;

  std::cout << "Enter the roll number of the student: ";
  std::cin >> roll_no;

  std::cout << "Enter Semester: ";
  std::cin >> semester;

  std::cout << "Enter the Number of Subjects: ";
  std::cin >> subject;

  students[i] = new Student(name, father_name, phne_no, roll_no, dd, mm, yy, subject, semester);
    }

  cout << "Details of students:" << endl;
    for (int i = 0; i < n; i++) {
        students[i]->display();
    }

  return 0;
}
