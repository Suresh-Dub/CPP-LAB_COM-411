//• To update all the input methods in student and course classes with validations using try-catch.

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Student {
public:
    Student() {}
    Student(int rollNumber, const string& name, int age) : rollNumber(rollNumber), name(name), age(age) {}

    int getRollNumber() const { return rollNumber; }
    void setRollNumber(int rollNumber) { this->rollNumber = rollNumber; }

    const string& getName() const { return name; }
    void setName(const string& name) { this->name = name; }

    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }

    void readData() {
        cout << "Enter roll number: ";
        cin >> rollNumber;

        cout << "Enter name: ";
        cin >> name;
        if (name.length() == 0) {
            throw runtime_error("Name cannot be empty.");
        }

        cout << "Enter age: ";
        cin >> age;
        if (age <= 0) {
            throw runtime_error("Age must be a positive integer.");
        }
    }

    void displayData() const {
        cout << "Roll number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

private:
    int rollNumber;
    string name;
    int age;
};

class Course {
public:
    Course() {}
    Course(int courseId, const string& courseName, int credits) : courseId(courseId), courseName(courseName), credits(credits) {}

    int getCourseId() const { return courseId; }
    void setCourseId(int courseId) { this->courseId = courseId; }

    const string& getCourseName() const { return courseName; }
    void setCourseName(const string& courseName) { this->courseName = courseName; }

    int getCredits() const { return credits; }
    void setCredits(int credits) { this->credits = credits; }

    void readData() {
        cout << "Enter course ID: ";
        cin >> courseId;
        if (courseId <= 0) {
            throw runtime_error("Course ID must be a positive integer.");
        }

        cout << "Enter course name: ";
        cin >> courseName;
        if (courseName.length() == 0) {
            throw runtime_error("Course name cannot be empty.");
        }

        cout << "Enter credits: ";
        cin >> credits;
        if (credits <= 0) {
            throw runtime_error("Credits must be a positive integer.");
        }
    }

    void displayData() const {
        cout << "Course ID: " << courseId << endl;
        cout << "Course name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
    }

private:
    int courseId;
    string courseName;
    int credits;
};

int main() {
    Student s;
    try {
        s.readData();
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    s.displayData();

    Course c;
    try {
        c.readData();
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    c.displayData();

    return 0;
}
