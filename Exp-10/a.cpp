//• To create course records using files.
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct CourseRecord {
    string name;
    string code;
    string instructor;
    string startDate;
    string endDate;
};

CourseRecord inputCourseRecord() {
    CourseRecord course;
    cout << "Enter course name: ";
    getline(cin, course.name);
    cout << "Enter course code: ";
    getline(cin, course.code);
    cout << "Enter instructor name: ";
    getline(cin, course.instructor);
    cout << "Enter start date: ";
    getline(cin, course.startDate);
    cout << "Enter end date: ";
    getline(cin, course.endDate);
    return course;
}

void writeCourseRecordToFile(const CourseRecord& course, const string& fileName) {
    ofstream outputFile(fileName, ios::app);
    outputFile << course.name << "," << course.code << "," << course.instructor << "," << course.startDate << "," << course.endDate << endl;
    outputFile.close();
}

vector<CourseRecord> readCourseRecordsFromFile(const string& fileName) {
    vector<CourseRecord> courses;
    ifstream inputFile(fileName);
    string line;
    while (getline(inputFile, line)) {
        CourseRecord course;
        size_t pos = 0;
        string token;
        while ((pos = line.find(",")) != string::npos) {
            token = line.substr(0, pos);
            line.erase(0, pos + 1);
            if (course.name.empty()) {
                course.name = token;
            } else if (course.code.empty()) {
                course.code = token;
            } else if (course.instructor.empty()) {
                course.instructor = token;
            } else if (course.startDate.empty()) {
                course.startDate = token;
            } else {
                course.endDate = token;
            }
        }
        courses.push_back(course);
    }
    inputFile.close();
    return courses;
}

int main() {
    CourseRecord course1 = inputCourseRecord();
    writeCourseRecordToFile(course1, "courses.txt");
    vector<CourseRecord> courses = readCourseRecordsFromFile("courses.txt");
    for (const CourseRecord& course : courses) {
        cout << course.name << " (" << course.code << ") - taught by " << course.instructor << " from " << course.startDate << " to " << course.endDate << endl;
    }
    return 0;
}
