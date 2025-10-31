#include <iostream>
#include <string>

using namespace std;

struct house
{
    string style;
    int noOfBedroom;
    int noOfBathroom;
    int yearBuilt;
    int squareFootage;
    double price;
    double tax; 
};

void printHouse(house h); // parameter pass by value

int main()
{
    house house1;
    
    house1.style = "A110";
    house1.noOfBedroom = 3;
    house1.noOfBathroom = 2;
    house1.yearBuilt = 2002;
    house1.squareFootage = 120;
    house1.price = 480000.0;
    house1.tax = 480;  
    printHouse(house1);
    cout << "---------------" << endl;  
    
    house house2;
    house2.style = "A210";
    house2.noOfBedroom = 4;
    house2.noOfBathroom = 2;
    house2.yearBuilt = 2010;
    house2.squareFootage = 160;
    house2.price = 640000.0;
    house2.tax = 640;  
    printHouse(house2);
    cout << "---------------" << endl;  

    house h3;
    h3 = house1;
    printHouse(h3);

   
   if ((house1.style == h3.style) && (house1.price == h3.price))
    {
        cout << "Test compare : SAMA" << endl;
    }
    
   return 0;
}


void printHouse(house h){
    cout << "House model: " << h.style << endl << 
    "No of Bedroom: "<< h.noOfBedroom << endl <<
    "No of Bathroom: "<< h.noOfBathroom << endl <<
    "Year built: " << h.yearBuilt << endl <<
    "Price: " << h.price << endl <<
    "Tax: " << h.tax << endl;      
}

