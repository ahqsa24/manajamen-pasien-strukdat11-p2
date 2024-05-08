#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Pasien {
private:
    string nama;
    string nomor_identitas;
    int usia;
    string alamat;
    string kontak;

public:
    // Konstruktor untuk inisialisasi data pasien
    Pasien() {
        // Meminta pengguna untuk memasukkan informasi pasien
        cout << "Masukkan nama pasien: ";
        getline(cin, nama);

        cout << "Masukkan nomor identitas pasien: ";
        getline(cin, nomor_identitas);

        cout << "Masukkan usia pasien: ";
        cin >> usia;

        cout << "Masukkan alamat pasien: ";
        cin.ignore(); // Membersihkan buffer
        getline(cin, alamat);

        cout << "Masukkan kontak pasien: ";
        getline(cin, kontak);
    }

    // Getter untuk mendapatkan informasi pasien
    string getNama() { return nama; }
    string getNomorIdentitas() { return nomor_identitas; }
    int getUsia() { return usia; }
    string getAlamat() { return alamat; }
    string getKontak() { return kontak; }
};

void catatRiwayatPenyakit(string riwayat[], int& jumlah_riwayat) {
    cout << "Masukkan riwayat penyakit (Ketik 'selesai' untuk mengakhiri):" << endl;
    string penyakit;
    while (true) {
        getline(cin, penyakit);
        if (penyakit == "selesai") {
            break;
        }
        riwayat[jumlah_riwayat] = penyakit;
        jumlah_riwayat++;
    }
}

int main() {
    const int MAX_RIWAYAT = 100;
    string riwayatPenyakit[MAX_RIWAYAT];
    int jumlahRiwayat = 0;

    // Membuat objek pasien dengan biodata yang dimasukkan oleh pengguna
    Pasien pasien;

    // Memanggil fungsi untuk mencatat riwayat penyakit
    catatRiwayatPenyakit(riwayatPenyakit, jumlahRiwayat);

    // Menampilkan riwayat penyakit yang telah dicatat
    cout << "\nBiodata Pasien:" << endl;
    cout << "Nama: " << pasien.getNama() << endl;
    cout << "Nomor Identitas: " << pasien.getNomorIdentitas() << endl;
    cout << "Usia: " << pasien.getUsia() << endl;
    cout << "Alamat: " << pasien.getAlamat() << endl;
    cout << "Kontak: " << pasien.getKontak() << endl;

    cout << "\nRiwayat Penyakit Pasien " << pasien.getNama() << ":" << endl;
    for (int i = 0; i < jumlahRiwayat; ++i) {
        cout << i + 1 << ". " << riwayatPenyakit[i] << endl;
    }

    return 0;
}