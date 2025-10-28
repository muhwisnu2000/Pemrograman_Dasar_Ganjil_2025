#include <iostream>

using namespace std;

void modify(int y) // y is VALUE Parameter
{
    y = y + 10; // The return Statement
    cout << "y inside  modify function = " << y << endl;
}

int main()
{
    int x;
    x = 7;
    cout << "x before calling modify function = " << x << endl;

    modify(x); // calling statement x is actual parameter

    cout << "x After calling modify function = " << x << endl;
    cout << endl;
    return 0;
}
