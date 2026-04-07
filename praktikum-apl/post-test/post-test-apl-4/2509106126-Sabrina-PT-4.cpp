#include <iostream>
#include <string>
using namespace std;

struct User {
    string nama;
    string nim;
};

struct Potion {
    string namaPotion;
    string bahan;
    string efek;
};

bool loginUser(User user) {
    string inputNama, inputNim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "=== SILAHKAN LOGIN ===" << endl;
        cout << "Masukkan Nama: ";
        cin >> inputNama;
        cout << "Masukkan NIM: ";
        cin >> inputNim;

        if (inputNama == user.nama && inputNim == user.nim) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "Login gagal!\n";
            percobaan++;
        }
    }

    cout << "Duhh gagal login 3 kali. Program berhenti.\n";
    return false;
}

void tambahPotion(Potion *potion, int *jumlahPotion) {
    cout << "\n=== MENAMBAHKAN POTION ===\n";

    cout << "Masukkan Nama Potion: ";
    cin >> potion[*jumlahPotion].namaPotion;

    cout << "Bahan potion: Glistering Melon, Pufferfish, Sugar\n";

    cout << "Masukkan Bahan Potion: ";
    cin >> potion[*jumlahPotion].bahan;

    cout << "Masukkan Efek Potion: ";
    cin >> potion[*jumlahPotion].efek;

    (*jumlahPotion)++;

    cout << "Potion berhasil ditambahkan!\n";
}

void lihatPotion(Potion *potion, int jumlahPotion) {
    int pilih;
    cout << "\n=== LIHAT POTION ===\n";
    cout << "1. Tampilkan semua potion\n";
    cout << "2. Pilih potion\n";
    cout << "Pilihan: ";
    cin >> pilih;

    if (pilih == 1) {
        for (int i = 0; i < jumlahPotion; i++) {
            cout << "\nPotion ke-" << i+1 << endl;
            cout << "Nama  : " << potion[i].namaPotion << endl;
            cout << "Bahan : " << potion[i].bahan << endl;
            cout << "Efek  : " << potion[i].efek << endl;
        }
    }
    else if (pilih == 2) {
        int index;
        cout << "Masukkan nomor potion: ";
        cin >> index;

        if (index > 0 && index <= jumlahPotion) {
            cout << "Nama  : " << potion[index-1].namaPotion << endl;
            cout << "Bahan : " << potion[index-1].bahan << endl;
            cout << "Efek  : " << potion[index-1].efek << endl;
        } else {
            cout << "Yahhh data tidak ditemukan\n";
        }
    }
}

void ubahPotion(Potion *potion, int jumlahPotion) {
    int ubah;

    cout << "\n=== UBAH POTION ===\n";
    cout << "Pilih potion yang ingin diubah: ";
    cin >> ubah;

    if (ubah > 0 && ubah <= jumlahPotion) {
        cout << "Nama potion baru: ";
        cin >> potion[ubah-1].namaPotion;

        cout << "Bahan potion: Glistering Melon, Pufferfish, Sugar\n";

        cout << "Bahan baru: ";
        cin >> potion[ubah-1].bahan;

        cout << "Efek baru: ";
        cin >> potion[ubah-1].efek;

        cout << "Data potion berhasil diubah!\n";
    } else {
        cout << "Yahhh data tidak ditemukan\n";
    }
}

void hapusPotion(Potion *potion, int *jumlahPotion) {
    int hapus;

    cout << "\n=== MENGHAPUS POTION ===\n";
    cout << "Pilih potion yang ingin dihapus: ";
    cin >> hapus;

    if (hapus > 0 && hapus <= *jumlahPotion) {
        for (int i = hapus-1; i < *jumlahPotion-1; i++) {
            potion[i] = potion[i+1];
        }
        (*jumlahPotion)--;

        cout << "Potion berhasil dihapus!\n";
    } else {
        cout << "Yahhh data tidak ditemukan\n";
    }
}

int main() {
    User user;
    Potion potion[100];
    int jumlahPotion = 0;

    user.nama = "rina";
    user.nim = "126";

    if (!loginUser(user)) {
        return 0;
    }

    int menu;

    do {
        cout << "\n=== SILAHKAN PILIH MENUNYA ===\n";
        cout << "1. Tambah Potion\n";
        cout << "2. Lihat Potion\n";
        cout << "3. Ubah Potion\n";
        cout << "4. Hapus Potion\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            tambahPotion(potion, &jumlahPotion); 
        }
        else if (menu == 2) {
            lihatPotion(potion, jumlahPotion);
        }
        else if (menu == 3) {
            ubahPotion(potion, jumlahPotion);
        }
        else if (menu == 4) {
            hapusPotion(potion, &jumlahPotion); 
        }

    } while (menu != 5);

    cout << "Program selesai.\n";

    return 0;
}
