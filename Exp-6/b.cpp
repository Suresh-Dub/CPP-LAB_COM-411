//• To get the details of a course by course_id using a member function of course class. 
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

    // Member function to get course details by course code
    void getCourseDetails(int courseId) {
        if (code == courseId) {
            cout << "Course Details:" << endl;
            cout << "Name: " << name << ", Code: " << code << ", Duration: " << duration << " year(s)" << endl;
        } else {
            cout << "Course with course code " << courseId << " not found." << endl;
        }
    }
};

int main() {
    // Create a course object and add details using parameterized constructor
    Course c1("C++ Programming", 101, 3);

    // Get course details by course code using member function
    c1.getCourseDetails(101);

    return 0;
}
