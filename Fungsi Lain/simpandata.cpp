#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Deklarasi variabel untuk menyimpan data
    string nama, alamat;
    int kontak, id, usia;

    // Buka file dengan mode append
    ofstream dataPasien("dataPasien.txt", ios::app);

    // Periksa apakah file berhasil dibuka
    if (!dataPasien.is_open()) {
        cout << "Gagal membuka file." << endl;
        return 1;
    }

    // Buat menambahkan data pasien baru
    char jawab;
    do {
        cout << "\n\t Cetak Data Pasien ke Dalam File txt \n\n";

        cout << " Masukkan  Nama : ";
        cin >> nama;

        cout << " Masukkan Usia : ";
        cin >> usia;

        cout << " Masukkan ID : ";
        cin >> id;

        cout << " Masukkan Kontak : ";
        cin >> kontak;

        cout << " Masukkan Alamat : ";
        cin >> alamat;

        // Menulis data ke file dengan mode append
        dataPasien << "\t Data-data Pasien \n";
        dataPasien << "\n Nama   : " <<  nama;
        dataPasien << "\n Usia   : " <<  usia;
        dataPasien << "\n Id     : " <<  id;
        dataPasien << "\n Kontak : " <<  kontak;
        dataPasien << "\n Alamat : " <<  alamat;
        dataPasien << "\n <======================> \n";

        // Tanyakan apakah ingin menambahkan data lagi
        cout << "Ingin menambahkan data pasien lagi? (y/n): ";
        cin >> jawab;
    } while (jawab == 'y' || jawab == 'Y');

    // Tutup file setelah selesai menulis
    dataPasien.close();

    cout << endl << "Data berhasil disimpan." << endl;
    return 0;
}
