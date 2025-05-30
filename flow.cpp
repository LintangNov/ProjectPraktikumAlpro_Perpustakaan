#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

/* PROTOTYPE FUNGSI */

// Bagian Pustakawan
void loginPustakawan();
void menuPustakawan();
void menuPengunjung();

// Bagian Pengunjung
int signInPengunjung();
void signUpPengunjung();

// Bagian Buku Buku (Pustakawan)
void tambahDataBuku();
void hapusDataBuku();
void ubahDataBuku();

// Bagian Buku Buku (Pengunjung)
void CariBuku();
void lihatDataBuku();
void pinjamBuku();
void lihatDataBukuTahunTerbit();
void lihatDataBukuJudul();
void lihatDataBukuID();

// Bagian Data Diri Pengunjung
void lihatDataDiri();

// Function Umum
void sequentialTahun(int cariTahun);
void sequentialString(string cariPengarang);
void ShellSort(int n);
void BubbleSortString(int n);
void QuickSort(int low, int high);
void MasukkanDataKeFile(const string &namafile);
void SalinDatadariFilekeArray(const string &namafile);
void center(string text, string batasSamping, int tabelLength);

struct buku
{
    int idBuku;
    string judul;
    int tahunTerbit;
    string pengarang;
    string penerbit;
};

struct pustakawan{
    string username;
    string password;
} data_pustakawan[]={
    {"fahmi", "123240055"},
    {"lintang", "123240065"},
};

string username, password, tgl_lahir, alamat, no_telp, email;

buku data_buku[201] = {
    {0},
};

// ===========================
// MAIN FUNCTION
// ===========================
int main()
{
    SalinDatadariFilekeArray("data_buku.txt");
    int mainMenuChoice;
    int pengunjungChoice;

    do
    {
        system("cls");
        cout << string(50, '-') << endl;
        center("Sistem Peminjaman Buku Perpustakaan", "|", 50);
        cout << string(50, '-') << endl;
        cout << "1. Masuk sebagai Pengunjung" << endl;
        cout << "2. Masuk sebagai Pustakawan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> mainMenuChoice;

        int login;
        switch (mainMenuChoice)
        {
        case 1:
            do
            {
                system("cls");
                cout << string(40, '-') << endl;
                center("Pengunjung", "|", 40);
                cout << string(40, '-') << endl;
                cout << "1. Sign In" << endl;
                cout << "2. Sign Up" << endl;
                cout << "3. Kembali" << endl;
                cout << "Pilihan: ";
                cin >> pengunjungChoice;

                switch (pengunjungChoice)
                {
                case 1:
                    login = signInPengunjung();
                    if (login != 0){
                        menuPengunjung();
                    } else {
                        cout << "Login gagal! Silahkan cek apakah username dan password benar.";
                        cout << "\nTekan enter untuk kembali...";
                        cin.ignore();
                        cin.get();
                    }
                    break;
                case 2:
                    signUpPengunjung();
                    break;
                case 3:
                    break;;
                default:
                    cout << "Pilihan tidak valid." << endl;
                }
            } while (pengunjungChoice != 3);
            break;
        case 2:
            loginPustakawan();
            break;
        case 3:
            cout << "\nKeluar dari sistem. Terima kasih!\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (mainMenuChoice != 3);
}

// ===========================
// Bagian Pustakawan
// ===========================
void loginPustakawan()
{
    system("cls");
    cout << string(40, '-') << endl;
    center("Login Pustakawan", "|", 40);
    cout << string(40, '-') << endl;
    string usn, pass;
    cout << "Username: ";
    cin >> usn;
    cout << "Password: ";
    cin >> pass;
    bool ketemu = false;
    for (int i = 0; i < sizeof(data_pustakawan) / sizeof(data_pustakawan[0]); i++)
    {
        if (data_pustakawan[i].username == usn && data_pustakawan[i].password == pass)
        {
            cout << "Login berhasil!! \nSelamat datang " << data_pustakawan[i].username << endl;
            ketemu = true;
            system("pause");
            menuPustakawan();
        }
    }
    if (!ketemu)
    {
        cout << "Username atau password salah!\n";
        system("pause");
        loginPustakawan();
    }
}

void menuPustakawan()
{
    int userMenuChoice;
    do
    {
        system("cls");
        cout << string(40, '-') << endl;
        center("Menu Pustakawan", "|", 40);
        cout << string(40, '-') << endl;
        cout << "1. Tambah Data Buku" << endl;
        cout << "2. Hapus Data Buku" << endl;
        cout << "3. Ubah Data Buku" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilihan: ";
        cin >> userMenuChoice;

        switch (userMenuChoice)
        {
        case 1:
            tambahDataBuku();
            break;
        case 2:
            hapusDataBuku();
            break;
        case 3:
            ubahDataBuku();
            break;
        case 4:
            MasukkanDataKeFile("data_buku.txt");
            cout << "\nLogout dari akun Pustakawan.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (userMenuChoice != 4);
}

void menuPengunjung() {
    
    int pengunjungMenuChoice;
    do
    {
        system("cls");
        cout << string(40, '-') << endl;
        center("Menu Pengunjung", "|", 40);
        cout << string(40, '-') << endl;
        cout << "1. Cari Buku" << endl;
        cout << "2. Lihat Data Buku" << endl;
        cout << "3. Pinjam Buku" << endl;
        cout << "4. Lihat Data Diri" << endl;
        cout << "5. Logout" << endl;
        cout << "Pilihan: ";
        cin >> pengunjungMenuChoice;

        switch (pengunjungMenuChoice)
        {
        case 1:
            CariBuku();
            break;
        case 2:
            lihatDataBuku();
            break;
        case 3:
            pinjamBuku();
            break;
        case 4:
            lihatDataDiri();
            break;
        case 5:
            cout << "\nLogout dari akun Pengunjung.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pengunjungMenuChoice != 5);
}

// ===========================
// Bagian Pengunjung
// ===========================
int signInPengunjung(){
    system("cls");
    cout << string(40, '-') << endl;
    center("Sign In Pengunjung", "|", 40);
    cout << string(40, '-') << endl;
    string usn, pass;
    cout << "Username: ";
    cin >> usn;
    cout << "Password: ";
    cin >> pass;
    ifstream filePengunjung("data_pengunjung.txt");
    if (!filePengunjung.is_open())
    {
        cout << "Gagal membuka file data pengunjung!\n";
        return 0;
    }
    string baris;
    int counter=0;
    while (getline(filePengunjung, baris)) {
        if (baris == "<<== START ==>>") {
            counter++;
            string usernameFile, passwordFile;
            getline(filePengunjung, baris); // Username
            usernameFile = baris.substr(baris.find(":") + 2);
            getline(filePengunjung, baris); // Tanggal Lahir
            tgl_lahir = baris.substr(baris.find(":") + 2);
            getline(filePengunjung, baris); // Alamat
            alamat = baris.substr(baris.find(":") + 2);
            getline(filePengunjung, baris); // No. Telepon
            no_telp = baris.substr(baris.find(":") + 2);
            getline(filePengunjung, baris); // Email
            email = baris.substr(baris.find(":") + 2);
            getline(filePengunjung, baris); // Password
            passwordFile = baris.substr(baris.find(":") + 2);

            if (usernameFile == usn && passwordFile == pass) {

                stringstream ss(baris);
                username = usernameFile;
                password = passwordFile;

                cout << "Login berhasil!\n";
                cout << "Selamat datang, " << usernameFile << "!\n";
                filePengunjung.close();
                system("pause");
                return counter;
            }
        }
    }

    if (counter == 0){
        cout << "Username atau password salah!\n";
        system("pause");
    }
    return 0;
}

void signUpPengunjung()
{
    // Cek username sudah ada atau belum
    ifstream fileCek("data_pengunjung.txt");
    if (!fileCek.is_open()) {
        cout << "Gagal membuka file untuk membaca data!\n";
        return;
    }
    system("cls");
    cout << string(40, '-') << endl;
    center("Sign Up", "|", 40);
    cout << string(40, '-') << endl;
    cout << "Masukkan username baru: ";
    cin >> username;
    string baris;
    while (getline(fileCek, baris)) {
        if (baris == "<<== START ==>>") {
            string usernameFile;
            getline(fileCek, baris); // Username
            usernameFile = baris.substr(10);
            if (username == usernameFile) {
                cout << "Username sudah ada! Silahkan coba username lain.\n";
                fileCek.close();
                system("pause");
                signUpPengunjung();
                return;
            }
        }
    }
    fileCek.close();

    cout << "Masukkan tanggal lahir (DD/MM/YYYY): ";
    cin >> tgl_lahir;
    cout << "Masukkan alamat: ";
    cin.ignore();
    getline(cin, alamat);
    cout << "Masukkan nomor telepon: ";
    cin >> no_telp;
    cout << "Masukkan email: ";
    cin >> email;
    cout << "Masukkan password baru: ";
    cin >> password;

    ofstream filePengunjung("data_pengunjung.txt", ios::app);
    if (!filePengunjung.is_open()) {
        cout << "Gagal membuka file untuk menyimpan data!\n";
        return;
    }
    filePengunjung << "<<== START ==>>" << endl;
    filePengunjung << "Username: " << username << endl;
    filePengunjung << "Tanggal Lahir: " << tgl_lahir << endl;
    filePengunjung << "Alamat: " << alamat << endl;
    filePengunjung << "No. Telepon: " << no_telp << endl;
    filePengunjung << "Email: " << email << endl;
    filePengunjung << "Password: " << password << endl;
    filePengunjung << "<<== END ==>>" << endl;
    filePengunjung.close();
    cout << "\nAkun berhasil dibuat! Silakan login.\n";
    system("pause");
}

// ===========================
// Bagian Buku Buku (Pustakawan)
// ===========================
void tambahDataBuku()
{
    system("cls");
    cout << string(40, '-') << endl;
    center("Daftar Buku Saat Ini", "|", 40);
    cout << string(40, '-') << endl;
    cout << left << setw(4) << setfill(' ') << "ID"
         << setw(30) << "Judul"
         << setw(25) << "Pengarang"
         << setw(15) << "Penerbit"
         << setw(6) << "Tahun" << endl;
    for (int i = 1; i <= 200; i++) {
        if (data_buku[i].idBuku != 0) {
            cout << left << setw(4) << setfill(' ') << data_buku[i].idBuku
                 << setw(30) << data_buku[i].judul
                 << setw(25) << data_buku[i].pengarang
                 << setw(15) << data_buku[i].penerbit
                 << setw(6) << data_buku[i].tahunTerbit << endl;
        }
    }
    cout << endl;
    cout << string(40, '-') << endl;
    center("Tambah Data Buku", "|", 40);
    cout << string(40, '-') << endl;
    // Cari slot kosong
    int idx = -1;
    for (int i = 1; i <= 200; i++)
    {
        if (data_buku[i].idBuku == 0)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "Database buku sudah penuh!\n";
        system("pause");
        return;
    }
    data_buku[idx].idBuku = idx;
    cout << "ID Buku: " << idx << endl;
    cout << "Masukkan Judul Buku: ";
    cin.ignore();
    getline(cin, data_buku[idx].judul);
    cout << "Masukkan Tahun Terbit: ";
    cin >> data_buku[idx].tahunTerbit;
    cin.ignore();
    cout << "Masukkan Pengarang: ";
    getline(cin, data_buku[idx].pengarang);
    cout << "Masukkan Penerbit: ";
    getline(cin, data_buku[idx].penerbit);
    cout << "\nData buku berhasil ditambahkan.\n";
    system("pause");
}

void hapusDataBuku()
{
    system("cls");
    cout << string(40, '-') << endl;
    center("Daftar Buku Saat Ini", "|", 40);
    cout << string(40, '-') << endl;
    cout << left << setw(4) << setfill(' ') << "ID"
         << setw(30) << "Judul"
         << setw(25) << "Pengarang"
         << setw(15) << "Penerbit"
         << setw(6) << "Tahun" << endl;
    for (int i = 1; i <= 200; i++) {
        if (data_buku[i].idBuku != 0) {
            cout << left << setw(4) << setfill(' ') << data_buku[i].idBuku
                 << setw(30) << data_buku[i].judul
                 << setw(25) << data_buku[i].pengarang
                 << setw(15) << data_buku[i].penerbit
                 << setw(6) << data_buku[i].tahunTerbit << endl;
        }
    }
    cout << endl;
    cout << string(40, '-') << endl;
    center("Hapus Data Buku", "|", 40);
    cout << string(40, '-') << endl;
    int id;
    cout << "Masukkan ID Buku yang ingin dihapus (0 untuk batal): ";
    cin >> id;
    if (id == 0) {
        cout << "Penghapusan dibatalkan.\n";
        system("pause");
        return;
    }
    // Cari buku berdasarkan ID
    for (int i = 1; i <= 200; i++)
    {
        if (data_buku[i].idBuku == id)
        {
            data_buku[i] = {0}; // Menghapus data buku
            for (int j = i; j < 200; j++) {
                if (data_buku[j+1].idBuku == 0){
                    data_buku[j] = {0}; 
                    break;
                }
                data_buku[j+1].idBuku = j;
                data_buku[j] = data_buku[j + 1]; // Geser data ke kiri
            }
            cout << "Data buku berhasil dihapus.\n";
            system("pause");
            return;
        }
    }
    cout << "Buku dengan ID tersebut tidak ditemukan.\n";
    system("pause");
}

void ubahDataBuku()
{
    system("cls");
    cout << string(40, '-') << endl;
    center("Daftar Buku Saat Ini", "|", 40);
    cout << string(40, '-') << endl;
    cout << left << setw(4) << setfill(' ') << "ID"
         << setw(30) << "Judul"
         << setw(25) << "Pengarang"
         << setw(15) << "Penerbit"
         << setw(6) << "Tahun" << endl;
    for (int i = 1; i <= 200; i++) {
        if (data_buku[i].idBuku != 0) {
            cout << left << setw(4) << setfill(' ') << data_buku[i].idBuku
                 << setw(30) << data_buku[i].judul
                 << setw(25) << data_buku[i].pengarang
                 << setw(15) << data_buku[i].penerbit
                 << setw(6) << data_buku[i].tahunTerbit << endl;
        }
    }
    cout << endl;
    cout << string(40, '-') << endl;
    center("Ubah Data Buku", "|", 40);
    cout << string(40, '-') << endl;

    int id, pilihan;
    bool ditemukan = false;
    cout << "Masukkan ID Buku yang ingin diubah: ";
    cin >> id;
    // Cari buku berdasarkan ID
    for (int i = 1; i <= 200; i++)
    {
        if (data_buku[i].idBuku == id)
        {
            ditemukan = true;
            cout << "\nData Buku Saat Ini:" << endl;
            cout << "1. Judul      : " << data_buku[i].judul << endl;
            cout << "2. Tahun Terbit: " << data_buku[i].tahunTerbit << endl;
            cout << "3. Pengarang  : " << data_buku[i].pengarang << endl;
            cout << "4. Penerbit   : " << data_buku[i].penerbit << endl;

            cout << "\nPilih data yang ingin diubah:" << endl;
            cout << "1. Judul\n2. Tahun Terbit\n3. Pengarang\n4. Penerbit\nPilihan: ";
            cin >> pilihan;
            cin.ignore(); // Bersihkan buffer

            switch (pilihan)
            {
            case 1:
                cout << "Masukkan judul baru: ";
                getline(cin, data_buku[i].judul);
                break;
            case 2:
                cout << "Masukkan tahun terbit baru: ";
                cin >> data_buku[i].tahunTerbit;
                break;
            case 3:
                cout << "Masukkan pengarang baru: ";
                getline(cin, data_buku[i].pengarang);
                break;
            case 4:
                cout << "Masukkan penerbit baru: ";
                getline(cin, data_buku[i].penerbit);
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
            }
            cout << "\nData buku berhasil diubah.\n";
            system("pause");
            return;
        }
    }
    if (!ditemukan)
    {
        cout << "Buku dengan ID tersebut tidak ditemukan.\n";
        system("pause");
    }
}

// ===========================
// Bagian Buku Buku (Pengunjung)
// ===========================
void CariBuku()
{
    system("cls");
    cout << string(40, '-') << endl;
    center("Cari Buku", "|", 40);
    cout << string(40, '-') << endl;
    int i;
    int cariTahun;
    string cari;
    int basedOn;
    cout << "\n==== Cari Buku Berdasarkan ====" << endl;
    cout << "1. Judul" << endl;
    cout << "2. Pengarang" << endl;
    cout << "3. Penerbit" << endl;
    cout << "4. Tahun Terbit" << endl;
    cout << "Pilih berdasarkan: ";
    cin >> basedOn;
    switch (basedOn)
    {
    case 1:
        cout << "Masukkan judul buku yang dicari: ";
        cin.ignore();
        getline(cin, cari);
        sequentialString(cari);
        break;
    case 2:
        cout << "Masukkan nama pengarang buku yang dicari: ";
        cin.ignore();
        getline(cin, cari);
        sequentialString(cari);
        break;
    case 3:
        cout << "Masukkan nama penerbit buku yang dicari: ";
        cin.ignore();
        getline(cin, cari);
        sequentialString(cari);
        break;
    case 4:
        cout << "Masukkan tahun terbit yang dicari: ";
        cin >> cariTahun;
        sequentialTahun(cariTahun);
        break;
    default:
        break;
    }
    cout << "Tekan apa saja untuk kembali......\n";
    cin.ignore();
    cin.get();

}

void lihatDataBuku()
{
    cout << string(40, '-') << endl;
    center("Daftar Buku", "|", 40);
    cout << string(40, '-') << endl;
    int pilihan;
    cout << "\nUrutkan Berdasarkan: \n";
    cout << "1. Judul" << endl;
    cout << "2. Tahun Terbit" << endl;
    cout << "3. ID Buku" << endl;
    cout << "4. Kembali ke Menu Utama" << endl;
    cout << "Pilih opsi: ";
    cin >> pilihan;

    switch (pilihan)
    {
    case 1:
        lihatDataBukuJudul();
        break;
    case 2:
        lihatDataBukuTahunTerbit();
        break;
    case 3:
        lihatDataBukuID();
        break;
    default:
        break;
    }
}

void pinjamBuku() {
    system("cls");
    int idPinjam;
    cout << "=== Pinjam Buku ===" << endl;
    cout << "Masukkan ID Buku yang ingin dipinjam: ";
    cin >> idPinjam;

    // Cari buku berdasarkan ID
    bool ditemukan = false;
    for (int i = 1; i <= 50; i++)
    {
        if (data_buku[i].idBuku == idPinjam)
        {
            ditemukan = true;
            cout << "\nBuku yang akan dipinjam:" << endl;
            cout << "Judul      : " << data_buku[i].judul << endl;
            cout << "Pengarang  : " << data_buku[i].pengarang << endl;
            cout << "Penerbit   : " << data_buku[i].penerbit << endl;
            cout << "Tahun Terbit: " << data_buku[i].tahunTerbit << endl;
            cout << "\nBuku berhasil dipinjam!\n";
            // Jika ingin menandai buku sudah dipinjam, bisa tambahkan status di struct buku
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Buku dengan ID tersebut tidak ditemukan.\n";
    }
    cout << "\nTekan enter untuk kembali...";
    cin.ignore();
    cin.get();
}

void lihatDataBukuTahunTerbit()
{
    system("cls");
    cout << "\n=== Daftar Buku Berdasarkan Tahun Terbit ===" << endl;
    int n = sizeof(data_buku) / sizeof(data_buku[0]);
    ShellSort(n);
    cout << left << setw(4) << setfill(' ') << "ID"
         << setw(30) << "Judul"
         << setw(25) << "Pengarang"
         << setw(15) << "Penerbit"
         << setw(6) << "Tahun" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (data_buku[i].idBuku != 0)
        {
            cout << left << setw(4) << setfill(' ') << data_buku[i].idBuku
                 << setw(30) << data_buku[i].judul
                 << setw(25) << data_buku[i].pengarang
                 << setw(15) << data_buku[i].penerbit
                 << setw(6) << data_buku[i].tahunTerbit << endl;
        }
    }
    cout << "\nTekan enter untuk kembali...";
    cin.ignore();
    cin.get();
}

void lihatDataBukuJudul()
{
    system("cls");
    cout << string(40, '-') << endl;
    center("Daftar Buku Berdasarkan Judul", "|", 40);
    cout << string(40, '-') << endl;
    int n = sizeof(data_buku) / sizeof(data_buku[0]);
    BubbleSortString(n);
    cout << left << setw(4) << setfill(' ') << "ID"
         << setw(30) << "Judul"
         << setw(25) << "Pengarang"
         << setw(15) << "Penerbit"
         << setw(6) << "Tahun" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (data_buku[i].idBuku != 0)
        {
            cout << left << setw(4) << setfill(' ') << data_buku[i].idBuku
                 << setw(30) << data_buku[i].judul
                 << setw(25) << data_buku[i].pengarang
                 << setw(15) << data_buku[i].penerbit
                 << setw(6) << data_buku[i].tahunTerbit << endl;
        }
    }
    cout << "\nTekan enter untuk kembali...";
    cin.ignore();
    cin.get();
}

void lihatDataBukuID(){
    system("cls");
    cout << string(40, '-') << endl;
    center("Daftar Buku Berdasarkan Judul", "|", 40);
    cout << string(40, '-') << endl;
    int n = sizeof(data_buku) / sizeof(data_buku[0]);
    QuickSort(1, n-1);
    cout << left << setw(4) << setfill(' ') << "ID"
         << setw(30) << "Judul"
         << setw(25) << "Pengarang"
         << setw(15) << "Penerbit"
         << setw(6) << "Tahun" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (data_buku[i].idBuku != 0)
        {
            cout << left << setw(4) << setfill(' ') << data_buku[i].idBuku
                 << setw(30) << data_buku[i].judul
                 << setw(25) << data_buku[i].pengarang
                 << setw(15) << data_buku[i].penerbit
                 << setw(6) << data_buku[i].tahunTerbit << endl;
        }
    }
    cout << "\nTekan enter untuk kembali...";
    cin.ignore();
    cin.get();
}

// ===========================
// Bagian Data Diri Pengunjung
// ===========================
void lihatDataDiri()
{
    system("cls");  
    cout << string(40, '-') << endl;
    center("Data Diri Anda", "|", 40);
    cout << string(40, '-') << endl;

    
    cout << "Username     : " << username << endl;
    cout << "Tanggal Lahir: " << tgl_lahir << endl;
    cout << "Alamat       : " << alamat << endl;
    cout << "No. Telepon  : " << no_telp << endl;
    cout << "Email        : " << email << endl;
    cout << "\nTekan enter untuk kembali...";
    cin.ignore();
    cin.get();
}

// ===========================
// Function Umum
// ===========================
void sequentialTahun(int cariTahun)
{
    system("cls");
    bool ketemu = false;
    buku *ptr = data_buku;
    for (int i = 1; i <= 50; i++)
    {
        if ((ptr + i)->tahunTerbit == cariTahun)
        {
            cout << "Buku ditemukan: " << endl;
            cout << "ID Buku: " << (ptr + i)->idBuku << endl;
            cout << "Judul: " << (ptr + i)->judul << endl;
            cout << "Tahun Terbit: " << (ptr + i)->tahunTerbit << endl;
            cout << "Pengarang: " << (ptr + i)->pengarang << endl;
            cout << "Penerbit: " << (ptr + i)->penerbit << endl
                 << endl;
            ketemu = true;
        }
    }
    if (!ketemu)
    {
        cout << "Buku tidak ditemukan." << endl;
    }
}

void sequentialString(string cariPengarang)
{
    int i = 1;
    bool ketemu = false;
    while (i <= 200 && data_buku[i].idBuku != 0)
    {
        if (data_buku[i].pengarang == cariPengarang || data_buku[i].judul == cariPengarang || data_buku[i].penerbit == cariPengarang)
        {
            system("cls");
            cout << "Buku ditemukan: " << endl;
            cout << "ID Buku: " << data_buku[i].idBuku << endl;
            cout << "Judul: " << data_buku[i].judul << endl;
            cout << "Tahun Terbit: " << data_buku[i].tahunTerbit << endl;
            cout << "Pengarang: " << data_buku[i].pengarang << endl;
            cout << "Penerbit: " << data_buku[i].penerbit << endl
                 << endl;
            ketemu = true;
        }
        i++;
    }
    if (!ketemu)
    {
        cout << "Buku tidak ditemukan." << endl;
    }
}

void ShellSort(int n)
{
    int gap = n / 2;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            buku temp = data_buku[i];
            int j;
            for (j = i; j >= gap && data_buku[j - gap].tahunTerbit > temp.tahunTerbit; j -= gap)
            {
                data_buku[j] = data_buku[j - gap];
            }
            data_buku[j] = temp;
        }
        gap /= 2;
    }
}

void BubbleSortString(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data_buku[j].judul > data_buku[j + 1].judul)
            {
                swap(data_buku[j], data_buku[j + 1]);
            }
        }
    }
}

void QuickSort(int low, int high){
    if (low < high) {
        int pivot = data_buku[high].idBuku;
        int i = (low - 1);
        for (int j = low; j < high; j++) {
            if (data_buku[j].idBuku <= pivot) {
                i++;
                swap(data_buku[i], data_buku[j]);
            }
        }
        swap(data_buku[i + 1], data_buku[high]);
        int pi = i + 1;

        QuickSort(low, pi - 1);
        QuickSort(pi + 1, high);
    }
}

void MasukkanDataKeFile(const string &namafile)
{
    ofstream file(namafile, ios::app);
    if (!file.is_open())
    {
        cout << "Gagal membuka file!!" << endl;
        return;
    }
    else
    {
        for (int i = 1; i <= 200; i++)
        {
            if (data_buku[i].idBuku != 0)
            {
                file << data_buku[i].idBuku << ";" << data_buku[i].judul << ";" << data_buku[i].tahunTerbit
                     << ";" << data_buku[i].pengarang << ";" << data_buku[i].penerbit << ";" << endl;
            }
        }
    }
}

void SalinDatadariFilekeArray(const string &namafile)
{
    ifstream file(namafile, ios::in);
    if (!file.is_open())
    {
        cout << "Gagal membuka file!!" << endl;
        return;
    }
    else
    {
        string baris;
        int i = 1;
        while (getline(file, baris) && i <= 200)
        {
            stringstream ss(baris);
            string temp;
            getline(ss, temp, ';');
            data_buku[i].idBuku = stoi(temp);
            getline(ss, data_buku[i].judul, ';');
            getline(ss, temp, ';');
            data_buku[i].tahunTerbit = stoi(temp);
            getline(ss, data_buku[i].pengarang, ';');
            getline(ss, data_buku[i].penerbit, ';');
            i++;
        }
    }
}

void center(string text, string batasSamping, int tabelLength)
{                                                      // Function untuk tampilkan teks di tengah
    int PanjangTeks = text.length();                   // Hitung panjang teks
    int extraSpace = (tabelLength - PanjangTeks) % 2;  // Space tambahan kalo panjang teks ganjil (biar rapi)
    int fillSamping = (tabelLength - PanjangTeks) / 2; // Hitung space samping kanan kiri

    cout << batasSamping << setfill(' ') << setw(fillSamping - 1) << ' ' << text << setfill(' ') << setw((fillSamping - 1) + extraSpace) << ' ' << batasSamping << endl;
}