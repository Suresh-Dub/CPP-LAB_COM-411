//• To search records by course id using files.
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

vector<CourseRecord> searchCourseRecordsByCode(const string& fileName, const string& courseCode) {
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
        if (course.code == courseCode) {
            courses.push_back(course);
        }
    }
    inputFile.close();
    return courses;
}

void printCourseRecords(const vector<CourseRecord>& courses) {
    for (const CourseRecord& course : courses) {
        cout << course.name << " (" << course.code << ") - taught by " << course.instructor << " from " << course.startDate << " to " << course.endDate << endl;
    }
}

int main() {
    vector<CourseRecord> courses = readCourseRecordsFromFile("courses.txt");

    string searchCode;
    cout << "Enter course code to search: ";
    cin >> searchCode;

    vector<CourseRecord> searchResults = searchCourseRecordsByCode("courses.txt", searchCode);

    if (searchResults.empty()) {
        cout << "No results found." << endl;
    } else {
        cout << "Results:" << endl;
        printCourseRecords(searchResults);
    }

    return 0;
}
