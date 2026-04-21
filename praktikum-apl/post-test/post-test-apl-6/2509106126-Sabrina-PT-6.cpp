#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct User {
    string nama;
    string nim;
};

struct Potion {
    int id;
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

// TAMPIL
void tampil(Potion *potion, int jumlah) {
    if (jumlah == 0) {
        cout << "Data kosong!\n";
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << i+1 << ". "
             << potion[i].id << " | "
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

    cout << "ID    : ";
    cin >> potion[*jumlah].id;

    cout << "Bahan tersedia: Glistering Melon, Pufferfish, Sugar\n";

    cout << "Bahan : ";
    cin >> potion[*jumlah].bahan;

    cout << "Efek  : ";
    cin >> potion[*jumlah].efek;

    (*jumlah)++;
    cout << "Potion berhasil ditambahkan!\n";
}

// HAPUS
void hapusPotion(Potion *potion, int *jumlah) {
    int x;
    cout << "Index: "; cin >> x;

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

// ================= BUBBLE SORT =================
void bubbleSort(Potion *potion, int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (potion[j].namaPotion > potion[j+1].namaPotion) {
                Potion temp = potion[j];
                potion[j] = potion[j+1];
                potion[j+1] = temp;
            }
        }
    }
    cout << "Bubble Sort selesai!\n";
    tampil(potion, jumlah);
}

// ================= SELECTION SORT =================
void selectionSort(Potion *potion, int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < jumlah; j++) {
            if (potion[j].namaPotion < potion[minIndex].namaPotion) {
                minIndex = j;
            }
        }
        Potion temp = potion[i];
        potion[i] = potion[minIndex];
        potion[minIndex] = temp;
    }
    cout << "Selection Sort selesai!\n";
    tampil(potion, jumlah);
}

// ================= MERGE SORT =================
void merge(Potion *potion, int left, int mid, int right) {
    Potion temp[100];
    int i = left, j = mid+1, k = left;

    while (i <= mid && j <= right) {
        if (potion[i].namaPotion <= potion[j].namaPotion)
            temp[k++] = potion[i++];
        else
            temp[k++] = potion[j++];
    }

    while (i <= mid) temp[k++] = potion[i++];
    while (j <= right) temp[k++] = potion[j++];

    for (int x = left; x <= right; x++) {
        potion[x] = temp[x];
    }
}

void mergeSort(Potion *potion, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(potion, left, mid);
        mergeSort(potion, mid+1, right);
        merge(potion, left, mid, right);
    }
}

// ================= LINEAR SEARCH =================
void linearSearchNama(Potion *potion, int jumlah) {
    string cari;
    cout << "\nCari Nama: ";
    cin >> cari;

    bool ketemu = false;

    for (int i = 0; i < jumlah; i++) {
        if (potion[i].namaPotion == cari) {
            cout << "Ditemukan: "
                 << potion[i].id << " | "
                 << potion[i].namaPotion << endl;
            ketemu = true;
        }
    }

    if (!ketemu) cout << "Tidak ditemukan\n";
}

// ================= SORT ID =================
void sortID(Potion *potion, int jumlah) {
    for (int i = 0; i < jumlah-1; i++) {
        for (int j = 0; j < jumlah-i-1; j++) {
            if (potion[j].id > potion[j+1].id) {
                Potion temp = potion[j];
                potion[j] = potion[j+1];
                potion[j+1] = temp;
            }
        }
    }
}

// ================= JUMP SEARCH =================
void jumpSearchID(Potion *potion, int jumlah) {
    int cari;
    cout << "\nCari ID: ";
    cin >> cari;

    sortID(potion, jumlah);

    int step = sqrt(jumlah);
    int prev = 0;

    while (potion[min(step, jumlah)-1].id < cari) {
        prev = step;
        step += sqrt(jumlah);

        if (prev >= jumlah) {
            cout << "Tidak ditemukan\n";
            return;
        }
    }

    for (int i = prev; i < min(step, jumlah); i++) {
        if (potion[i].id == cari) {
            cout << "Ditemukan: "
                 << potion[i].id << " | "
                 << potion[i].namaPotion << endl;
            return;
        }
    }

    cout << "Tidak ditemukan\n";
}

// ================= MAIN =================
int main() {
    User user = {"rina", "126"};
    Potion potion[100];
    int jumlah = 0;

    if (!loginUser(&user)) return 0;

    int menu;
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tambah\n";
        cout << "2. Lihat\n";
        cout << "3. Hapus\n";
        cout << "4. Bubble Sort\n";
        cout << "5. Selection Sort\n";
        cout << "6. Merge Sort\n";
        cout << "7. Linear Search (Nama)\n";
        cout << "8. Jump Search (ID)\n";
        cout << "9. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        switch(menu) {
            case 1: tambahPotion(potion, &jumlah); break;
            case 2: tampil(potion, jumlah); break;
            case 3: hapusPotion(potion, &jumlah); break;
            case 4: bubbleSort(potion, jumlah); break;
            case 5: selectionSort(potion, jumlah); break;
            case 6:
                mergeSort(potion, 0, jumlah-1);
                cout << "Merge Sort selesai!\n";
                tampil(potion, jumlah);
                break;
            case 7: linearSearchNama(potion, jumlah); break;
            case 8: jumpSearchID(potion, jumlah); break;
        }

    } while (menu != 9);

    cout << "Program selesai.\n";
    return 0;
}
