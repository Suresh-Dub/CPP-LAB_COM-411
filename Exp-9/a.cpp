//• To edit student records using files. 
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
    // Open the file for reading and writing
    fstream file;
    file.open("students.txt", ios::in | ios::out);

    // Check if file was opened successfully
    if (!file) {
        cout << "Error: Failed to open file" << endl;
        return 1;
    }

    // Search for student record
    int searchRollNo;
    cout << "Enter roll number to search: ";
    cin >> searchRollNo;

    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1+1);

        int rollNo = stoi(line.substr(pos1+1, pos2-pos1-1));

        if (rollNo == searchRollNo) {
            Student s;

            s.name = line.substr(0, pos1);
            s.rollNo = rollNo;
            s.marks = stof(line.substr(pos2+1));

            // Prompt user to enter new student details
            cout << "Enter new name: ";
            cin >> s.name;
            cout << "Enter new roll number: ";
            cin >> s.rollNo;
            cout << "Enter new marks: ";
            cin >> s.marks;

            // Update student record in file
            file.seekp(file.tellg() - line.length() - 1); // Move file pointer to beginning of line
            file << s.name << "," << s.rollNo << "," << s.marks; // Write new student record to file

            cout << "Student record updated successfully" << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student record not found" << endl;
    }

    // Close the file stream
    file.close();

    return 0;
}
