#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class RiwayatObat {
public:
    RiwayatObat(string obat, string efek) : obat(obat), efek(efek) {}

    string getObat() const { return obat; }
    string getEfek() const { return efek; }

private:
    string obat;
    string efek;
};

class Pasien {
public:
    Pasien(string nama, string nomor_identitas, int usia, string alamat, string kontak) : nama(nama), nomor_identitas(nomor_identitas), usia(usia), alamat(alamat), kontak(kontak) {}

    string getNama() const { return nama; }

    void tambahRiwayatObat(string obat, string efek) {
        riwayat_obat.push_back(RiwayatObat(obat, efek));
    }

    void tampilkanRiwayatObat() const {
        cout << "Riwayat obat untuk " << nama << ":" << endl;
        for (const auto& riwayat : riwayat_obat) {
            cout << "Obat: " << riwayat.getObat() << endl;
            cout << "Efek: " << riwayat.getEfek() << endl;
            cout << endl;
        }
    }

private:
    string nama;
    string nomor_identitas;
    int usia;
    string alamat;
    string kontak;
    vector<RiwayatObat> riwayat_obat;
};

class ManajemenObat {
private:
    unordered_map<string, string> DatabaseObat;
    vector<string> DaftarPenyakit;

public:
    ManajemenObat() {
        DatabaseObat["Dermatitis"] = "Clobetasol, resep : Oleskan tipis-tipis pada area yang terkena dermatitis, Efek samping: iritasi kulit, kemerahan";
        DatabaseObat["Demam"] = "Ibuprofen, resep : 3 kali sehari, Efek samping: sakit perut, mual";
        DatabaseObat["Analgesik"] = "Paracetamol, resep : 1 tablet setiap 4-6 jam sesuai kebutuhan, Efek samping: kerusakan hati";
        DatabaseObat["Asma"] = "Salbutamo, resep : Inhalasikan 2 kali saat terjadi serangan asmal, Efek samping: jantung berdebar, gemetar";
        DatabaseObat["Darah Tinggi"] = "Bystolic, resep : 1 tablet setiap hari pada pagi hari, Efek samping: pusing, lelah";
        DatabaseObat["Leukimia"] = "Sprycel, resep :  1 tablet setiap hari dengan makanan, Efek samping: mual, muntah";
        DatabaseObat["Diabetes"] = "Metformin, resep : 1 tablet setiap seteh makan pagi dan malam, Efek samping: diare, perut kembung";
        DatabaseObat["Kanker"] = "Cisplatin, resep : Diberikan oleh dokter sesuai dengan jadwal kemoterapi, Efek samping: kerontokan rambut, mual";
        DatabaseObat["HIV/AIDS"] = "Tenofovir, resep : 1 tablet setiap hari pada waktu yang sama setiap hari,  Efek samping: gangguan tidur, pusing";
        DatabaseObat["Hipertensi"] = "Bystolic, resep : 1 tablet setiap hari pada pagi hari, Efek samping: penurunan libido, impotensi";

        for (auto& pair : DatabaseObat) {
            DaftarPenyakit.push_back(pair.first);
        }
    }

    void tampilkanDaftarPenyakit() const {
        cout << "Daftar Penyakit:\n";
        for (int i = 0; i < DaftarPenyakit.size(); ++i) {
            cout << i+1 << ". " << DaftarPenyakit[i] << endl;
        }
    }

    string getMedicineByNumber(int number) const {
        if (number > 0 && number <= DaftarPenyakit.size()) {
            string disease = DaftarPenyakit[number - 1];
            return DatabaseObat.at(disease);
        } else {
            return "Invalid selection";
        }
    }
};

int main() {
    ManajemenObat manager;
    vector<Pasien> daftar_pasien;
    int jumlahPasien;

    cout << "Masukkan jumlah pasien: ";
    cin >> jumlahPasien;

    for (int i = 0; i < jumlahPasien; ++i) {
        string nama, nomor_identitas, alamat, kontak;
        int usia;
        
        cout << "Masukkan data pasien ke-" << i + 1 << ":" << endl;
        cout << "Nama: ";
        cin >> nama;
        cout << "Nomor Identitas: ";
        cin >> nomor_identitas;
        cout << "Usia: ";
        cin >> usia;
        cout << "Alamat: ";
        cin >> alamat;
        cout << "Kontak: ";
        cin >> kontak;

        daftar_pasien.push_back(Pasien(nama, nomor_identitas, usia, alamat, kontak));
    }

    for (int i = 0; i < daftar_pasien.size(); ++i) {
        cout << "Masukkan riwayat obat untuk " << daftar_pasien[i].getNama() << endl;

        char lanjut;
        do {
            manager.tampilkanDaftarPenyakit();

            cout << "Masukkan angka untuk jenis penyakit (0 untuk keluar): ";
            int pilihan;
            cin >> pilihan;

            if (cin.fail()) {
                cout << "Input tidak valid. Silahkan masukkan nomor penyakit." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (pilihan == 0) break;

            string medicine = manager.getMedicineByNumber(pilihan);
            if (medicine != "Invalid selection") {
                string obat = medicine.substr(0, medicine.find(", resep :"));
                string efek = medicine.substr(medicine.find(", Efek samping: ") + 16);
                daftar_pasien[i].tambahRiwayatObat(obat, efek);
            } else {
                cout << "Obat belum tersedia. Silahkan masukkan input nomor lain." << endl;
                continue;
            }

            cout << "Apakah ada riwayat obat lain untuk " << daftar_pasien[i].getNama() << " (y/n)? ";
            cin >> lanjut;
        } while (lanjut == 'y' || lanjut == 'Y');
    }

    for (int i = 0; i < daftar_pasien.size(); ++i) {
        daftar_pasien[i].tampilkanRiwayatObat();
    }

    return 0;
}