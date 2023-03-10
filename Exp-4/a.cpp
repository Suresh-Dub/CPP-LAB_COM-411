#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int roll_no;
    int marks;

    // Constructor
    Student(string n, int r, int m) {
        name = n;
        roll_no = r;
        marks = m;
    }

    // Member function to search student by roll no
    void searchStudent(int r) {
        if (roll_no == r) {
            cout << "Name: " << name << endl;
            cout << "Roll No: " << roll_no << endl;
            cout << "Marks: " << marks << endl;
        }
        else {
            cout << "No student found with Roll No: " << r << endl;
        }
    }
};

int main() {
    // Create array of student objects
    Student students[] = {
        Student("John", 101, 80),
        Student("Alice", 102, 90),
        Student("Bob", 103, 70),
        Student("Emma", 104, 85),
        Student("Chris", 105, 95)
    };

    // Search for student by roll no
    int search_roll_no;
    cout << "Enter Roll No to search: ";
    cin >> search_roll_no;

    for (int i = 0; i < 5; i++) {
        students[i].searchStudent(search_roll_no);
    }

    return 0;
}

