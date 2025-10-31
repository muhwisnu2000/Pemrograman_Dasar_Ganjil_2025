#include <iostream>
using namespace std;

union Data {
    int intValue;
    float floatValue;
    char charValue;
};

int main() {
    Data data;

    // Assign int value
    data.intValue = 42;
    cout << "Int value: " << data.intValue << endl;

    // Assign float value (overwrites int value)
    data.floatValue = 3.14;
    cout << "Float value: " << data.floatValue << endl;

    // Assign char value (overwrites float value)
    data.charValue = 'A';
    cout << "Char value: " << data.charValue << endl;

    // The intValue and floatValue are now invalid after the charValue assignment
    cout << "Int value after char assignment: " << data.intValue << endl;
    //cout << "Float value: " << data.floatValue << endl; 
    //cout << "Char value: " << data.charValue << endl;

    return 0;
}
