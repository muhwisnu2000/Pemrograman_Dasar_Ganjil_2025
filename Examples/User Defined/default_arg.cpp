// Using default arguments

#include <iostream>
using namespace std;

int boxVolume(int length=1, int width = 1, int height=1);

int main()
{
    cout << "The default box volume is: " << boxVolume()
         << endl;
    cout << "length 10, width 1 and height 1 is: " << boxVolume(10)
         << endl;
    cout << "length 10, width 5 and height 1 is: " << boxVolume(10, 5)
         << endl;
    cout << "length 10, width 5 and height 2 is: " << boxVolume(10, 5, 2)
         << endl;

    return 0;
}

// Calculate the volume of a box
int boxVolume(int length, int width, int height)
{
    return length * width * height;
}
