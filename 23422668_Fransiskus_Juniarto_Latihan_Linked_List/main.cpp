#include "header.h"

void displayMenu() {
    cout << "===========================================" << endl;
    cout << "      OPERASI PADA DOUBLE LINKED LIST" << endl;
    cout << "===========================================" << endl;
    cout << "[1] Tambah data dari depan" << endl;
    cout << "[2] Tambah data dari belakang" << endl;
    cout << "[3] Hapus data dari depan" << endl;
    cout << "[4] Hapus data dari belakang" << endl;
    cout << "[5] Cetak data" << endl;
    cout << "[6] Clear" << endl;
    cout << "[7] Cetak data dari belakang" << endl;
    cout << "[8] Hitung jumlah node" << endl;
    cout << "[0] Exit" << endl;
    cout << "===========================================" << endl;
    cout << "Masukkan pilihan: ";
}

int main() {
    int databaru;
    head baru = NULL;

    int choose;
    do {
        printHeader("MENU UTAMA");
        displayMenu();
        cin >> choose;

        switch (choose) {
            case 1:
                printHeader("PENYISIPAN SIMPUL DI DEPAN");
                cout << "Masukkan angka: ";
                cin >> databaru;
                insertDepan(baru, databaru);
                cout << "Data setelah penyisipan: " << endl;
                tampil(baru);
                system("pause");
                break;
            case 2:
                printHeader("PENYISIPAN SIMPUL DI BELAKANG");
                cout << "Masukkan angka: ";
                cin >> databaru;
                insertBelakang(baru, databaru);
                cout << "Data setelah penyisipan: " << endl;
                tampil(baru);
                system("pause");
                break;
            case 3:
                printHeader("PENGHAPUSAN SIMPUL DI DEPAN");
                hapusDepan(baru);
                cout << "Data setelah penghapusan: " << endl;
                tampil(baru);
                system("pause");
                break;
            case 4:
                printHeader("PENGHAPUSAN SIMPUL DI BELAKANG");
                hapusBelakang(baru);
                cout << "Data setelah penghapusan: " << endl;
                tampil(baru);
                system("pause");
                break;
            case 5:
                printHeader("ISI LINKED LIST");
                tampil(baru);
                system("pause");
                break;
            case 6:
                printHeader("MENGHAPUS SEMUA DATA");
                clear(baru);
                system("pause");
                break;
            case 7:
                printHeader("ISI LINKED LIST DARI BELAKANG");
                tampilBelakang(baru);
                system("pause");
                break;
            case 8:
                printHeader("JUMLAH NODE DALAM LINKED LIST");
                cout << "Jumlah Node: " << hitungNode(baru) << endl;
                system("pause");
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                system("pause");
                break;
        }
    } while (choose != 0);
    return 0;
}

