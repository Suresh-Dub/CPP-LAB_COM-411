//• To delete the details of a course using a member function of course class. 

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

    // Member function to delete course details
    void deleteCourse() {
        name = "";
        code = 0;
        duration = 0;
    }
};

int main() {
    // Create a course object and add details using parameterized constructor
    Course c1("C++ Programming", 101, 3);

    // Print initial course details
    cout << "Initial Course Details:" << endl;
    cout << "Name: " << c1.name << ", Code: " << c1.code << ", Duration: " << c1.duration << " year(s)" << endl;

    // Delete course details using member function
    c1.deleteCourse();

    // Print deleted course details
    cout << "Deleted Course Details:" << endl;
    cout << "Name: " << c1.name << ", Code: " << c1.code << ", Duration: " << c1.duration << " year(s)" << endl;

    return 0;
}


