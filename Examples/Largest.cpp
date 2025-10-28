//*********************************************************
//Program find the largest number of a set of 10 numbers.
//*********************************************************

#include <iostream>

using namespace std;

double larger(double x, double y);
  
int main()
{
    double num; //variable to hold the current number
    double max; //variable to hold the larger number
    int count;  //loop control variable

    cout << "Enter 10 numbers." << endl;
    cin >> num;                                 
    max = num;                                  

    for (count = 1; count < 10; count++)        
    {
        cin >> num;                             
        max = larger(max, num);                
    }

    cout << "The largest number is " << max << endl; 
    return 0;
}

double larger(double x, double y)
{
    if (x >= y)
        return x;
    else 
        return y;
}
