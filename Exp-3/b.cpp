//To delete the details of a student using a member function of student class.
#include <iostream>
#include <vector>
using namespace std;
//student class is created
class Student {
private: // private data members are declared
string name;
string fatherName;
string phoneNumber;
int rollNo;
string dateOfBirth;
int semester,n;
string email;
string addr;
public:
    void addStudent(vector<Student>& students)
    /*declares a reference to a vector of Student objects.
    The vector container is a part of the C++ Standard Template Library (STL)
    and provides a dynamic array-like data structure that can be resized and reallocated in memory as needed.
    By declaring a reference to a vector of Student objects,
    we can modify the vector from within a function without having to pass the vector by value,
    which can be expensive in terms of memory usage and copying overhead.*/
    {
            cout << "Enter the number of students to get added: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
            cout <<"\n Enter student name: ";
            cin >> name;
            cout << "\n Enter father's name: ";
            cin >> fatherName;
            cout<<"\n Enter Contact number: ";
            cin>>phoneNumber;
            cout<<" \nEnter Date Of Birth:";
            cin>>dateOfBirth;
            cout<<"\n Enter E-mail Id: ";
            cin>>email;
            cout<<"\n Enter Address: ";
            cin>>addr;
            cout<<"\n Enter Roll No: ";
            cin>>rollNo;
            cout<<"\n Enter Semester: ";
            cin>>semester;
            students.push_back(*this);
            }
    }
        void updateStudent(vector<Student>& students)  //member function for data updating using roll no
         {
            int updateRollNo;
            cout <<"Enter roll number of the student to be updated: ";
            cin >> updateRollNo;
            for (int i = 0; i < students.size(); i++) {
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
        void deleteStudent(vector<Student>& students) // member function which deletes the data of a specific student
        {
            int deleteRollNo;
            cout << "Enter roll number of the student to be deleted: ";
            cin >> deleteRollNo;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].rollNo == deleteRollNo) {
                    students.erase(students.begin() + i);
                }
            }
        }
        void displayStudents(vector<Student>& students) {
            cout << "Name\tFather's Name\t Contact Number\t Date of Birth\t Email ID\t Address\t Roll Number\t Semester\t\n";
            for (int i = 0; i < students.size(); i++) {
                cout << students[i].name << "\t" << students[i].fatherName << "\t\t" << students[i].phoneNumber << "\t\t" << students[i].dateOfBirth <<"\t\t" <<students[i].email <<"\t\t" <<students[i].addr << "\t\t" << students[i].rollNo<< "\t\t" << students[i].semester<< endl;
            }
        }
};

int main() {
    vector<Student> students;
    Student s;
    int choice;
    do {
        cout<<"\n\t               Model Institute of Engineering"<<endl;
        cout<<"\n_____________________________________________________________________________"<<endl;
        cout << "1. Add student" << endl;
        cout << "2. Update student" << endl;
        cout << "3. Delete student" << endl;
        cout << "4. Display all students" << endl;
        cout << "5. Exit" << endl;
        cout << "\n Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                s.addStudent(students);
                break;
            case 2:
                s.updateStudent(students);
                break;
            case 3:
                s.deleteStudent(students);
                break;
            case 4:
                s.displayStudents(students);
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);
    return 0;
}
