//• To add the details of a course using a parameterized constructor of course class.


#include <iostream>
#include <string>

using namespace std;

class Course {
public:
    string name;
    int code;
    int duration;

    // Parameterized constructor to add course details
    Course(string n, int c, int d) {
        name = n;
        code = c;
        duration = d;
    }
};

int main() {
    // Add course details using parameterized constructor
    Course c1("C++ Programming", 101, 3);
    Course c2("Data Structures and Algorithms", 102, 4);
    Course c3("Web Development", 103, 2);
    Course c4("Database Management", 104, 3);

    // Print course details
    cout << "Course Details:" << endl;
    cout << "Name: " << c1.name << ", Code: " << c1.code << ", Duration: " << c1.duration << " year(s)" << endl;
    cout << "Name: " << c2.name << ", Code: " << c2.code << ", Duration: " << c2.duration << " year(s)" << endl;
    cout << "Name: " << c3.name << ", Code: " << c3.code << ", Duration: " << c3.duration << " year(s)" << endl;
    cout << "Name: " << c4.name << ", Code: " << c4.code << ", Duration: " << c4.duration << " year(s)" << endl;

    return 0;
}

