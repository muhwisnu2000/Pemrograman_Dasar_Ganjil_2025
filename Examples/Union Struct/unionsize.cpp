#include <iostream>
using namespace std;

union myunion {
    int i;
    float f;
    char c;
};

struct mystruct {
    int i;
    float f;
    char c;
};

int main(){

    cout << "Size of myunion: " << sizeof(myunion) << " bytes" << endl;
    cout << "Size of mystruct: " << sizeof(mystruct) << " bytes" << endl;
    
}