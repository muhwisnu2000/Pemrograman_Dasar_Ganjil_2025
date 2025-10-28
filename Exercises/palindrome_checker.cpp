#include <iostream>
#include <string> // Diperlukan untuk menggunakan tipe data string

using namespace std;

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;

    // Loop selama pointer kiri < pointer kanan
    while (left < right) {
        // Jika karakter di kiri dan kanan tidak sama, maka bukan palindrom
        if (str[left] != str[right]) {
            return false;
        }
        // Geser pointer
        left++;
        right--;
    }

    // Jika loop selesai tanpa menemukan perbedaan, maka ini adalah palindrom
    return true;
}

int main() {
    // Definisikan array string untuk diuji
    string testCases[] = {
        "madam",
        "abba ", // Perhatikan ada spasi di akhir
        "22",
        "67876",
        "444244",
        "trymeuemyrt"
    };

    cout << "--- Hasil Pengecekan Palindrome ---" << endl;

    // Gunakan loop untuk menguji setiap string
    for (const string& s : testCases) {
        // Panggil fungsi isPalindrome
        if (isPalindrome(s)) {
            cout << "\"" << s << "\" adalah palindrom." << endl;
        } else {
            cout << "\"" << s << "\" BUKAN palindrom." << endl;
        }
    }

    return 0;
}