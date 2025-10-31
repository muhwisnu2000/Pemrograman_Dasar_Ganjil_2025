/*
For Alice Smith, the output will calculate her paycheck 
based on her monthly salary (30000 / 12 = 2500) and 
her monthly bonus (200), resulting in a total paycheck of 2700. 
This will be added to her year-to-date paid amount
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct employee
{
    string firstName;
    string lastName;
    int personID;
    string deptID;
    double yearlySalary;
    double monthlySalary;
    double yearToDatePaid;
    double monthlyBonus;
};

// Function to initialize employees
void initializeEmployees(employee employees[], int size)
{
    string firstNames[] = {"Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Hannah", "Ivy", "Jack"};
    string lastNames[] = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez"};
    int personIDs[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    string deptIDs[] = {"D101", "D102", "D103", "D104", "D105", "D106", "D107", "D108", "D109", "D110"};
    double yearlySalaries[] = {30000, 40000, 35000, 45000, 50000, 60000, 55000, 65000, 70000, 75000};
    double monthlyBonuses[] = {200, 300, 250, 400, 500, 600, 550, 700, 800, 900};
    double yearToDatePaid[] = {10000, 20000, 15000, 25000, 30000, 35000, 30000, 40000, 45000, 50000};

    for (int i = 0; i < size; i++)
    {
        employees[i].firstName = firstNames[i];
        employees[i].lastName = lastNames[i];
        employees[i].personID = personIDs[i];
        employees[i].deptID = deptIDs[i];
        employees[i].yearlySalary = yearlySalaries[i];
        employees[i].monthlySalary = employees[i].yearlySalary / 12;
        employees[i].yearToDatePaid = yearToDatePaid[i];
        employees[i].monthlyBonus = monthlyBonuses[i];
    }
}

int main()
{
    const int NUM_EMPLOYEES = 10;
    employee employees[NUM_EMPLOYEES];

    // Initialize employee data
    initializeEmployees(employees, NUM_EMPLOYEES);

    double payCheck; // variable to calculate the paycheck

    // Display employee information
    for (int counter = 0; counter < NUM_EMPLOYEES; counter++)
    {
        cout << employees[counter].firstName << " " << employees[counter].lastName << " ";
        payCheck = employees[counter].monthlySalary + employees[counter].monthlyBonus;
        employees[counter].yearToDatePaid += payCheck;
        cout << fixed << setprecision(2) << payCheck << endl;
    }

    cout << "*** End of program. ***" << endl;
    return 0;
}
