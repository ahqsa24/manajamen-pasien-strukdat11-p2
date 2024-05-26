void loadBiodataFromFile() {
    ifstream file("biodata.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    string line, nama, nomor_identitas, alamat, kontak;
    int usia;
    vector<string> riwayatPenyakit;

    while (getline(file, line)) {
        if (line.find("Nama: ") != string::npos) {
            nama = line.substr(6); // Ambil substring setelah "Nama: "
            getline(file, line);
            nomor_identitas = line.substr(18); // Ambil substring setelah "Nomor Identitas: "
            getline(file, line);
            usia = stoi(line.substr(6)); // Ambil usia setelah "Usia: "
            getline(file, line);
            alamat = line.substr(8); // Ambil substring setelah "Alamat: "
            getline(file, line);
            kontak = line.substr(8); // Ambil substring setelah "Kontak: "

            // Membaca riwayat penyakit
            riwayatPenyakit.clear();
            while (getline(file, line) && line.find("Penyakit: ") != string::npos) {
                riwayatPenyakit.push_back(line.substr(10)); // Ambil substring setelah "Penyakit: "
            }

            Pasien pasien(nama, nomor_identitas, usia, alamat, kontak);
            pasien.setRiwayatPenyakit(riwayatPenyakit);
            biodataPasien[nama] = pasien;
        }
    }

    file.close();
}
