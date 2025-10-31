#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 10;

struct student {
    string firstName;
    string lastName;
    char courseGrade;
    int testScore;
    int programmingScore;
    double GPA;
};

struct studentList {
    student students_array[ARRAY_SIZE];  // Array to store students
    int listLength;                      // Current number of students in the array
};

void displayStudentInfo(const student& student); // Function to display student info
void displayAllStudents(const studentList& sList); // Function to display all students
void initializeStudents(studentList& sList); // Function to initialize hardcoded students

int main() {
    studentList sList;   // Declare a student list
    sList.listLength = ARRAY_SIZE;  // Set the list length to the size of the array

    // Initialize the student array with hardcoded data
    initializeStudents(sList);
    
    // Display all student information
    cout << "\nDisplaying all students:\n";
    displayAllStudents(sList);
    
    return 0;
}

// Function to initialize hardcoded student data
void initializeStudents(studentList& sList) {
    sList.students_array[0] = {"Alice", "Smith", 'B', 85, 90, 3.7};
    sList.students_array[1] = {"Bob", "Johnson", 'C', 78, 82, 3.2};
    sList.students_array[2] = {"Charlie", "Williams", 'A', 92, 95, 3.9};
    sList.students_array[3] = {"Diana", "Brown", 'B', 88, 85, 3.5};
    sList.students_array[4] = {"Ethan", "Jones", 'A', 94, 92, 4.0};
    sList.students_array[5] = {"Fiona", "Garcia", 'C', 72, 76, 2.8};
    sList.students_array[6] = {"George", "Miller", 'B', 83, 87, 3.4};
    sList.students_array[7] = {"Hannah", "Davis", 'A', 90, 93, 3.8};
    sList.students_array[8] = {"Isaac", "Martinez", 'D', 60, 65, 2.2};
    sList.students_array[9] = {"Jenna", "Lopez", 'C', 75, 78, 2.9};
}

void displayStudentInfo(const student& student) {
    cout << "Name: " << student.firstName << " " << student.lastName << endl;
    cout << "Test Score: " << student.testScore << endl;
    cout << "Programming Score: " << student.programmingScore << endl;
    cout << "GPA: " << student.GPA << endl;
    cout << "Course Grade: " << student.courseGrade << endl;
    cout << "--------------------------" << endl;
}

void displayAllStudents(const studentList& sList) {
    for (int i = 0; i < sList.listLength; i++) {
        cout << "\nStudent " << (i + 1) << ":\n";
        displayStudentInfo(sList.students_array[i]);
    }
}
