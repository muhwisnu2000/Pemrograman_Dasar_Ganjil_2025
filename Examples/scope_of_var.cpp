// A scoping example
#include <iostream>
using namespace std;
void a();     // function prototype
void b();     // function prototype
void c(void); // function prototype
int x = 1;    // global variable
const double PHI = 3.14;

int main()
{
    int x = 5; // local variable to main
    cout << "local x in outer scope of main is " << x << endl;

    { // start new scope
        int x = 7;
        cout << "local x in inner scope of main is " << x << endl;
    } // end new scope

    cout << "globel x in outer scope of main is " << ::x << endl;
    cout << "local x in outer scope of main is " << x << endl;

    cout << "*************************************************" << endl;
    a(); // a has automatic local x
    b(); // b has static local x
    c(); // c uses global x
    cout << "*************************************************" << endl;
    cout << "After second calling" << endl;
    a(); // a reinitializes automatic local x
    b(); // static local x retains its previous value
    c(); // global x also retains its value

    cout << endl
         << "local x in main is " << x << endl
         << endl;

    return 0;
}

void a()
{
    int x = 25; // initialized each time a is called
    cout << "local x in a is " << x << " after entering a" << endl;
}

void b()
{
    static int x = 50; // Static initialization only
                       // first time b is called.
    cout << endl
         << "local static x is " << x << " on entering b" << endl;
    x = x + 2;
}

void c(void)
{
    cout << endl
         << "global x is " << x << " on entering c" << endl;
    x *= 10;
}
