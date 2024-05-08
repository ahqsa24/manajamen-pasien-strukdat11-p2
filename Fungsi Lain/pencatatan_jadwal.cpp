#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

// Kelas untuk menyimpan detail tugas
class Task {
public:
    string name;
    string description;
    time_t dueDate;
    string doctorName; // Nama dokter
    string nurseSchedule; // Jadwal perawatan perawat

    // Konstruktor untuk kelas Task
    Task(string name, string description, time_t dueDate, string doctorName, string nurseSchedule) : name(name), description(description), dueDate(dueDate), doctorName(doctorName), nurseSchedule(nurseSchedule) {}

    // Metode untuk menampilkan tugas
    void displayTask() const {
        cout << "Nama Tugas: " << name << endl;
        cout << "Deskripsi: " << description << endl;
        cout << "Dokter: " << doctorName << endl;
        cout << "Jadwal Perawatan: " << nurseSchedule << endl;
        // Mengonversi waktu dari detik menjadi tanggal
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
    vector<string> doctors = {"Dr. John Doe", "Dr. Jane Smith", "Dr. Michael Johnson"};
    
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

int main() {
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

    return 0;
}