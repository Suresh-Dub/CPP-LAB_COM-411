//To delete the details of a student using a member function of student class.

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

int main() {
    vector<Student> students;
    Student s;     // class student object is created
    int choice;
    do {                   // To display the main menu options
        cout<<"\n\t               Student Management System "<<endl;
        cout<<"\n --------------------------------------------------------------"<<endl;
        cout << "1. Add Student Details" << endl;
        cout << "2. Update Student Details" << endl;
        cout << "3. Delete Student Details" << endl;
        cout << "4. Search for student" << endl;
        cout << "5. Display all students" << endl;
        cout << "6. Exit" << endl;
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
                s.searchStudent(students);     //function to search student details
                break;
            case 5:
                s.displayStudents(students);   //function to display all student details
                break;
            case 6:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);
    return 0;
}



