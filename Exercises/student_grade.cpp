#include <iostream>
#include <fstream>  
#include <string>  
#include <iomanip> 

using namespace std;

// --- Konstanta Global ---
const int NUM_STUDENTS = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// --- Prototipe Fungsi ---

void readData(ifstream& inFile, studentType list[], int size);
void assignGrades(studentType list[], int size);
void printResults(ofstream& outFile, const studentType list[], int size);
int findHighestScore(const studentType list[], int size);
void printHighestScorers(ofstream& outFile, const studentType list[], int size, int highScore);

int main() {
    // Deklarasi Variabel
    studentType classList[NUM_STUDENTS];
    int highestScore;
    ifstream infile;
    ofstream outfile;

    // Membuka File
    infile.open("studentsScore.txt");
    if (!infile) {
        cout << "Error: Tidak dapat membuka file input 'students.txt'." << endl;
        return 1; // Keluar dengan kode error
    }

    outfile.open("studentResults.txt");
    if (!outfile) {
        cout << "Error: Tidak dapat membuka file output 'results.txt'." << endl;
        infile.close();
        return 1;
    }

    // Panggilan Fungsi (Alur Program Utama)
    
    // Membaca data dari students.txt ke classList
    readData(infile, classList, NUM_STUDENTS);

    // Menghitung dan menetapkan nilai A, B, C... ke classList
    assignGrades(classList, NUM_STUDENTS);

    // Mencetak laporan utama ke results.txt
    printResults(outfile, classList, NUM_STUDENTS);

    // Menemukan skor tertinggi
    highestScore = findHighestScore(classList, NUM_STUDENTS);

    // Mencetak ringkasan skor tertinggi di bagian bawah laporan
    outfile << "\n--------------------------------------------------" << endl;
    outfile << "Skor Tes Tertinggi: " << highestScore << endl;
    outfile << "Siswa dengan skor tertinggi:" << endl;
    
    // Mencetak nama-nama siswa yang mendapat skor tertinggi
    printHighestScorers(outfile, classList, NUM_STUDENTS, highestScore);

    infile.close();
    outfile.close();

    cout << "Pemrosesan selesai. Silakan periksa file 'results.txt'." << endl;

    return 0;
}

// --- Implementasi Fungsi ---

void readData(ifstream& inFile, studentType list[], int size) {
    for (int i = 0; i < size; i++) {
        inFile >> list[i].studentFName >> list[i].studentLName >> list[i].testScore;
    }
}

void assignGrades(studentType list[], int size) {
    // Menggunakan skala penilaian standar
    for (int i = 0; i < size; i++) {
        if (list[i].testScore >= 90) {
            list[i].grade = 'A';
        } else if (list[i].testScore >= 80) {
            list[i].grade = 'B';
        } else if (list[i].testScore >= 70) {
            list[i].grade = 'C';
        } else if (list[i].testScore >= 60) {
            list[i].grade = 'D';
        } else {
            list[i].grade = 'F';
        }
    }
}

void printResults(ofstream& outFile, const studentType list[], int size) {
    // Mengatur formatting untuk file output
    outFile << left; // Meratakan teks ke kiri
    outFile << "--------------------------------------------------" << endl;
    outFile << setw(30) << "Nama Siswa" << setw(10) << "Skor" << "Nilai" << endl;
    outFile << "--------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        // Format nama: "NamaBelakang, NamaDepan"
        string fullName = list[i].studentLName + ", " + list[i].studentFName;
        
        // Mencetak baris yang sudah diformat
        outFile << setw(30) << fullName
                << setw(10) << list[i].testScore
                << list[i].grade << endl;
    }
}

int findHighestScore(const studentType list[], int size) {
    // Mulai dengan asumsi skor tertinggi adalah milik siswa pertama
    int maxScore = list[0].testScore;

    // Loop melalui sisa array untuk menemukan skor yang lebih tinggi
    for (int i = 1; i < size; i++) {
        if (list[i].testScore > maxScore) {
            maxScore = list[i].testScore;
        }
    }
    return maxScore;
}

void printHighestScorers(ofstream& outFile, const studentType list[], int size, int highScore) {
    outFile << left; // Pastikan teks rata kiri
    
    // Loop melalui semua siswa
    for (int i = 0; i < size; i++) {
        // Jika siswa ini memiliki skor tertinggi
        if (list[i].testScore == highScore) {
            // Cetak nama mereka dalam format yang diminta
            string fullName = list[i].studentLName + ", " + list[i].studentFName;
            outFile << fullName << endl;
        }
    }
}
