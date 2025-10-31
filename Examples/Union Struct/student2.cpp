#include <iostream>

using namespace std;

struct student{
    string firstName;
    string lastName;
    char courseGrade;
    int testScore;
    int programmingScore;
    double GPA;
};

void readIn(student& student);
void displayStudentInfo(const student& student); // parameter pass by reference

int main() {
    student newStudent; 
    readIn(newStudent); 
    displayStudentInfo(newStudent); 
    return 0;
}

void readIn(student& student)
{
    int score;
    cout << "Enter first name: "; cin >> student.firstName;
    cout << "Enter last name: ";  cin >> student.lastName;
    cout << "Enter test score: "; cin >> student.testScore;
    cout << "Enter programming score: "; cin >> student.programmingScore;
    cout << "Enter GPA: "; cin >> student.GPA;

    score = (student.testScore + student.programmingScore) / 2;
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
    cout << "\nStudent Information:" << endl;
    cout << "Name: " << student.firstName << " " << student.lastName << endl;
    cout << "Test Score: " << student.testScore << endl;
    cout << "Programming Score: " << student.programmingScore << endl;
    cout << "GPA: " << student.GPA << endl;
    cout << "Course Grade: " << student.courseGrade << endl;
}
