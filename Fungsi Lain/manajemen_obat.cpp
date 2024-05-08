#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class ManajemenObat {
private:
    unordered_map<string, string> DatabaseObat;
    vector<string> DaftarPenyakit;

public:
    ManajemenObat() {
        // Menginisialisasi database obat
        DatabaseObat["Dermatitis"] = "Clobetasol, Oleskan tipis-tipis pada area yang terkena dermatitis";
        DatabaseObat["Demam"] = "Ibuprofen, 3 kali sehari";
        DatabaseObat["Analgesik"] = "Paracetamol, 1 tablet setiap 4-6 jam sesuai kebutuhan";
        DatabaseObat["Asma"] = "Salbutamo, Inhalasikan 2 kali saat terjadi serangan asmal";
        DatabaseObat["Darah Tinggi"] = "Bystolic, 1 tablet setiap hari pada pagi hari";
        DatabaseObat["Leukimia"] = "Sprycel, 1 tablet setiap hari dengan makanan";
        DatabaseObat["Diabetes"] = "Metformin, 1 tablet setiap setelah makan pagi dan malam";
        DatabaseObat["Kanker"] = "Cisplatin, Diberikan oleh dokter sesuai dengan jadwal kemoterapi";
        DatabaseObat["HIV/AIDS"] = "Tenofovir, 1 tablet setiap hari pada waktu yang sama setiap hari";
        DatabaseObat["Hipertensi"] = "Bystolic, 1 tablet setiap hari pada pagi hari";

        // Menginisialisasi daftar penyakit
        for (auto& pair : DatabaseObat) {
            DaftarPenyakit.push_back(pair.first);
        }
    }

    void tampilkanDaftarPenyakit() {
        cout << "Daftar Penyakit:\n";
        for (int i = 0; i < DaftarPenyakit.size(); ++i) {
            cout << i+1 << ". " << DaftarPenyakit[i] << endl;
        }
    }

    string getMedicineByNumber(int number) {
        if (number > 0 && number <= DaftarPenyakit.size()) {
            string disease = DaftarPenyakit[number - 1];
            return DatabaseObat[disease];
        } else {
            return "Invalid selection";
        }
    }
};

int main() {
    ManajemenObat manager;
    int pilihan;
    char opsiLanjut;

    do {
        manager.tampilkanDaftarPenyakit();

        // Meminta pengguna memasukkan angka untuk jenis penyakit
        cout << "Masukkan angka untuk jenis penyakit (0 untuk keluar): ";
        cin >> pilihan;

        // Membaca ulang input jika input tidak berupa angka
        if (cin.fail()) {
            cout << "Input tidak valid. Silahkan masukkan nomor penyakit." << endl;
            cin.clear(); // Menghapus status error pada cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus karakter yang tersisa di buffer
            continue;
        }

        if (pilihan == 0) break;

        string medicine = manager.getMedicineByNumber(pilihan);
        if (medicine != "Invalid selection") {
            cout << "Obat untuk penyakit tersebut beserta resep pemakaiannya adalah: " << medicine <<  endl;
        } else {
            cout << "Obat belum tersedia. Silahkan masukkan input nomor lain." << endl;
            continue;
        }

        do {
            cout << "Tekan 'a' untuk melanjutkan pencarian, tekan 'b' untuk menyelesaikan pencarian: ";
            cin >> opsiLanjut;
            cin.ignore();

            if (opsiLanjut == 'a') {
                break;
            } else if (opsiLanjut == 'b') {
                break;
            } else {
                cout << "Input tidak valid. Harap masukkan 'a' atau 'b'." << endl;
            }
        } while (true);

        if (opsiLanjut == 'b') break;

    } while (true);

    cout << "Pencarian obat selesai, Semoga Lekas Sembuh." << endl;
    cout << "-dr Sulthan Farras Razin-\n" << endl;

    return 0;
}