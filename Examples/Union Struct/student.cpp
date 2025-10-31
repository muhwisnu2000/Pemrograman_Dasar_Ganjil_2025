#include <iostream>
#include <string>

using namespace std;

const int NO_OF_STUDENT = 6;

struct Name
{
    string first;
    string last;
};

struct Course
{
    string name;
    int courseCode;
    int credit;
    char grade;
};

struct Student
{
    Name studentName;
    double gpa;
    Course course;
};

int main()
{
   
    Student classList[NO_OF_STUDENT]; // Array to store students

    classList[0].studentName.first = "Chris";
    classList[0].studentName.last = "Martin";
    classList[0].gpa = 3.75;
    classList[0].course.name = "Music Fundamental";
    classList[0].course.courseCode = 101;
    classList[0].course.credit = 3;
    classList[0].course.grade = 'A';

    cout << "Student Name: " << classList[0].studentName.first << " " << classList[0].studentName.last << endl;
    cout << "GPA: " << classList[0].gpa << endl;
    cout << "Course: " << classList[0].course.name << " (" << classList[0].course.courseCode << ")" << endl;
    cout << "Credit: " << classList[0].course.credit << endl;
    cout << "Grade: " << classList[0].course.grade << endl;

}

