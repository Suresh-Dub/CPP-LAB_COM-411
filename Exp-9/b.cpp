//• To delete student records using files.



#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    cout << "Enter roll number to delete: ";
    cin >> searchRollNo;

    vector<string> lines;
    string line;
    bool found = false;

    while (getline(file, line)) {
        size_t pos1 = line.find(",");
        size_t pos2 = line.find(",", pos1+1);

        int rollNo = stoi(line.substr(pos1+1, pos2-pos1-1));

        if (rollNo == searchRollNo) {
            found = true;
            continue;
        }

        lines.push_back(line);
    }

    // Clear the file contents
    file.close();
    file.open("students.txt", ios::out | ios::trunc);

    // Write the remaining student records back to the file
    for (string& l : lines) {
        file << l << endl;
    }

    if (found) {
        cout << "Student record deleted successfully" << endl;
    } else {
        cout << "Student record not found" << endl;
    }

    // Close the file stream
    file.close();

    return 0;
}
