//• To search student records using files. 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define a student structure
struct Student {
    string name;
    int rollNo;
    float marks;
};

int main() {
    // Open the file for reading
    ifstream inFile;
    inFile.open("students.txt");

    // Check if file was opened successfully
    if (!inFile) {
        cout << "Error: Failed to open file" << endl;
        return 1;
    }

    // Search for student record
    int searchRollNo;
    cout << "Enter roll number to search: ";
    cin >> searchRollNo;

    string line;
    bool found = false;

    while (getline(inFile, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1+1);

        int rollNo = stoi(line.substr(pos1+1, pos2-pos1-1));

        if (rollNo == searchRollNo) {
            Student s;

            s.name = line.substr(0, pos1);
            s.rollNo = rollNo;
            s.marks = stof(line.substr(pos2+1));

            cout << "Student record found:" << endl;
            cout << "Name: " << s.name << ", Roll No: " << s.rollNo << ", Marks: " << s.marks << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student record not found" << endl;
    }

    // Close the file stream
    inFile.close();

    return 0;
}


