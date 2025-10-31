// Program: Largest of two or three numbers

#include <iostream>

using namespace std;

double larger(double x, int y);
double compareThree(double x , double y, double z);

int main()
{
    double u = 4.0;
    int v = 8;
    cout << "The larger of 5 and 10 is " << larger(5, 10) << endl;
    cout << "The larger of u and v is " << larger(u, v) << endl;
    

    double one, two;
    cout << "Enter two numbers: ";
    cin >> one >> two;
    cout << "The larger of " << one << " and " << two << " is "
         << larger(one, two) << endl;

    cout << "The largest of 23, 34, and 12 is "
         << compareThree(23, 34, 12) << endl;

    return 0;
}

double larger(double x, int y)
{
    if (x >= y)
        return x;
    else
        return y;
}

double compareThree(double x, double y, double z)
{
    return larger(x, larger(y, z));
}


double average(double a, double b, double c)
{
    
    double dummy = 10;
    return dummy;
}
