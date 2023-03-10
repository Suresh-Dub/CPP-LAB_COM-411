//• To store student records in persistent storage i.e. files. in cpp


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
    // Create a file stream object to write student records to a file
    ofstream outFile;
    outFile.open("students.txt");

    // Check if file was opened successfully
    if (!outFile) {
        cout << "Error: Failed to create file" << endl;
        return 1;
    }

    // Get student details from user and write to file
    int numStudents;
    cout << "Enter number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        Student s;

        cout << "Enter name of student " << i+1 << ": ";
        cin >> s.name;

        cout << "Enter roll number of student " << i+1 << ": ";
        cin >> s.rollNo;

        cout << "Enter marks of student " << i+1 << ": ";
        cin >> s.marks;

        // Write student record to file
        outFile << s.name << "," << s.rollNo << "," << s.marks << endl;
    }

    // Close the file stream
    outFile.close();

    // Open the file for reading and display the student records
    ifstream inFile;
    inFile.open("students.txt");

    // Check if file was opened successfully
    if (!inFile) {
        cout << "Error: Failed to open file" << endl;
        return 1;
    }

    // Read and display student records from file
    string line;
    cout << "\nStudent Records:" << endl;

    while (getline(inFile, line)) {
        Student s;
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1+1);

        s.name = line.substr(0, pos1);
        s.rollNo = stoi(line.substr(pos1+1, pos2-pos1-1));
        s.marks = stof(line.substr(pos2+1));

        cout << "Name: " << s.name << ", Roll No: " << s.rollNo << ", Marks: " << s.marks << endl;
    }

    // Close the file stream
    inFile.close();

    return 0;
}
