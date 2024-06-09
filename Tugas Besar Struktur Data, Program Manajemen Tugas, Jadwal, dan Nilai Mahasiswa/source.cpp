#include "header.h"

void TaskManager::tambahTugas() {
    string nama, keterangan, deadline;
    char lagi;
    do {
        system("cls");
        cout << "=================" << endl;
        cout << "  Tambah Tugas   " << endl;
        cout << "=================" << endl;
        
        cout << "(ketik 1 untuk melanjutkan, 0 untuk kembali ke menu utama): ";
    	int index;
    	cin >> index;
    	if (index == 0) return;
    	
        cin.ignore();
        cout << "Input Tugas: ";
        getline(cin, nama);
        cout << "Input Keterangan Tugas: ";
        getline(cin, keterangan);
        cout << "Input Deadline: ";
        getline(cin, deadline);

        Task t = {nama, keterangan, deadline, false, ""};
        daftarTugas.push_back(t);

        cout << "Tugas berhasil diinputkan." << endl;
        cout << "tugas yg di inputkan " << nama << " dengan deadline " << deadline << endl;
        cout << "Apakah ingin menginput tugas lagi (Y/N)? ";
        cin >> lagi;

    } while (lagi == 'Y' || lagi == 'y');
}

void TaskManager::tampilkanTugas() const {
    system("cls");
    cout << "====================" << endl;
    cout << "    Daftar Tugas    " << endl;
    cout << "====================" << endl;

    cout << "Tugas Belum Selesai" << endl;
    for (size_t i = 0; i < daftarTugas.size(); ++i) {
        if (!daftarTugas[i].isDone) {
            cout << i + 1 << ". " << daftarTugas[i].nama << " - " << daftarTugas[i].keterangan << " - " << daftarTugas[i].deadline << endl;
        }
    }

    cout << "\nTugas Selesai" << endl;
    for (size_t i = 0; i < daftarTugas.size(); ++i) {
        if (daftarTugas[i].isDone) {
            cout << i + 1 << ". " << daftarTugas[i].nama << " - " << daftarTugas[i].keterangan << " - " << daftarTugas[i].deadline << " - Selesai pada: " << daftarTugas[i].selesai << endl;
        }
    }
	system("pause");
}

void TaskManager::tampilkanTugasBelumSelesai() const {
    for (size_t i = 0; i < daftarTugas.size(); ++i) {
        if (!daftarTugas[i].isDone) {
            cout << i + 1 << ". " << daftarTugas[i].nama << " - " << daftarTugas[i].keterangan << " - " << daftarTugas[i].deadline << endl;
        }
    }
}

void TaskManager::capTugasTuntas() {
    system("cls");
    cout << "===================" << endl;
    cout << "  Cap Tugas Tuntas  " << endl;
    cout << "===================" << endl;

    tampilkanTugasBelumSelesai();
    	
    if (daftarTugas.empty()) {
        cout << "Tugas kosong." << endl;
        return;
    }

    cout << "Input nomor tugas yang ingin dinyatakan selesai: ";
    int index;
    cin >> index;
    if (index > 0 && index <= daftarTugas.size() && !daftarTugas[index - 1].isDone) {
        daftarTugas[index - 1].isDone = true;
        daftarTugas[index - 1].selesai = getTanggalDanWaktuHariIni();
        cout << "Kamu hebat telah menyelesaikan tugas ini, semangat mengerjakan tugas berikutnya!" << endl;
    } else {
        cout << "Input tidak valid." << endl;
    }

    if (all_of(daftarTugas.begin(), daftarTugas.end(), [](const Task& t) { return t.isDone; })) {
        cout << "Tugas sudah diselesaikan semua, kamu hebat banget!" << endl;
    }
	system("pause");
}

void TaskManager::hapusTugas() {
    system("cls");
    cout << "==================" << endl;
    cout << "   Hapus Tugas    " << endl;
    cout << "==================" << endl;

    tampilkanTugas();

    if (daftarTugas.empty()) {
        cout << "Tugas kosong." << endl;
        return;
    }

    cout << "Input nomor tugas yang ingin dihapus (ketik -1 untuk reset semua, 0 untuk kembali ke menu utama): ";
    int index;
    cin >> index;
    if (index == 0) return;
    else if (index == -1) {
        daftarTugas.clear();
        cout << "Reset berhasil." << endl;
    } else if (index > 0 && index <= daftarTugas.size()) {
        daftarTugas.erase(daftarTugas.begin() + index - 1);
        cout << "Tugas berhasil dihapus." << endl;
    } else {
        cout << "Input tidak valid." << endl;
    }

    char lagi;
    cout << "Ingin menghapus lagi (Y/N)? ";
    cin >> lagi;
    if (lagi == 'Y' || lagi == 'y') hapusTugas();
}

void TaskManager::tambahJadwal() {
    string namaMakul, namaDosen, waktu;
    int sks;
    char lagi;

    do {
        system("cls");
        cout << "==================" << endl;
        cout << "  Input Jadwal    " << endl;
        cout << "==================" << endl;
        cout << "Jika tidak ada yang ingin di inputkan silahkan menekan 0 untuk kembali ke menu utama" << endl;
        cin.ignore();
        cout << "Input nama makul: ";
        getline(cin, namaMakul);
        if (namaMakul == "0") return;
        cout << "Input nama dosen: ";
        getline(cin, namaDosen);
        cout << "Input SKS: ";
        cin >> sks;
        if (sks < 1 || sks > 4) {
            cout << "SKS tidak valid. Masukkan antara 1 hingga 4." << endl;
            continue;
        }
        cout << "Input waktu makul (contoh 07:30 - 09:20): ";
        cin >> ws;
        getline(cin, waktu);

        Schedule schedule = { namaMakul, namaDosen, sks, waktu };
        jadwal.push_back(schedule);

        cout << "Jadwal berhasil diinputkan." << endl;

        cout << "Apakah ingin menginput jadwal lagi (Y/N)? ";
        cin >> lagi;

    } while (lagi == 'Y' || lagi == 'y');
}

void TaskManager::tampilkanJadwal() const {
    system("cls");
    cout << "====================" << endl;
    cout << "      Jadwal       " << endl;
    cout << "====================" << endl;

    if (jadwal.empty()) {
        cout << "Jadwal kosong." << endl;
    } else {
        for (size_t i = 0; i < jadwal.size(); ++i) {
            cout << i + 1 << ". " << jadwal[i].namaMakul << " - [ " << jadwal[i].namaDosen << " ] - | " << jadwal[i].sks << " SKS | - " << jadwal[i].waktu << endl;
        }
    }
    system("pause");
}

void TaskManager::hapusJadwal() {
    system("cls");
    cout << "====================" << endl;
    cout << "    Hapus Jadwal   " << endl;
    cout << "====================" << endl;

    tampilkanJadwal();
	cout << "Input nomor jadwal yang ingin dihapus (ketik -1 untuk reset semua, 0 untuk kembali ke menu utama): ";
    if (jadwal.empty()) {
        cout << "Jadwal kosong." << endl;
        return;
    }

    int index;
    cin >> index;
    if (index == 0) return;
    else if (index == -1) {
        jadwal.clear();
        cout << "Reset berhasil." << endl;
    } else if (index > 0 && index <= jadwal.size()) {
        jadwal.erase(jadwal.begin() + index - 1);
        cout << "Jadwal berhasil dihapus." << endl;
    } else {
        cout << "Input tidak valid." << endl;
    }

    char lagi;
    cout << "Ingin menghapus lagi (Y/N)? ";
    cin >> lagi;
    if (lagi == 'Y' || lagi == 'y') hapusJadwal();
}

void TaskManager::hitungNilaiAkhir() {
    string semester, makul;
    double absensi, tugas, uts, uas;
    char lagi;

    do {
        system("cls");
        cout << "=================" << endl;
        cout << "  Menghitung Nilai Akhir" << endl;
        cout << "=================" << endl;
        cin.ignore();
        cout << "Input Semester: ";
        getline(cin, semester);
        cout << "Input Makul: ";
        getline(cin, makul);
        cout << "Input Nilai Absensi: ";
        cin >> absensi;
        while (absensi < 0 || absensi > 100) {
            cout << "Nilai tidak valid. Masukkan antara 0 hingga 100." << endl;
            cout << "Input Nilai Absensi: ";
            cin >> absensi;
        }
        cout << "Input Nilai Tugas: ";
        cin >> tugas;
        while (tugas < 0 || tugas > 100) {
            cout << "Nilai tidak valid. Masukkan antara 0 hingga 100." << endl;
            cout << "Input Nilai Tugas: ";
            cin >> tugas;
        }
        cout << "Input Nilai UTS: ";
        cin >> uts;
        while (uts < 0 || uts > 100) {
            cout << "Nilai tidak valid. Masukkan antara 0 hingga 100." << endl;
            cout << "Input Nilai UTS: ";
            cin >> uts;
        }
        cout << "Input Nilai UAS: ";
        cin >> uas;
        while (uas < 0 || uas > 100) {
            cout << "Nilai tidak valid. Masukkan antara 0 hingga 100." << endl;
            cout << "Input Nilai UAS: ";
            cin >> uas;
        }

        double total = (absensi * 0.1) + (tugas * 0.2) + (uts * 0.3) + (uas * 0.4);
        string grade;
        if (total >= 80) grade = "A";
        else if (total >= 60) grade = "B";
        else if (total >= 40) grade = "C";
        else grade = "D";

        Grade g = {semester, makul, absensi, tugas, uts, uas, total, grade};
        nilai.push_back(g);

        cout << "Daftar Nilai Semester " << semester << endl;
        cout << "Nama Makul: " << makul << endl;
        cout << "Nilai Absensi: " << absensi << endl;
        cout << "Nilai Tugas: " << tugas << endl;
        cout << "Nilai UTS: " << uts << endl;
        cout << "Nilai UAS: " << uas << endl;
        cout << "Menampilkan rumus penghitunganya ...." << endl;
        cout << "(absensi * 10%) + (nilai tugas * 20%) + (nilai uts * 30%) + (nilai uas * 40%)" << endl;
        cout << "Total nilai dan Grade" << endl;
        cout << "Nilai Akhir " << total << " Grade " << grade << endl;

        if (grade == "A") cout << "Selamat Atas nilai yang sangat bagus ini, di pertahankan yaa nilainya!" << endl;
        else if (grade == "B") cout << "Nilainya Sudah bagus tapi masih bisa di tingkatkan lagi, Semangat!" << endl;
        else if (grade == "C") cout << "Waduh Nilainya masih kurang ni, Belajar dan tingkatkan lagi yaa, Semangat kamu pasti bisa!" << endl;
        else if (grade == "D") cout << "Sepertinya kamu Harus banyak banyak lagi belajar dan jangan putus asa dengan nilai itu, masih bisa di tingkatkan lagi, Ayo lebih semangat saya selalu menemani anda di sini." << endl;

        cout << "\nNilai berhasil disimpan." << endl;
        cout << "Apakah ingin menghitung nilai lagi (Y/N)? ";
        cin >> lagi;

    } while (lagi == 'Y' || lagi == 'y');
}

void TaskManager::tampilkanNilai() const {
    system("cls");
    cout << "=====================" << endl;
    cout << "     Daftar Nilai    " << endl;
    cout << "=====================" << endl;

    if (nilai.empty()) {
        cout << "Nilai kosong." << endl;
    } else {
        for (const auto& g : nilai) {
            cout << "Daftar Nilai Semester " << g.semester << endl;
            cout << "Nama Makul: " << g.makul << endl;
            cout << "Nilai Absensi: " << g.absensi << endl;
            cout << "Nilai Tugas: " << g.tugas << endl;
            cout << "Nilai UTS: " << g.uts << endl;
            cout << "Nilai UAS: " << g.uas << endl;
            cout << "Total Nilai: " << g.total << endl;
            cout << "Grade: " << g.grade << endl;

            if (g.grade == "A") cout << "Selamat Atas nilai yang sangat bagus ini, di pertahankan yaa nilainya!" << endl;
            else if (g.grade == "B") cout << "Nilainya Sudah bagus tapi masih bisa di tingkatkan lagi, Semangat!" << endl;
            else if (g.grade == "C") cout << "Waduh Nilainya masih kurang ni, Belajar dan tingkatkan lagi yaa, Semangat kamu pasti bisa!" << endl;
            else if (g.grade == "D") cout << "Sepertinya kamu Harus banyak banyak lagi belajar dan jangan putus asa dengan nilai itu, masih bisa di tingkatkan lagi, Ayo lebih semangat saya selalu menemani anda di sini." << endl;

            cout << "---------------------------------" << endl;
        }
    }
	system("pause");
}

void TaskManager::hapusNilai() {
    system("cls");
    cout << "=================" << endl;
    cout << "    Hapus Nilai  " << endl;
    cout << "=================" << endl;

    tampilkanNilai();

    if (nilai.empty()) {
        cout << "Nilai kosong." << endl;
        return;
    }

    cout << "Input nomor nilai yang ingin dihapus (ketik -1 untuk reset semua, 0 untuk kembali ke menu utama): ";
    int index;
    cin >> index;
    if (index == 0) return;
    else if (index == -1) {
        nilai.clear();
        cout << "Reset berhasil." << endl;
    } else if (index > 0 && index <= nilai.size()) {
        nilai.erase(nilai.begin() + index - 1);
        cout << "Nilai berhasil dihapus." << endl;
    } else {
        cout << "Input tidak valid." << endl;
    }

    char lagi;
    cout << "Ingin menghapus lagi (Y/N)? ";
    cin >> lagi;
    if (lagi == 'Y' || lagi == 'y') hapusNilai();
}

string TaskManager::getTanggalDanWaktuHariIni() const {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now);
    return string(buffer);
}

void TaskManager::simpanData() const {
    ofstream file("data.txt");

    if (!file.is_open()) {
        cerr << "Gagal membuka file untuk menyimpan data." << endl;
        return;
    }

    file << daftarTugas.size() << endl;
    for (const auto& task : daftarTugas) {
        file << task.nama << endl;
        file << task.keterangan << endl;
        file << task.deadline << endl;
        file << task.isDone << endl;
        file << task.selesai << endl;
    }

    file << jadwal.size() << endl;
    for (const auto& schedule : jadwal) {
        file << schedule.namaMakul << endl;
        file << schedule.namaDosen << endl;
        file << schedule.sks << endl;
        file << schedule.waktu << endl;
    }

    file << nilai.size() << endl;
    for (const auto& grade : nilai) {
        file << grade.semester << endl;
        file << grade.makul << endl;
        file << grade.absensi << endl;
        file << grade.tugas << endl;
        file << grade.uts << endl;
        file << grade.uas << endl;
        file << grade.total << endl;
        file << grade.grade << endl;
    }

    file.close();
}

void TaskManager::muatData() {
    ifstream file("data.txt");

    if (!file.is_open()) {
        cerr << "Gagal membuka file untuk memuat data." << endl;
        return;
    }

    size_t tugasSize, jadwalSize, nilaiSize;

    file >> tugasSize;
    file.ignore();
    daftarTugas.resize(tugasSize);
    for (auto& task : daftarTugas) {
        getline(file, task.nama);
        getline(file, task.keterangan);
        getline(file, task.deadline);
        file >> task.isDone;
        file.ignore();
        getline(file, task.selesai);
    }

    file >> jadwalSize;
    file.ignore();
    jadwal.resize(jadwalSize);
    for (auto& schedule : jadwal) {
        getline(file, schedule.namaMakul);
        getline(file, schedule.namaDosen);
        file >> schedule.sks;
        file.ignore();
        getline(file, schedule.waktu);
    }

    file >> nilaiSize;
    file.ignore();
    nilai.resize(nilaiSize);
    for (auto& grade : nilai) {
        getline(file, grade.semester);
        getline(file, grade.makul);
        file >> grade.absensi;
        file >> grade.tugas;
        file >> grade.uts;
        file >> grade.uas;
        file >> grade.total;
        file.ignore();
        getline(file, grade.grade);
    }

    file.close();
}
