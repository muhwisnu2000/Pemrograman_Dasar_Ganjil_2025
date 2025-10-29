#include <iostream>
#include <cmath> 
#include <iomanip> 

using namespace std;

const double PI = 3.1416;

double distance(double x1, double y1, double x2, double y2);
double radius(double centerX, double centerY, double pointX, double pointY);
double circumference(double rad);
double area(double rad);

int main() {
    double centerX, centerY, pointX, pointY;
    double rad, diam, circ, ar;

    // Minta input titik pusat
    cout << "Masukkan koordinat titik pusat (x1, y1): ";
    cin >> centerX >> centerY;

    // Minta input titik di tepi lingkaran
    cout << "Masukkan koordinat titik di tepi (x2, y2): ";
    cin >> pointX >> pointY;

    // Panggil fungsi untuk menghitung
    rad = radius(centerX, centerY, pointX, pointY);
    diam = 2.0 * rad;
    circ = circumference(rad);
    ar = area(rad);

    // Tampilkan hasil
    cout << fixed << setprecision(2); // Atur output ke 2 angka desimal
    cout << "\n--- Hasil Perhitungan Lingkaran ---" << endl;
    cout << "Radius         : " << rad << endl;
    cout << "Diameter       : " << diam << endl;
    cout << "Keliling (Circ): " << circ << endl;
    cout << "Luas (Area)    : " << ar << endl;

    return 0;
}

// --- Function Definitions (Implementasi) ---

double distance(double x1, double y1, double x2, double y2) {
    // Rumus: sqrt( (x2-x1)^2 + (y2-y1)^2 )
    double deltaX = x2 - x1;
    double deltaY = y2 - y1;

    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

double radius(double centerX, double centerY, double pointX, double pointY) {
    // Memanggil fungsi 'distance'
    return distance(centerX, centerY, pointX, pointY);
}

double circumference(double rad) {
    return 2.0 * PI * rad;
}

double area(double rad) {
    return PI * pow(rad, 2); // pow(rad, 2) sama dengan r*r
}