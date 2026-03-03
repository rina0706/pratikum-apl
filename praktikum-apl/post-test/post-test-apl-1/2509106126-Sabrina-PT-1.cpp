#include <iostream>
using namespace std;

int main() {
    string Nama, inputNama;
    int password, inputPass;
    int percobaan = 0;

    Nama = "rina";
    password = 126;

    while (percobaan < 3) {
        cout << "LOGIN\n";
        cout << "Nama : ";
        cin >> inputNama;
        cout << "Password : ";
        cin >> inputPass;

        if (inputNama == Nama && inputPass == password) {
            cout << "\nLogin berhasil!\n";
            break;
        } else {
            percobaan++;
            cout << "Login salah! Percobaan ke-" << percobaan << endl;
        }

        if (percobaan == 3) {
            cout << "\nGagal login 3 kali. Program berhenti.\n";
            return 0;
        }
    }

    string pilihan;
    double nilai;

    do {
        cout << "\n=== MENU KONVERSI PANJANG ===\n";
        cout << "1. Meter ke Kilometer dan Centimeter\n";
        cout << "2. Kilometer ke Meter dan Centimeter\n";
        cout << "3. Centimeter ke Meter dan Kilometer\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        if (pilihan == "1") {
            cout << "Masukkan nilai Meter: ";
            cin >> nilai;
            cout << "Hasil:\n";
            cout << nilai / 1000 << " Kilometer\n";
            cout << nilai * 100 << " Centimeter\n";

        } else if (pilihan == "2") {
            cout << "Masukkan nilai Kilometer: ";
            cin >> nilai;
            cout << "Hasil:\n";
            cout << nilai * 1000 << " Meter\n";
            cout << nilai * 100000 << " Centimeter\n";

        } else if (pilihan == "3") {
            cout << "Masukkan nilai Centimeter: ";
            cin >> nilai;
            cout << "Hasil:\n";
            cout << nilai / 100 << " Meter\n";
            cout << nilai / 100000 << " Kilometer\n";

        } else if (pilihan == "4") {
            cout << "Tengss. Programnya sudah selesai.\n";

        } else {
            cout << "Pilihanmu ga valid!\n";
        }

    } while (pilihan != "4");

    return 0;
}
