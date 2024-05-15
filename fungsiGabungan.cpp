#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include <iomanip>
#include <vector>
#include <unordered_map>

using namespace std;

// Hash Table
struct HashTable
{
    // data
    string username, password;
} dataAkun[26];

// Fungsi hash
int hashFunction(string key)
{
    return tolower(key[0]) - 97;
}

// Fungsi cekDaftar
bool cekDaftar(string username, string password)
{

    int index = hashFunction(password);

    // cek index masih kosong atau sudah ditempati
    if (dataAkun[index].username != "" && dataAkun[index].password != "")
    {
        // kalo sel index hash tidak table kosong
        cout << "User sudah ada!!" << endl;
        return false;
    }
    else
    {
        // kalo sel index di hash table kosong
        dataAkun[index].username = username;
        dataAkun[index].password = password;
        return true;
    }
}

// Fungsi cekLogin
bool cekLogin(string username, string password)
{
    // hashing dulu
    int index = hashFunction(password);

    // cek username & password bener gak
    if (dataAkun[index].username == username && dataAkun[index].password == password)
    {
        // kalo bener
        return true;
    }
    else
    {
        return false;
    }
}

// Fungsi cekHapusAkun
bool cekHapusAkun(int index)
{
    // cek apakah sel index di hash table kosong atau tidak
    if (dataAkun[index].username == "" && dataAkun[index].password == "")
    {
        // kalo selnya kosong
        cout << "\nData akun tidak ada!!" << endl;
        return false;
    }
    else
    {
        // kalo ada datanya
        dataAkun[index].username = "";
        dataAkun[index].password = "";
        return true;
    }
}

// Fungsi untuk menampilkan menu login
void viewMainMenu();
void welcome();
void viewLoginMenu()
{
    string username, password;
    cout << "== LOGIN ==" << endl;
    cout << "Masukkan username & password" << endl;
    cout << "Isi username anda : ";
    cin >> username;
    cout << "Isi password anda : ";
    cin >> password;

    if (cekLogin(username, password))
    {
        cout << "\nLogin berhasil!!" << endl;
        // Panggil fungsi menu setelah login berhasil
        viewMainMenu();
    }
    else
    {
        cout << "\nLogin Gagal!!" << endl;
        // Tambahkan logika untuk mengulang proses login atau keluar dari aplikasi
        welcome();
    }
}

void viewDaftar()
{
  string username, password;
  cout << "\n== MENU DAFTAR ==" << endl;
  cout << "Masukkan username & password" << endl;
  cout << "Isi Username anda : ";
  cin >> username;
  cout << "Isi Password anda : ";
  cin >> password;

  if( cekDaftar(username, password) ){
    cout << "Akun berhasil terdaftar!!" << endl;
  }else{
    cout << "Akun gagal terdaftar!!" << endl;
  }
  
}

// Fungsi 1 (Biodata) Start Here

// Deklarasi variabel di luar fungsi
const int MAX_RIWAYAT = 100;
string riwayatPenyakit[MAX_RIWAYAT];
int jumlahRiwayat = 0;

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
private:
    string nama;
    string nomor_identitas;
    int usia;
    string alamat;
    string kontak;
    vector<string> riwayatObat;

public:
    // Konstruktor untuk inisialisasi data pasien
    Pasien() {}

    Pasien(const string& _nama, const string& _nomor_identitas, int _usia, const string& _alamat, const string& _kontak)
        : nama(_nama), nomor_identitas(_nomor_identitas), usia(_usia), alamat(_alamat), kontak(_kontak) {
        // Constructor body
    }

    // Method to add riwayat obat
    void tambahRiwayatObat(const string& obat) {
        riwayatObat.push_back(obat);
    }

    // Method to display riwayat obat
    void tampilkanRiwayatObat() const {
        cout << "Riwayat obat untuk pasien " << nama << ":" << endl;
        for (const auto& obat : riwayatObat) {
            cout << obat << endl;
        }
    }

    // Fungsi untuk memasukkan biodata pasien
    void inputBiodata() {
        cout << "Masukkan nama pasien: ";
        cin >> nama;

        cout << "Masukkan nomor identitas pasien: ";
        cin >> nomor_identitas;

        cout << "Masukkan usia pasien: ";
        cin >> usia;

        cout << "Masukkan alamat pasien: ";
        cin.ignore(); // Membersihkan buffer
        getline(cin, alamat);

        cout << "Masukkan kontak pasien: ";
        getline(cin, kontak);

        // Tampilkan informasi biodata yang telah dimasukkan
        cout << "\n============================" << endl;
        cout << "Selamat datang, " << nama << "! Berikut adalah biodata Anda: " << endl;
        cout << "Nama: " << nama << endl;
        cout << "Nomor Identitas: " << nomor_identitas << endl;
        cout << "Usia: " << usia << endl;
        cout << "Alamat: " << alamat << endl;
        cout << "Kontak: " << kontak << endl;
        cout << "\n============================" << endl;
    }

    // Getter untuk mendapatkan informasi pasien
    string getNama() { return nama; }
    string getNomorIdentitas() { return nomor_identitas; }
    int getUsia() { return usia; }
    string getAlamat() { return alamat; }
    string getKontak() { return kontak; }
};

// Fungsi untuk memasukkan biodata dari fungsi Pasien
void inputBiodataPasien(Pasien& pasien) {
    pasien.inputBiodata();
}

// Fungsi 2 (Riwayat Penyakit) Start Here

void catatRiwayatPenyakit(string riwayat[], int& jumlah_riwayat) {
    Pasien pasien; // Declare an instance of the Pasien class
    cout << "Masukkan riwayat penyakit (Ketik 'selesai' untuk mengakhiri):" << endl;
    string penyakit;
    while (true) {
        cin >> penyakit;
        if (penyakit == "selesai") {
            break;
        }
        riwayat[jumlah_riwayat] = penyakit;
        jumlah_riwayat++;
    }

    cout << "\nRiwayat Penyakit Pasien " << pasien.getNama() << ":" << endl;
    for (int i = 0; i < jumlahRiwayat; i++) {
        cout << riwayatPenyakit[i] << endl;
    }
}

// Fungsi 3 (Riwayat Obat) Start Here
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

void viewRiwayatObat(ManajemenObat& manager, Pasien& pasien) {
    int pilihan;
    char opsiLanjut;

    do {
        manager.tampilkanDaftarPenyakit();

        cout << "Masukkan angka untuk jenis penyakit (0 untuk keluar): ";
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
            cout << "Obat untuk penyakit tersebut beserta resep pemakaiannya dan efek samping: " << medicine <<  endl;
            pasien.tambahRiwayatObat(medicine); // Tambahkan riwayat obat ke pasien
        } else {
            cout << "Obat belum tersedia. Silahkan masukkan input nomor lain." << endl;
            continue;
        }

        do {
            cout << "Tekan 'a' untuk melanjutkan pencarian, tekan 'b' untuk menyelesaikan pencarian: ";
            cin >> opsiLanjut;
            cin.ignore();

            if (opsiLanjut == 'a' || opsiLanjut == 'b') {
                break;
            } else {
                cout << "Input tidak valid. Harap masukkan 'a' atau 'b'." << endl;
            }
        } while (true);

        if (opsiLanjut == 'b') break;

    } while (true);

    cout << "Pencarian obat selesai. Riwayat obat telah ditambahkan pada data pasien." << endl;
}

// Fungsi 4 (Manajemen Obat) Start Here

void viewManajemenObat() {
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
                daftar_pasien[i].tambahRiwayatObat(obat); // Remove the extra argument 'efek'
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
}


// Fungsi 5 (Pencatatan Jadwal) Start Here

class Task {
public:
    string name;
    string description;
    time_t dueDate;
    string doctorName;
    string nurseSchedule;

    Task(string name, string description, time_t dueDate, string doctorName, string nurseSchedule) : name(name), description(description), dueDate(dueDate), doctorName(doctorName), nurseSchedule(nurseSchedule) {}

    void displayTask() const {
        cout << "Nama Jadwal: " << name << endl;
        cout << "Deskripsi: " << description << endl;
        cout << "Dokter: " << doctorName << endl;
        cout << "Jadwal Perawatan: " << nurseSchedule << endl;
        struct tm * timeinfo;
        timeinfo = localtime(&dueDate);
        char buffer[80];
        strftime(buffer, 80, "Batas Waktu: %d-%m-%Y %I:%M:%S", timeinfo);
        cout << buffer << endl;
    }
};

// Fungsi untuk mendapatkan input tugas baru dari pengguna
Task getTaskFromUser() {
    string name, description, nurseSchedule;
    int doctorChoice;
    vector<string> doctors = {"Dr. Tirta Saputra", "Dr. Boyke Prayoga", "Dr. Noorman Kamaru"};
    
    cout << "Nama Jadwal: ";
    getline(cin, name);
    cout << "Deskripsi: ";
    getline(cin, description);

    // Pilihan nama dokter
    cout << "Pilih nama dokter:" << endl;
    for (int i = 0; i < doctors.size(); ++i) {
        cout << i+1 << ". " << doctors[i] << endl;
    }
    cout << "Pilihan Anda: ";
    cin >> doctorChoice;
    cin.ignore(); // Membersihkan buffer
    if (doctorChoice < 1 || doctorChoice > doctors.size()) {
        cout << "Pilihan tidak valid, menggunakan default." << endl;
        doctorChoice = 1;
    }
    string doctorName = doctors[doctorChoice - 1];

    // Input tanggal dan jam
    int year, month, day, hour, minute;
    cout << "Masukkan tahun (YYYY): ";
    cin >> year;
    cout << "Masukkan bulan (1-12): ";
    cin >> month;
    cout << "Masukkan hari (1-31): ";
    cin >> day;
    cout << "Masukkan jam (0-23): ";
    cin >> hour;
    cout << "Masukkan menit (0-59): ";
    cin >> minute;

    cin.ignore(); // Membersihkan buffer
    struct tm tm_time;
    tm_time.tm_year = year - 1900;
    tm_time.tm_mon = month - 1;
    tm_time.tm_mday = day;
    tm_time.tm_hour = hour;
    tm_time.tm_min = minute;
    tm_time.tm_sec = 0;

    time_t dueDate = mktime(&tm_time);

    cout << "Jadwal Perawatan: " << setfill('0') << setw(2) << day << "-" << setfill('0') << setw(2) << month << "-" << year << " " << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << endl;
    
    return Task(name, description, dueDate, doctorName, nurseSchedule);
}

// Fungsi untuk menampilkan pengingat
void reminder(const Task& task) {
    cout << "Pengingat! Tugas berikut sudah melewati batas waktunya:" << endl;
    task.displayTask();
}

// Fungsi untuk pencatatan jadwal
void viewPencatatanJadwal()
{
    // Membuat vektor untuk menyimpan tugas-tugas
    vector<Task> tasks;

    // Menu utama
    int choice;
    do {
        cout << "\nPENYIMPANAN JADWAL PERAWATAN DAN PENGINGAT" << endl;
        cout << "\n============================" << endl;
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tambah Jadwal Perawatan" << endl;
        cout << "2. Edit Jadwal Perawatan" << endl;
        cout << "3. Hapus Jadwal Perawatan" << endl;
        cout << "4. Lihat Jadwal Perawatan" << endl;
        cout << "5. Keluar" << endl;
        cout << "\n============================" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        cin.ignore(); // Membersihkan buffer

        switch (choice) {
            case 1:
                tasks.push_back(getTaskFromUser());
                break;
            case 2:
                if (!tasks.empty()) {
                    cout << "Pilih nomor tugas yang ingin diedit: ";
                    int taskIndex;
                    cin >> taskIndex;
                    cin.ignore(); // Membersihkan buffer
                    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
                        tasks[taskIndex - 1] = getTaskFromUser();
                    } else {
                        cout << "Nomor tugas tidak valid." << endl;
                    }
                } else {
                    cout << "Tidak ada tugas yang bisa diedit." << endl;
                }
                break;
            case 3:
                if (!tasks.empty()) {
                    cout << "Pilih nomor tugas yang ingin dihapus: ";
                    int taskIndex;
                    cin >> taskIndex;
                    cin.ignore(); // Membersihkan buffer
                    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
                        tasks.erase(tasks.begin() + taskIndex - 1);
                    } else {
                        cout << "Nomor tugas tidak valid." << endl;
                    }
                } else {
                    cout << "Tidak ada tugas yang bisa dihapus." << endl;
                }
                break;
            case 4:
                if (!tasks.empty()) {
                    cout << "Jadwal Perawatan:" << endl;
                    int index = 1;
                    for (const auto& task : tasks) {
                        cout << index << ". ";
                        task.displayTask();
                        index++;
                    }
                } else {
                    cout << "Belum ada jadwal perawatan yang dimasukkan." << endl;
                }
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini. Sampai jumpa!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }

    } while (choice != 5);

    // Menampilkan pengingat jika ada tugas yang melewati batas waktu
    time_t currentTime = time(0);
    for (const auto& task : tasks) {
        if (task.dueDate < currentTime) {
            reminder(task);
        }
    }
}


// Fungsi untuk menampilkan menu utama setelah login berhasil
void viewMainMenu()
{
    Pasien pasien;
    ManajemenObat manager;
    int choice;
    while (true)
    {
        cout << "\n== MAIN MENU ==" << endl;
        cout << "Menu Pilihan :" << endl;
        cout << "1. Biodata" << endl;
        cout << "2. Riwayat Penyakit" << endl;
        cout << "3. Manajemen Obat" << endl;
        cout << "4. Riwayat Obat" << endl;
        cout << "5. Pencatatan Jadwal" << endl;
        cout << "6. Logout" << endl;
        cout << "Pilih menu [1/2/3/4/5/6] : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            {
                // Membuat objek Pasien baru
                Pasien pasien;
                // Panggil fungsi untuk biodata dengan objek pasien sebagai argumen
                inputBiodataPasien(pasien);
                break;
            }
        case 2:
            // Panggil fungsi untuk riwayat penyakit
            catatRiwayatPenyakit(riwayatPenyakit, jumlahRiwayat);
            break;
        case 3:
            // Panggil fungsi untuk riwayat obat
            viewRiwayatObat(manager, pasien);
            break;
        case 4:
            // Panggil fungsi untuk manajemen obat
            viewManajemenObat();
            break;
        case 5:
            // Panggil fungsi untuk pencatatan jadwal
            viewPencatatanJadwal();
            break;
        case 6:
            cout << "Anda berhasil logout" << endl;
            return;
        default:
            cout << "Pilihan tidak tersedia!!" << endl;
        }
    }
}

// Fungsi untuk tampilan utama
void welcome()
{
    while (true)
    {
        string pilihan;
        cout << "\n\n== SELAMAT DATANG! ==" << endl;
        cout << "Menu Pilihan :" << endl;
        cout << "1. Daftar" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu [1/2/3] : ";
        cin >> pilihan;

        if (pilihan == "1")
        {
            // Panggil fungsi untuk daftar
            viewDaftar();
        }
        else if (pilihan == "2")
        {
            viewLoginMenu();
            // Jika login berhasil, panggil fungsi untuk menu utama
            viewMainMenu();
        }
        else if (pilihan == "3")
        {
            cout << "\nTerimakasih" << endl;
            break;
        }
        else
        {
            cout << "Pilihan tidak tersedia!!" << endl;
        }
    }
}

int main()
{
    welcome();
    return 0;
}