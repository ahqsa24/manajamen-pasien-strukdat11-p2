// Fungsi untuk menampilkan menu login
void viewMainMenu();
void welcome();
void viewLoginMenu() {
    string username, password;
    cout << "== LOGIN ==" << endl;
    cout << "Masukkan username & password" << endl;
    cout << "Isi username anda : ";
    cin >> username;
    cout << "Isi password anda : ";
    cin >> password;

    if (muatDataAkunDariFile(username, password)) {
        cout << "\nLogin berhasil!!" << endl;
        // Panggil fungsi menu setelah login berhasil
        viewMainMenu();
    } else {
        cout << "\nLogin Gagal!!" << endl;
        // Tambahkan logika untuk mengulang proses login atau keluar dari aplikasi
        welcome();
    }
}