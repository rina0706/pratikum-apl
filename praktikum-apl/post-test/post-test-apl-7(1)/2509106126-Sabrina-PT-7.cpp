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

bool loginUser(User *user) {
    string inputNama, inputNim;
    int percobaan = 0;

    while (percobaan < 3) {
        try {
            cout << "=== LOGIN ===\n";
            cout << "Nama: ";
            cin >> inputNama;
            cout << "NIM : ";
            cin >> inputNim;

            if (inputNama.empty() || inputNim.empty()) {
                throw "Nama atau NIM tidak boleh kosong!";
            }

            if (inputNama == user->nama && inputNim == user->nim) {
                cout << "Login berhasil!\n";
                return true;
            } else {
                throw "Login gagal! Nama atau NIM salah.";
            }
        }
        catch (const char* pesan) {
            cout << "Error: " << pesan << endl;
            percobaan++;
        }
    }

    cout << "Terlalu banyak percobaan login!\n";
    return false;
}

void tampil(Potion *potion, int jumlah) {
    try {
        if (jumlah == 0) {
            throw "Data potion masih kosong!";
        }

        cout << "\n=== DATA POTION ===\n";
        for (int i = 0; i < jumlah; i++) {
            cout << i + 1 << ". "
                 << potion[i].id << " | "
                 << potion[i].namaPotion << " | "
                 << potion[i].bahan << " | "
                 << potion[i].efek << endl;
        }
    }
    catch (const char* pesan) {
        cout << "Error: " << pesan << endl;
    }
}
void tambahPotion(Potion *potion, int *jumlah) {
    try {
        if (*jumlah >= 100) {
            throw "Penyimpanan penuh!";
        }

        cout << "\n=== TAMBAH POTION ===\n";

        cout << "Nama Potion : ";
        cin >> potion[*jumlah].namaPotion;

        cout << "ID Potion   : ";
        cin >> potion[*jumlah].id;

        if (potion[*jumlah].id <= 0) {
            throw "ID tidak boleh kurang dari atau sama dengan 0!";
        }

        cout << "Bahan tersedia: Glistering Melon, Pufferfish, Sugar\n";
        cout << "Bahan       : ";
        cin >> potion[*jumlah].bahan;

        cout << "Efek        : ";
        cin >> potion[*jumlah].efek;

        if (potion[*jumlah].namaPotion.empty() || potion[*jumlah].bahan.empty()) {
            throw "Data potion tidak boleh kosong!";
        }

        (*jumlah)++;
        cout << "Potion berhasil ditambahkan!\n";
    }
    catch (const char* pesan) {
        cout << "Error: " << pesan << endl;
    }
}
void hapusPotion(Potion *potion, int *jumlah) {
    try {
        if (*jumlah == 0) {
            throw "Belum ada data potion!";
        }

        int x;
        cout << "Index yang ingin dihapus: ";
        cin >> x;

        if (x <= 0 || x > *jumlah) {
            throw "Index tidak valid!";
        }

        for (int i = x - 1; i < *jumlah - 1; i++) {
            potion[i] = potion[i + 1];
        }

        (*jumlah)--;
        cout << "Potion berhasil dihapus!\n";
    }
    catch (const char* pesan) {
        cout << "Error: " << pesan << endl;
    }
}

void bubbleSort(Potion *potion, int jumlah) {
    try {
        if (jumlah == 0) {
            throw "Data kosong, tidak bisa sorting!";
        }

        for (int i = 0; i < jumlah - 1; i++) {
            for (int j = 0; j < jumlah - i - 1; j++) {
                if (potion[j].namaPotion > potion[j + 1].namaPotion) {
                    Potion temp = potion[j];
                    potion[j] = potion[j + 1];
                    potion[j + 1] = temp;
                }
            }
        }

        cout << "Bubble Sort selesai!\n";
        tampil(potion, jumlah);
    }
    catch (const char* pesan) {
        cout << "Error: " << pesan << endl;
    }
}

void selectionSort(Potion *potion, int jumlah) {
    try {
        if (jumlah == 0) {
            throw "Data kosong, tidak bisa sorting!";
        }

        for (int i = 0; i < jumlah - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < jumlah; j++) {
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
    catch (const char* pesan) {
        cout << "Error: " << pesan << endl;
    }
}
void merge(Potion *potion, int left, int mid, int right) {
    Potion temp[100];

    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (potion[i].namaPotion <= potion[j].namaPotion) {
            temp[k++] = potion[i++];
        } else {
            temp[k++] = potion[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = potion[i++];
    }

    while (j <= right) {
        temp[k++] = potion[j++];
    }

    for (int x = left; x <= right; x++) {
        potion[x] = temp[x];
    }
}

void mergeSort(Potion *potion, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(potion, left, mid);
        mergeSort(potion, mid + 1, right);
        merge(potion, left, mid, right);
    }
} 
void linearSearchNama(Potion *potion, int jumlah) {
    try {
        if (jumlah == 0) {
            throw "Data kosong!";
        }

        string cari;
        cout << "\nCari Nama Potion: ";
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

        if (!ketemu) {
            throw "Potion tidak ditemukan!";
        }
    }
    catch (const char* pesan) {
        cout << "Error: " << pesan << endl;
    }
}
void sortID(Potion *potion, int jumlah) {
    for (int i = 0; i < jumlah - 1; i++) {
        for (int j = 0; j < jumlah - i - 1; j++) {
            if (potion[j].id > potion[j + 1].id) {
                Potion temp = potion[j];
                potion[j] = potion[j + 1];
                potion[j + 1] = temp;
            }
        }
    }
}
void jumpSearchID(Potion *potion, int jumlah) {
    try {
        if (jumlah == 0) {
            throw "Data kosong!";
        }

        int cari;
        cout << "\nCari ID Potion: ";
        cin >> cari;

        sortID(potion, jumlah);

        int step = sqrt(jumlah);
        int prev = 0;

        while (potion[min(step, jumlah) - 1].id < cari) {
            prev = step;
            step += sqrt(jumlah);

            if (prev >= jumlah) {
                throw "ID tidak ditemukan!";
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

        throw "ID tidak ditemukan!";
    }
    catch (const char* pesan) {
        cout << "Error: " << pesan << endl;
    }
}
int main() {
    User user = {"rina", "126"};
    Potion potion[100];
    int jumlah = 0;

    if (!loginUser(&user)) {
        return 0;
    }

    int menu;

    do {
        try {
            cout << "\n=== MENU ===\n";
            cout << "1. Tambah Potion\n";
            cout << "2. Lihat Potion\n";
            cout << "3. Hapus Potion\n";
            cout << "4. Bubble Sort\n";
            cout << "5. Selection Sort\n";
            cout << "6. Merge Sort\n";
            cout << "7. Linear Search (Nama)\n";
            cout << "8. Jump Search (ID)\n";
            cout << "9. Keluar\n";
            cout << "Pilih Menu: ";
            cin >> menu;

            if (menu < 1 || menu > 9) {
                throw "Menu tidak tersedia!";
            }

            switch (menu) {
                case 1:
                    tambahPotion(potion, &jumlah);
                    break;

                case 2:
                    tampil(potion, jumlah);
                    break;

                case 3:
                    hapusPotion(potion, &jumlah);
                    break;

                case 4:
                    bubbleSort(potion, jumlah);
                    break;

                case 5:
                    selectionSort(potion, jumlah);
                    break;

                case 6:
                    if (jumlah == 0) {
                        throw "Data kosong, tidak bisa merge sort!";
                    }

                    mergeSort(potion, 0, jumlah - 1);
                    cout << "Merge Sort selesai!\n";
                    tampil(potion, jumlah);
                    break;

                case 7:
                    linearSearchNama(potion, jumlah);
                    break;

                case 8:
                    jumpSearchID(potion, jumlah);
                    break;

                case 9:
                    cout << "Program selesai.\n";
                    break;
            }
        }
        catch (const char* pesan) {
            cout << "Error: " << pesan << endl;
        }

    } while (menu != 9);

    return 0;
}
