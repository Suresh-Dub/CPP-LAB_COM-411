//Activity 6 To get the details of a course by course_id using a member function of course class
//Declaration of header files
#include <iostream>
#include <vector>
using namespace std;

/* Class Definitions */
class Student {
    private:                        // Data Members declaration
string name;
string fatherName;
string phoneNumber;
int rollNo;
string dateOfBirth;
int semester,n;
string email;
string addr;


    public:
        void addStudent(vector<Student>& students)            //Member function to insert student details
        {
            cout << "Enter the number of students to get added: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
            cout <<"\nEnter student name: ";
            cin >> name;
            cout <<"Enter father's name: ";
            cin >> fatherName;
            cout<<"Enter Contact number: ";
            cin>>phoneNumber;
            cout<<"Enter Date Of Birth:";
            cin>>dateOfBirth;
            cout<<"Enter E-mail Id: ";
            cin>>email;
            cout<<"Enter Address: ";
            cin>>addr;
            cout<<"Enter Roll No: ";
            cin>>rollNo;
            cout<<"Enter Semester: ";
            cin>>semester;
            students.push_back(*this);
            }
        }
        void updateStudent(vector<Student>& students) {   //Member function to Modify student details
            int updateRollNo;
            cout <<"Enter roll number of the student to be updated: ";
            cin >> updateRollNo;
            for (int i = 0; i < students.size(); i++) {     //modifying the details by entering roll number
                if (students[i].rollNo == updateRollNo) {
                    cout << "Enter updated student name: ";
                    cin >> students[i].name;
                    cout << "Enter updated father's name: ";
                    cin >> students[i].fatherName;
                    cout << "Enter updated contact number: ";
                    cin >> students[i].phoneNumber;
                    cout << "Enter updated date of birth : ";
                    cin >> students[i].dateOfBirth;
                    cout << "Enter updated email : ";
                    cin >> students[i].email;
                    cout << "Enter updated address : ";
                    cin >> students[i].addr;
                    cout << "Enter updated semester : ";
                    cin >> students[i].semester;

                }
            }
        }

         void searchStudent(vector<Student>& students) {   //Member function to search student details
            int searchRollNo;
            cout << "Enter roll number of the student to be searched: ";
            cin >> searchRollNo;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].rollNo == searchRollNo) {
                    cout << "Name: " << students[i].name << endl;
                    cout << "Father's Name: " << students[i].fatherName << endl;
                    cout << "Enter updated contact number: "<<students[i].phoneNumber << endl;
                    cout << "Enter updated date of birth : "<<students[i].dateOfBirth << endl;
                    cout << "Enter updated email : " << students[i].email << endl;
                    cout << "Enter updated address : " << students[i].addr << endl;
                    cout << "Roll Number: " << students[i].rollNo << endl;
                    cout << "Enter updated semester : " << students[i].semester << endl;
                }
            }
        }

        void deleteStudent(vector<Student>& students) {      //Member function to delete student record
            int deleteRollNo;
            cout << "Enter roll number of the student to be deleted: ";
            cin >> deleteRollNo;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].rollNo == deleteRollNo) {
                    students.erase(students.begin() + i);
                }
            }
        }
        void displayStudents(vector<Student>& students)    //Member function to display all student details
        {
            cout << "Name\tFather's Name\t Contact Number\t Date of Birth\t Email ID\t Address\t Roll Number\t Semester\t\n";
            for (int i = 0; i < students.size(); i++) {
                cout << students[i].name << "\t" << students[i].fatherName << "\t\t" << students[i].phoneNumber << "\t\t" << students[i].dateOfBirth <<"\t\t" <<students[i].email <<"\t\t" <<students[i].addr << "\t\t" << students[i].rollNo<< "\t\t" << students[i].semester<< endl;
            }
        }
};

class Course
{
    private:
     string semester;
     string course_ID;
     string course_name;
     string instructor;
     int n;

    public:

    void addcourse(vector<Course>& courses) {     //Member function to insert student details
    cout << "Enter the semester: ";
    cin >> semester;
    cout << "Enter the number of subjects: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter course ID: ";
        cin >> course_ID;
        cout << "Enter course name: ";
        cin >> course_name;
        cout << "Name of the instructor: ";
        cin >> instructor;
        courses.push_back(*this);
    }
}

    void updatecourse(vector<Course>& courses) {    //Member function to Update the course details
    cout << "Enter semester to update the details: ";
    cin >> semester;
    for (int i = 0; i < courses.size(); i++) {           //modifying the details according to semester
        if (courses[i].semester == semester) {
            cout << "Enter updated Course name: ";
            cin >> courses[i].course_name;
            cout << "Enter updated Course ID: ";
            cin >> courses[i].course_ID;
            cout << "Enter updated Name of the instructor: ";
            cin >> courses[i].instructor;
        }
    }
}
       void deleteCourse(vector<Course>& courses) {
       string deleteCourseID;
       cout << "Enter course ID of the course to be deleted: ";
       cin >> deleteCourseID;
       for (int i = 0; i < courses.size(); i++) {
        if (courses[i].course_ID == deleteCourseID) {
            courses.erase(courses.begin() + i);
        }
    }
        cout<<"Course deleted successfully";
}

    void searchCourse(vector<Course>& courses) {
    string searchCourseID;
    cout << "Enter course ID to search for: ";
    cin >> searchCourseID;
    for (int i = 0; i < courses.size(); i++) {
        if (courses[i].course_ID == searchCourseID) {
            cout << "Course ID: " << courses[i].course_ID << endl;
            cout << "Course Name: " << courses[i].course_name << endl;
            cout << "Semester: " << courses[i].semester << endl;
            cout << "Instructor: " << courses[i].instructor << endl;
            return;
        }
    }
    cout << "Course not found." << endl;
}

            void displaycourse(vector<Course>& courses) {
            string semester;
            cout << "Enter the semester to display courses: ";
            cin >> semester;
            cout << "Courses for semester " << semester << ":" << endl;
            for (int i = 0; i < courses.size(); i++) {
                if (courses[i].semester == semester) {
                    cout << "Course ID: " << courses[i].course_ID << endl;
                    cout << "Course Name: " << courses[i].course_name << endl;
                    cout << "Instructor: " << courses[i].instructor << endl;
                    cout << endl;
                }
            }
        }
};
int main() {
    vector<Student> students;
    Student s;
    vector<Course> courses;   // class student object is created
    Course c;
    int choice;
    do {                   // To display the main menu options
        cout<<"\n\t               Student Management System "<<endl;
        cout<<"\n --------------------------------------------------------------"<<endl;
        cout << "1. Add Student Details" << "\t\t" <<    "6. To add Course details:" <<endl;
        cout << "2. Update Student Details"<<"\t"<< "7. To Update Course details:" <<endl;
        cout << "3. Delete Student Details"<<"\t"<< "8. To Display Course details:" <<endl;
        cout << "4. Search for student" << "\t\t" <<     "9. To Delete Course details:" <<endl;
        cout << "5. Display all students" << "\t\t"  "10. To search Course details:" <<endl;
        cout << "\t\t\t\t"      "11. Exit" << endl;
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                s.addStudent(students);     //function to insert student details
                break;
            case 2:
                s.updateStudent(students);    //function to update student details
                break;
            case 3:
                s.deleteStudent(students);    //function to delete student details
                break;
            case 4:
                s.searchStudent(students);     //function call to search student details
                break;
            case 5:
                s.displayStudents(students);   //function call to display all student details
                break;
            case 6:
                c.addcourse(courses);          //function call to insert course details
                break;
            case 7:
                c.updatecourse(courses);       //function call to modify the course details
                break;
            case 8:
                c.displaycourse(courses);      //function call to display the course details
                break;
            case 9:
                c.deleteCourse(courses);       //function to delete the course details
                break;
            case 10:
                c.searchCourse(courses);       //function to delete the course details
                break;
            case 11:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 11);
    return 0;
}




