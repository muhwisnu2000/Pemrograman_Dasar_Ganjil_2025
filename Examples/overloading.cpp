// Using overloaded functions
#include <iostream>

using namespace std;

int square(int x){
    return x * x; 
 }
 
 double square(double y) {
    return y * y; 
 }

int main(){
   cout << "The square of integer 7 is " << square(7)<< endl
        << "The square of double 7.5 is " << square(7.5) << endl;    

   return 0;
}


