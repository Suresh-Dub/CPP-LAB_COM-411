//• To delete course records using files.
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

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

void deleteCourseRecord(vector<CourseRecord>& courses) {
    string searchCode;
    cout << "Enter course code to delete: ";
    cin >> searchCode;

    auto it = find_if(courses.begin(), courses.end(), [&](const CourseRecord& course){ return course.code == searchCode; });

    if (it != courses.end()) {
        courses.erase(it);
        cout << "Course record with code " << searchCode << " deleted." << endl;
    } else {
        cout << "No course found with code " << searchCode << endl;
    }
}

int main() {
    vector<CourseRecord> courses = readCourseRecordsFromFile("courses.txt");

    cout << "Welcome to the course record editor." << endl;
    cout << "Choose an option:" << endl;
    cout << "1. View course records" << endl;
    cout << "2. Delete course record" << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            printCourseRecords(courses);
            break;
        case 2:
            deleteCourseRecord(courses);
            writeCourseRecordsToFile("courses.txt", courses);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}
