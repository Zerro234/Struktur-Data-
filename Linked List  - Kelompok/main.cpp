#include "header.h"

void printHeader(const string& title) {
    system("cls");
    cout << "=========================================\n";
    cout << "      " << title << "       \n";
    cout << "=========================================\n";
}

int main() {
    simpul L = NULL;
    char choose;
    do {
        printHeader("OPERASI PADA SINGLE LINKED LIST");
        cout << " [1] Tambah Data Mahasiswa \n";
        cout << " [2] Tambah Kehadiran \n";
        cout << " [3] Cetak Data Mahasiswa dan Kehadiran\n";
        cout << " [0] Keluar \n";
        cout << "=========================================\n";
        cout << "Masukan pilihan : ";
        cin >> choose;
        cout << "------------------------------------" << endl;
        switch (choose) {
            case '1': {
                printHeader("Tambah Data Mahasiswa");
                string nama;
                cout << "Masukkan Nama Mahasiswa: ";
                cin.ignore(); // To clear the newline character from input buffer
                getline(cin, nama); // To allow names with spaces
                Sisip(L, nama);
                cout << "Data " << nama << " ditambahkan." << endl;
                cout << endl;
                cout << "------------------------------------" << endl;
                system("pause");
                break;
            }
            case '2': {
                printHeader("Tambah Kehadiran");
                TambahKehadiran(L);
                cout << "------------------------------------" << endl;
                system("pause");
                break;
            }
            case '3': {
                printHeader("Cetak Data Mahasiswa dan Kehadiran");
                Cetak(L);
                cout << "------------------------------------" << endl;
                system("pause");
                break;
            }
            case '0': {
                printHeader("Keluar");
                cout << "Terima kasih telah menggunakan program ini.\n";
                break;
            }
            default: {
                cout << "Pilihan tidak tersedia" << endl << endl;
                cout << "------------------------------------" << endl;
                system("pause");
                break;
            }
        }
    } while (choose != '0');
    return 0;
}

