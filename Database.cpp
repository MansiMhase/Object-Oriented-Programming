#include <iostream>
#include <cstring> // For strcpy and strlen

class Student {
private:
    char* name;
    int rollNumber;
    char className[10];
    char division;
    char dateOfBirth[11];
    char bloodGroup[4];
    char contactAddress[100];
    char telephoneNumber[15];
    char drivingLicenseNo[20];
    char other[50];

    static int count; // Static member to keep track of the number of students

public:
    // Default constructor
    Student() {
        name = new char[1];
        name[0] = '\0'; // Initialize name to an empty string
        rollNumber = 0;
        className[0] = '\0';
        division = '\0';
        dateOfBirth[0] = '\0';
        bloodGroup[0] = '\0';
        contactAddress[0] = '\0';
        telephoneNumber[0] = '\0';
        drivingLicenseNo[0] = '\0';
        other[0] = '\0';
        count++;
    }

    // Parameterized constructor
    Student(const char* n, int rn, const char* cls, char div, const char* dob, const char* bg, const char* addr, const char* tel, const char* dl, const char* oth) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        rollNumber = rn;
        strcpy(className, cls);
        division = div;
        strcpy(dateOfBirth, dob);
        strcpy(bloodGroup, bg);
        strcpy(contactAddress, addr);
        strcpy(telephoneNumber, tel);
        strcpy(drivingLicenseNo, dl);
        strcpy(other, oth);
        count++;
    }

    // Copy constructor
    Student(const Student& s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        rollNumber = s.rollNumber;
        strcpy(className, s.className);
        division = s.division;
        strcpy(dateOfBirth, s.dateOfBirth);
        strcpy(bloodGroup, s.bloodGroup);
        strcpy(contactAddress, s.contactAddress);
        strcpy(telephoneNumber, s.telephoneNumber);
        strcpy(drivingLicenseNo, s.drivingLicenseNo);
        strcpy(other, s.other);
        count++;
    }

    // Destructor
    ~Student() {
        delete[] name;
        count--;
    }

    // Static member function to get the count of students
    static int getCount() {
        return count;
    }

    // Inline function to print student details
    void printDetails() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Roll Number: " << rollNumber << std::endl;
        std::cout << "Class: " << className << std::endl;
        std::cout << "Division: " << division << std::endl;
        std::cout << "Date of Birth: " << dateOfBirth << std::endl;
        std::cout << "Blood Group: " << bloodGroup << std::endl;
        std::cout << "Contact Address: " << contactAddress << std::endl;
        std::cout << "Telephone Number: " << telephoneNumber << std::endl;
        std::cout << "Driving License No: " << drivingLicenseNo << std::endl;
        std::cout << "Other: " << other << std::endl;
    }

    // Friend class (for demonstration; in a real scenario, the purpose should be clear)
    friend class Database;
};

// Initialize static member
int Student::count = 0;

class Database {
private:
    Student** students;
    int size;

public:
    // Constructor
    Database(int s) : size(s) {
        students = new Student*[size];
        for (int i = 0; i < size; i++) {
            students[i] = nullptr;
        }
    }

    // Destructor
    ~Database() {
        for (int i = 0; i < size; i++) {
            delete students[i];
        }
        delete[] students;
    }

    // Add student to the database
    void addStudent(int index, const Student& s) {
        if (index >= 0 && index < size) {
            if (students[index] != nullptr) {
                delete students[index];
            }
            students[index] = new Student(s);
        }
    }

    // Print all student details
    void printAllStudents() const {
        for (int i = 0; i < size; i++) {
            if (students[i] != nullptr) {
                students[i]->printDetails();
                std::cout << "---------------------" << std::endl;
            }
        }
    }

    // Static member function to get the count of students
    static int getStudentCount() {
        return Student::getCount();
    }
};

int main() {
    // Create database of size 3
    Database db(3);

    // Add students
    db.addStudent(0, Student("John Doe", 101, "10A", 'A', "01/01/2000", "O+", "123 Elm St", "555-1234", "DL123456", "N/A"));
    db.addStudent(1, Student("Jane Smith", 102, "10B", 'B', "02/02/2000", "A-", "456 Oak St", "555-5678", "DL654321", "N/A"));
    db.addStudent(2, Student("Alice Johnson", 103, "10A", 'A', "03/03/2000", "B+", "789 Pine St", "555-9876", "DL789123", "N/A"));

    // Print all students
    db.printAllStudents();

    // Print the total number of students
    std::cout << "Total number of students: " << Database::getStudentCount() << std::endl;

    return 0;
}
