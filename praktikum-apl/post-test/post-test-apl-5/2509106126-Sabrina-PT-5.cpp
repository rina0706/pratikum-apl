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

// LOGIN
bool loginUser(User *user) {
    string inputNama, inputNim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "=== LOGIN ===\n";
        cout << "Nama: "; cin >> inputNama;
        cout << "NIM : "; cin >> inputNim;

        if (inputNama == user->nama && inputNim == user->nim) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "Login gagal!\n";
            percobaan++;
        }
    }
    return false;
}

// TAMPIL SETELAH SORT
void tampilSetelahSort(Potion *potion, int jumlah) {
    cout << "\n=== HASIL SETELAH SORTING ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i+1 << ". "
             << potion[i].namaPotion << " | "
             << potion[i].bahan << " | "
             << potion[i].efek << endl;
    }
}

// TAMBAH
void tambahPotion(Potion *potion, int *jumlah) {
    cout << "\n=== TAMBAH POTION ===\n";

    cout << "Nama  : ";
    cin >> potion[*jumlah].namaPotion;

    cout << "Bahan tersedia: Glistering Melon, Pufferfish, Sugar\n";

    cout << "Bahan : ";
    cin >> potion[*jumlah].bahan;

    cout << "Efek  : ";
    cin >> potion[*jumlah].efek;

    (*jumlah)++;
    cout << "Potion berhasil ditambahkan!\n";
}

// LIHAT
void lihatPotion(Potion *potion, int *jumlah) {
    int pilih;
    cout << "\n=== LIHAT POTION ===\n";
    cout << "1. Semua\n2. Pilih\nPilihan: ";
    cin >> pilih;

    if (pilih == 1) {
        for (int i = 0; i < *jumlah; i++) {
            cout << "\nPotion ke-" << i+1 << endl;
            cout << "Nama  : " << potion[i].namaPotion << endl;
            cout << "Bahan : " << potion[i].bahan << endl;
            cout << "Efek  : " << potion[i].efek << endl;
        }
    } else {
        int index;
        cout << "Nomor: "; cin >> index;

        if (index > 0 && index <= *jumlah) {
            cout << "Nama  : " << potion[index-1].namaPotion << endl;
            cout << "Bahan : " << potion[index-1].bahan << endl;
            cout << "Efek  : " << potion[index-1].efek << endl;
        } else {
            cout << "Data tidak ditemukan\n";
        }
    }
}

// UBAH
void ubahPotion(Potion *potion, int *jumlah) {
    int x;
    cout << "\n=== UBAH POTION ===\n";
    cout << "Pilih index: "; cin >> x;

    if (x > 0 && x <= *jumlah) {
        cout << "Nama baru  : "; cin >> potion[x-1].namaPotion;

        cout << "Bahan tersedia: Glistering Melon, Pufferfish, Sugar\n";

        cout << "Bahan baru : "; cin >> potion[x-1].bahan;
        cout << "Efek baru  : "; cin >> potion[x-1].efek;

        cout << "Berhasil diubah!\n";
    } else {
        cout << "Data tidak ditemukan\n";
    }
}

// HAPUS
void hapusPotion(Potion *potion, int *jumlah) {
    int x;
    cout << "\n=== HAPUS POTION ===\n";
    cout << "Pilih index: "; cin >> x;

    if (x > 0 && x <= *jumlah) {
        for (int i = x-1; i < *jumlah-1; i++) {
            potion[i] = potion[i+1];
        }
        (*jumlah)--;
        cout << "Berhasil dihapus!\n";
    } else {
        cout << "Data tidak ditemukan\n";
    }
}

// SORT NAMA DESC (Z-A)
void sortNamaDesc(Potion *potion, int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (potion[j].namaPotion < potion[j+1].namaPotion) {
                Potion temp = potion[j];
                potion[j] = potion[j+1];
                potion[j+1] = temp;
            }
        }
    }
    cout << "Sorting Nama Z-A selesai!\n";
    tampilSetelahSort(potion, jumlah);
}

// SORT PANJANG ASC
void sortPanjangAsc(Potion *potion, int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (potion[j].namaPotion.length() > potion[j+1].namaPotion.length()) {
                Potion temp = potion[j];
                potion[j] = potion[j+1];
                potion[j+1] = temp;
            }
        }
    }
    cout << "Sorting panjang nama ASC selesai!\n";
    tampilSetelahSort(potion, jumlah);
}

// SORT BEBAS (Efek A-Z)
void sortEfekAsc(Potion *potion, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (potion[j].efek > potion[j + 1].efek) {
                Potion temp = potion[j];
                potion[j] = potion[j + 1];
                potion[j + 1] = temp;
            }
        }
    }
    cout << "Sorting efek A-Z selesai!\n";
    tampilSetelahSort(potion, jumlah);
}

int main() {
    User user;
    Potion potion[100];
    int jumlahPotion = 0;

    user.nama = "rina";
    user.nim = "126";

    if (!loginUser(&user)) return 0;

    int menu;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah Potion\n";
        cout << "2. Lihat Potion\n";
        cout << "3. Ubah Potion\n";
        cout << "4. Hapus Potion\n";
        cout << "5. Sort Nama (Desc)\n";
        cout << "6. Sort Panjang Nama (Asc)\n";
        cout << "7. Sort Efek (Bubble Sort A-Z)\n";
        cout << "8. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        switch(menu) {
            case 1: tambahPotion(potion, &jumlahPotion); break;
            case 2: lihatPotion(potion, &jumlahPotion); break;
            case 3: ubahPotion(potion, &jumlahPotion); break;
            case 4: hapusPotion(potion, &jumlahPotion); break;
            case 5: sortNamaDesc(potion, jumlahPotion); break;
            case 6: sortPanjangAsc(potion, jumlahPotion); break;
            case 7: sortEfekAsc(potion, jumlahPotion); break;
        }

    } while (menu != 8);

    cout << "Program selesai.\n";
    return 0;
}
