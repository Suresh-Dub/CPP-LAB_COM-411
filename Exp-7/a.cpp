//• To implement inheritance for a UGCourse class, PCourse class and DiplomaCourse class.


#include <iostream>
#include <string>

using namespace std;

// Base class UGCourse
class UGCourse {
public:
    string name;
    int code;
    int duration;

    UGCourse(string n, int c, int d) {
        name = n;
        code = c;
        duration = d;
    }

    void printCourse() {
        cout << "Name: " << name << ", Code: " << code << ", Duration: " << duration << " year(s)" << endl;
    }
};

// Derived class PCourse
class PCourse : public UGCourse {
public:
    string specialization;

    PCourse(string n, int c, int d, string s) : UGCourse(n, c, d) {
        specialization = s;
    }

    void printCourse() {
        cout << "Name: " << name << ", Code: " << code << ", Duration: " << duration << " year(s), Specialization: " << specialization << endl;
    }
};

// Derived class DiplomaCourse
class DiplomaCourse : public UGCourse {
public:
    string field;

    DiplomaCourse(string n, int c, int d, string f) : UGCourse(n, c, d) {
        field = f;
    }

    void printCourse() {
        cout << "Name: " << name << ", Code: " << code << ", Duration: " << duration << " year(s), Field: " << field << endl;
    }
};

int main() {
    // Create a UGCourse object and print details
    UGCourse u1("Computer Science", 101, 3);
    cout << "UG Course Details:" << endl;
    u1.printCourse();

    // Create a PCourse object and print details
    PCourse p1("Computer Engineering", 201, 4, "Software Engineering");
    cout << "P Course Details:" << endl;
    p1.printCourse();

    // Create a DiplomaCourse object and print details
    DiplomaCourse d1("Information Technology", 301, 2, "Networking");
    cout << "Diploma Course Details:" << endl;
    d1.printCourse();

    return 0;
}
