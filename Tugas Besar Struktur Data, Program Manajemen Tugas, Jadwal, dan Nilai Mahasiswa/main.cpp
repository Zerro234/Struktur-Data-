#include "header.h"

void printHeader() {
    cout << "=========================" << endl;
    cout << "  Program Manajemen Tugas" << endl;
    cout << "=========================" << endl;
}

int main() {
    TaskManager tm;
    tm.muatData();

    while (true) {
        system("cls");
        cout << "=================" << endl;
        cout << "   Menu Utama    " << endl;
        cout << "=================" << endl;
        cout << "1. Tambah Tugas" << endl;
        cout << "2. Tampilkan Tugas" << endl;
        cout << "3. Cap Tugas Tuntas" << endl;
        cout << "4. Hapus Tugas" << endl;
        cout << "5. Tambah Jadwal" << endl;
        cout << "6. Tampilkan Jadwal" << endl;
        cout << "7. Hapus Jadwal" << endl;
        cout << "8. Hitung Nilai Akhir" << endl;
        cout << "9. Tampilkan Nilai" << endl;
        cout << "10. Hapus Nilai" << endl;
        cout << "11. Simpan dan Keluar" << endl;
        cout << "=================" << endl;
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tm.tambahTugas();
            break;
        case 2:
            tm.tampilkanTugas();
            break;
        case 3:
            tm.capTugasTuntas();
            break;
        case 4:
            tm.hapusTugas();
            break;
        case 5:
            tm.tambahJadwal();
            break;
        case 6:
            tm.tampilkanJadwal();
            break;
        case 7:
            tm.hapusJadwal();
            break;
        case 8:
            tm.hitungNilaiAkhir();
            break;
        case 9:
            tm.tampilkanNilai();
            break;
        case 10:
            tm.hapusNilai();
            break;
        case 11:
            tm.simpanData();
            cout << "Data berhasil disimpan. Keluar dari program." << endl;
            return 0;
        default:
            cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    }

    return 0;
}
