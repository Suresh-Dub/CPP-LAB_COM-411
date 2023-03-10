//To implement polymorphism for member functions of UGCourse class, PGCourse class and DiplomaCourse class. in cpp
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

    virtual void printCourse() {
        cout << "Name: " << name << ", Code: " << code << ", Duration: " << duration << " year(s)" << endl;
    }
};

// Derived class PGCourse
class PGCourse : public UGCourse {
public:
    string specialization;

    PGCourse(string n, int c, int d, string s) : UGCourse(n, c, d) {
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
    // Create an array of UGCourse pointers and assign objects of derived classes
    UGCourse *courses[3];
    courses[0] = new UGCourse("Computer Science", 101, 3);
    courses[1] = new PGCourse("Computer Engineering", 201, 4, "Software Engineering");
    courses[2] = new DiplomaCourse("Information Technology", 301, 2, "Networking");

    // Print details of all courses using polymorphism
    for (int i = 0; i < 3; i++) {
        courses[i]->printCourse();
    }

    return 0;
}

