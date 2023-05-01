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
    // Create a UGCourse object and prompt user to enter details
    cout << "Enter UG Course Details:" << endl;
    string name;
    int code, duration;
    cout << "Name: ";
    cin >> name;
    cout << "Code: ";
    cin >> code;
    cout << "Duration (in years): ";
    cin >> duration;
    UGCourse u1(name, code, duration);
    cout << endl << "UG Course Details:" << endl;
    u1.printCourse();

    // Create a PCourse object and prompt user to enter details
    cout << endl << "Enter P Course Details:" << endl;
    string pname, specialization;
    int pcode, pduration;
    cout << "Name: ";
    cin >> pname;
    cout << "Code: ";
    cin >> pcode;
    cout << "Duration (in years): ";
    cin >> pduration;
    cout << "Specialization: ";
    cin >> specialization;
    PCourse p1(pname, pcode, pduration, specialization);
    cout << endl << "P Course Details:" << endl;
    p1.printCourse();

    // Create a DiplomaCourse object and prompt user to enter details
    cout << endl << "Enter Diploma Course Details:" << endl;
    string dname, field;
    int dcode, dduration;
    cout << "Name: ";
    cin >> dname;
    cout << "Code: ";
    cin >> dcode;
    cout << "Duration (in years): ";
    cin >> dduration;
    cout << "Field: ";
    cin >> field;
    DiplomaCourse d1(dname, dcode, dduration, field);
    cout << endl << "Diploma Course Details:" << endl;
    d1.printCourse();

    return 0;
}

