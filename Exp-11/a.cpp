// To edit course records using files.

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct CourseRecord {
    string name;
    string code;
    string instructor;
    string startDate;
    string endDate;
};

vector<CourseRecord> readCourseRecordsFromFile(const string& fileName) {
    vector<CourseRecord> courses;
    ifstream inputFile(fileName);
    string line;
    while (getline(inputFile, line)) {
        CourseRecord course;
        stringstream ss(line);
        getline(ss, course.name, ',');
        getline(ss, course.code, ',');
        getline(ss, course.instructor, ',');
        getline(ss, course.startDate, ',');
        getline(ss, course.endDate, ',');
        courses.push_back(course);
    }
    inputFile.close();
    return courses;
}

void writeCourseRecordsToFile(const string& fileName, const vector<CourseRecord>& courses) {
    ofstream outputFile(fileName);
    for (const CourseRecord& course : courses) {
        outputFile << course.name << "," << course.code << "," << course.instructor << "," << course.startDate << "," << course.endDate << endl;
    }
    outputFile.close();
}

void printCourseRecords(const vector<CourseRecord>& courses) {
    for (const CourseRecord& course : courses) {
        cout << course.name << " (" << course.code << ") - taught by " << course.instructor << " from " << course.startDate << " to " << course.endDate << endl;
    }
}

void editCourseRecord(vector<CourseRecord>& courses) {
    string searchCode;
    cout << "Enter course code to edit: ";
    cin >> searchCode;

    for (CourseRecord& course : courses) {
        if (course.code == searchCode) {
            string newName, newCode, newInstructor, newStartDate, newEndDate;
            cout << "Enter new course name: ";
            cin.ignore(); // Ignore newline left in stream from previous input
            getline(cin, newName);
            cout << "Enter new course code: ";
            getline(cin, newCode);
            cout << "Enter new instructor name: ";
            getline(cin, newInstructor);
            cout << "Enter new start date: ";
            getline(cin, newStartDate);
            cout << "Enter new end date: ";
            getline(cin, newEndDate);

            course.name = newName;
            course.code = newCode;
            course.instructor = newInstructor;
            course.startDate = newStartDate;
            course.endDate = newEndDate;

            cout << "Course record updated." << endl;
            return;
        }
    }

    cout << "No course found with code " << searchCode << endl;
}

int main() {
    vector<CourseRecord> courses = readCourseRecordsFromFile("courses.txt");

    cout << "Welcome to the course record editor." << endl;
    cout << "Choose an option:" << endl;
    cout << "1. View course records" << endl;
    cout << "2. Edit course record" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            printCourseRecords(courses);
            break;
        case 2:
            editCourseRecord(courses);
            writeCourseRecordsToFile("courses.txt", courses);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}
