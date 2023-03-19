// To get the results of students by roll no using a member function of student class.
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
int semester,n,sub;
string email;
string addr;
char sub_name[3][20];
float max_mark[],min_mark[],obt_mark[];
float  overallMarks = 0, minMarks = 0;
float percentage = 0;
float total_marks = 0;
float check = 0;

    public:

		// Function to check the character is an alphabet or not
		bool isChar(char c)
		{
			return ((c >= 'a' && c <= 'z')
					|| (c >= 'A' && c <= 'Z'));
		}

		// Function to check the character is an digit or not
		bool isDigit(const char c)
		{
			return (c >= '0' && c <= '9');
		}

		// Function to check email id is valid or not
		bool is_valid(string email)
			{
			// Check the first character is an alphabet or not
			if (!isChar(email[0])) {

				// If it's not an alphabet email id is not valid
				return 0;
			}
			// Variable to store position of At and Dot
			int At = -1, Dot = -1;

			// Traverse over the email id string to find position of Dot and At
			for (int i = 0;
				i < email.length(); i++) {

				// If the character is '@'
				if (email[i] == '@') {

					At = i;
				}

				// If character is '.'
				else if (email[i] == '.') {

					Dot = i;
				}
			}

			// If At or Dot is not present
			if (At == -1 || Dot == -1)
				return 0;

			// If Dot is present before At
			if (At > Dot)
				return 0;

			// If Dot is present at the end
			return !(Dot >= (email.length() - 1));
		}


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

            while(check==0)
			{
			cout<<"Enter E-mail Id: ";
            cin>>email;
			bool ans = is_valid(email);
			if (ans) {
				cout << email << " : "
					<< "valid" << endl;
				check = 1;
			}
			else {
				cout << email << " : "
					<< "invalid! Re enter again" << endl;
				check = 0;
			}}

            cout<<"Enter Address: ";
            cin>>addr;
            cout<<"Enter Roll No: ";
            cin>>rollNo;
            cout<<"Enter Semester: ";
            cin>>semester;
              // Get input for each subject's name and marks

            cout << "Enter the number of subjects to get added: ";
            cin >> sub;
           for (int j = 0; j < sub; j++) {
                cout << "Enter subject " << j + 1 << " name: ";
                cin >> sub_name[j];
                cout << "Enter maximum marks for subject " << j + 1 << ": ";
                cin >> max_mark[j];
                cout << "Enter minimum marks for subject " << j + 1 << ": ";
                cin >> min_mark[j];
                cout << "Enter obtained marks for subject " << j + 1 << ": ";
                cin >> obt_mark[j];

           }
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
     void displayResult(vector<Student>& students) {
         int RollNo;
         char choice;
         cout << "Enter roll number of the student to get the result: ";
         cin >> RollNo;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].rollNo == RollNo) {
                    // Calculate the total marks and percentage for the student
                    for (int j = 0; j < sub ; j++) {
                        total_marks = total_marks + obt_mark[j];
                        //overallMarks = overallMarks + max_mark[j];
                    }
					overallMarks = sub*100;
                    percentage = (total_marks / overallMarks) * 100;

                    // Display the result for the student
                    cout << "Name: " << students[i].name << endl;
                    cout << "Roll Number: " << students[i].rollNo << endl;
                    cout << "Marks Obtained: " << total_marks << endl;
					cout << "Overall Marks: " << overallMarks << endl;
                    cout << "Percentage: " << percentage << "%" << endl;

                    // Break out of the loop since we've found the student
                    break;
                }
                else
                cout<<"Roll no not found";
            }

        }
}; //class ends here


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
        cout << "6. Display Result" << endl;
        cout << "7. Exit" << endl;
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
                s.displayResult(students);   //function to display result by roll no of student
                break;
            case 7:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
    while (choice != 7);
    return 0;
}




