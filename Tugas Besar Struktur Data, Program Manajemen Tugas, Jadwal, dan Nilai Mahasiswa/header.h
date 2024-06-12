#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <fstream>

using namespace std;

struct Task {
    string nama;
    string keterangan;
    string deadline;
    bool isDone;
    string selesai;
};

struct Schedule {
    string namaMakul;
    string namaDosen;
    int sks;
    string waktu;
};

struct Grade {
    string semester;
    string makul;
    double absensi;
    double tugas;
    double uts;
    double uas;
    double total;
    string grade;
};

class TaskManager {
public:
    void tambahTugas();
    void tampilkanTugas() const;
    void tampilkanTugasBelumSelesai() const;
    void tampilkanTugasSudahSelesai() const;
    void capTugasTuntas();
    void hapusTugas();

    void tambahJadwal();
    void tampilkanJadwal() const;
    void tampilkanJadwalIni() const;
    void hapusJadwal();

    void hitungNilaiAkhir();
    void tampilkanNilai() const;
    void tampilkanNilaiIni() const;
    void hapusNilai();

    void simpanData() const;
    void muatData();

private:
    vector<Task> daftarTugas;
    vector<Schedule> jadwal;
    vector<Grade> nilai;

    string getTanggalDanWaktuHariIni() const;
};
