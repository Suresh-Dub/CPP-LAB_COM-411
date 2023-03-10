//Analyze and design classes for a student management system.
class Student {
private:
    std::string name;
    std::string id;
    std::string email;
    std::string branch;
    // Add more attributes as necessary

public:
    Student(const std::string& name, const std::string& id, const std::string& email);
    // Add more methods as necessary
};

class Course {
private:
    std::string name;
    std::string code;
    std::string sem;
    // Add more attributes as necessary

public:
    Course(const std::string& name, const std::string& code);
    // Add more methods as necessary
};

class Instructor {
private:
    std::string name;
    std::string id;
    std::string email;
    // Add more attributes as necessary

public:
    Instructor(const std::string& name, const std::string& id, const std::string& email);
    // Add more methods as necessary
};
