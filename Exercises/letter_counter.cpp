#include <iostream>
#include <fstream>  
#include <string>   
#include <cstdlib>  

using namespace std;

const int ALPHABET_SIZE = 26;

struct LetterCount {
    char upper;       // Karakter (mis. 'A')
    char lower;       // Karakter (mis. 'a')
    int upperCount;   // Hitungan untuk huruf besar
    int lowerCount;   // Hitungan untuk huruf kecil
};

// --- Deklarasi Fungsi (Prototipe) ---

void initializeCounts(LetterCount counts[], int size);
void openFile(ifstream& inFile, ofstream& outFile);
void count(ifstream& inFile, LetterCount counts[], int size, int& totalUpper, int& totalLower);
void printResult(ofstream& outFile, const LetterCount counts[], int size, int totalUpper, int totalLower);

int main() {
    // --- Deklarasi Variabel ---
    LetterCount letterCounts[ALPHABET_SIZE];
    int totalUppercase = 0;
    int totalLowercase = 0;
    ifstream inputFile;
    ofstream outputFile;
    
    // Siapkan array struktur
    initializeCounts(letterCounts, ALPHABET_SIZE);

    // Minta nama file dan buka stream
    openFile(inputFile, outputFile);

    // Baca file dan hitung huruf
    count(inputFile, letterCounts, ALPHABET_SIZE, totalUppercase, totalLowercase);

    // Cetak hasil ke file output
    printResult(outputFile, letterCounts, ALPHABET_SIZE, totalUppercase, totalLowercase);

    // Tutup file stream
    inputFile.close();
    outputFile.close();

    cout << "Analisis selesai. Hasil ditulis ke file output." << endl;

    return 0;
}


// --- Implementasi Fungsi ---

void initializeCounts(LetterCount counts[], int size) {
    for (int i = 0; i < size; ++i) {
        counts[i].upper = 'A' + i; // 'A', 'B', 'C', ...
        counts[i].lower = 'a' + i; // 'a', 'b', 'c', ...
        counts[i].upperCount = 0;
        counts[i].lowerCount = 0;
    }
}

void openFile(ifstream& inFile, ofstream& outFile) {
    string inputFilename;
    string outputFilename;

    // Meminta nama file dari pengguna
    cout << "Masukkan nama file input: ";
    cin >> inputFilename;

    cout << "Masukkan nama file output: ";
    cin >> outputFilename;

    // Membuka file input
    inFile.open(inputFilename);
    if (!inFile) {
        // Jika file tidak ada atau tidak bisa dibuka, cetak pesan dan keluar
        cout << "Error: Tidak dapat membuka file input '" << inputFilename << "'." << endl;
        exit(1); // Keluar dari program dengan kode error
    }

    // Membuka file output
    outFile.open(outputFilename);
    if (!outFile) {
        // Jika file output tidak bisa dibuat/dibuka
        cout << "Error: Tidak dapat membuka file output '" << outputFilename << "'." << endl;
        inFile.close(); // Tutup file input yang sudah terlanjur dibuka
        exit(1);
    }
}

void count(ifstream& inFile, LetterCount counts[], int size, int& totalUpper, int& totalLower) {
    char ch;
    
    // Inisialisasi total hitungan
    totalUpper = 0;
    totalLower = 0;

    // Membaca file karakter demi karakter sampai akhir file (EOF)
    while (inFile.get(ch)) {
        // Cek apakah itu huruf besar A-Z
        if (ch >= 'A' && ch <= 'Z') {
            int index = ch - 'A'; // 'A' - 'A' = 0, 'B' - 'A' = 1, ...
            counts[index].upperCount++;
            totalUpper++;
        }
        // Cek apakah itu huruf kecil a-z
        else if (ch >= 'a' && ch <= 'z') {
            int index = ch - 'a'; // 'a' - 'a' = 0, 'b' - 'a' = 1, ...
            counts[index].lowerCount++;
            totalLower++;
        }
    }
}

void printResult(ofstream& outFile, const LetterCount counts[], int size, int totalUpper, int totalLower) {
    outFile << "Analisis Frekuensi Huruf" << endl;
    outFile << "---------------------------------" << endl;
    outFile << "Total Huruf Besar: " << totalUpper << endl;
    outFile << "Total Huruf Kecil: " << totalLower << endl;
    outFile << "---------------------------------" << endl << endl;

    // Mencetak bagian huruf besar
    outFile << "--- Huruf Besar ---" << endl;
    for (int i = 0; i < size; ++i) {
        outFile << counts[i].upper << ": " << counts[i].upperCount;
        
        // Hitung persentase
        if (totalUpper > 0) {
            // Dibulatkan ke integer terdekat
            int percentage = static_cast<int>((counts[i].upperCount * 100.0 / totalUpper) + 0.5);
            outFile << " (" << percentage << "%)" << endl;
        } else {
            outFile << " (0%)" << endl; // Hindari pembagian dengan nol
        }
    }

    // Mencetak bagian huruf kecil
    outFile << endl << "--- Huruf Kecil ---" << endl;
    for (int i = 0; i < size; ++i) {
        outFile << counts[i].lower << ": " << counts[i].lowerCount;
        
        // Hitung persentase
        if (totalLower > 0) {
            // Dibulatkan ke integer terdekat
            int percentage = static_cast<int>((counts[i].lowerCount * 100.0 / totalLower) + 0.5);
            outFile << " (" << percentage << "%)" << endl;
        } else {
            outFile << " (0%)" << endl; // Hindari pembagian dengan nol
        }
    }
}
