//• To make use of function templates to search a student by name or roll number.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    int age;
};

template <typename T>
int search(const vector<Student>& students, T key, bool (*comparator)(const Student&, T)) {
    for (int i = 0; i < students.size(); i++) {
        if (comparator(students[i], key)) {
            return i;
        }
    }
    return -1;
}

bool compareName(const Student& student, const string& name) {
    return student.name == name;
}

bool compareRollNumber(const Student& student, int rollNumber) {
    return student.rollNumber == rollNumber;
}

int main() {
    vector<Student> students = {
        { "Alice", 1001, 20 },
        { "Bob", 1002, 21 },
        { "Charlie", 1003, 19 },
        { "Dave", 1004, 22 }
    };

    cout << "Choose an option:" << endl;
    cout << "1. Search by name" << endl;
    cout << "2. Search by roll number" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            string name;
            cout << "Enter name to search for: ";
            cin >> name;
            int index = search(students, name, compareName);
            if (index != -1) {
                cout << "Student " << students[index].name << " found with roll number " << students[index].rollNumber << " and age " << students[index].age << endl;
            } else {
                cout << "No student found with name " << name << endl;
            }
            break;
        }
        case 2: {
            int rollNumber;
            cout << "Enter roll number to search for: ";
            cin >> rollNumber;
            int index = search(students, rollNumber, compareRollNumber);
            if (index != -1) {
                cout << "Student " << students[index].name << " found with roll number " << students[index].rollNumber << " and age " << students[index].age << endl;
            } else {
                cout << "No student found with roll number " << rollNumber << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}
