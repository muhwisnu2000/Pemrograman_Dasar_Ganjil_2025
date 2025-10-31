#include <iostream>
#include <string>

using namespace std;

const int ARRAY_SIZE = 3;

struct student {
    string firstName;
    string lastName;
    char courseGrade;
    int testScore;
    int programmingScore;
    double GPA;
};

struct studentList {
    student students_array[ARRAY_SIZE];  
    int listLength;                      
};

void readIn(student& student);           // Function to read student data
void displayStudentInfo(const student& student); // Function to display student info
void displayAllStudents(const studentList& sList); // Function to display all students

int main() {
    studentList sList;   
    sList.listLength = 0;  
    
    // Fill the student array with input from the user
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "\nEnter details for student " << (i + 1) << ":\n";
        readIn(sList.students_array[i]);
        sList.listLength++;  // Increase the list length
    }
    
    // Display all students 
    cout << "\nDisplaying all students:\n";
    displayAllStudents(sList);
    
    return 0;
}

void readIn(student& student)
{
    cout << "Enter first name: ";
    cin >> student.firstName;
    cout << "Enter last name: ";
    cin >> student.lastName;
    
    cout << "Enter test score: ";
    cin >> student.testScore;
    cout << "Enter programming score: ";
    cin >> student.programmingScore;
    
    cout << "Enter GPA: ";
    cin >> student.GPA;
    
    // Calculate average score
    int score = (student.testScore + student.programmingScore) / 2;
    
    // Assign course grade
    if (score >= 90)
        student.courseGrade = 'A';
    else if (score >= 80)
        student.courseGrade = 'B';
    else if (score >= 70)
        student.courseGrade = 'C';
    else if (score >= 60)
        student.courseGrade = 'D';
    else
        student.courseGrade = 'F';
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
