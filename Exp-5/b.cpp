//• To update the details of a course using a member function of course class. 

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

    // Member function to update course details
    void updateCourse(string n, int c, int d) {
        name = n;
        code = c;
        duration = d;
    }
};

int main() {
    // Create a course object and add details using parameterized constructor
    Course c1("C++ Programming", 101, 3);

    // Print initial course details
    cout << "Initial Course Details:" << endl;
    cout << "Name: " << c1.name << ", Code: " << c1.code << ", Duration: " << c1.duration << " year(s)" << endl;

    // Update course details using member function
    c1.updateCourse("Object-Oriented Programming", 102, 4);

    // Print updated course details
    cout << "Updated Course Details:" << endl;
    cout << "Name: " << c1.name << ", Code: " << c1.code << ", Duration: " << c1.duration << " year(s)" << endl;

    return 0;
}


