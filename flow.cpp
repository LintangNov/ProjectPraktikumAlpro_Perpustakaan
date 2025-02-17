#include <iostream>
#include <string>

using namespace std;

// Function declarations
void mainMenu();
void login();
void signUp();
void menuAdmin();
void menuPengunjung();
void tambahDataBuku();
void hapusDataBuku();
void ubahDataBuku();
void lihatDataBuku();
void pinjamBuku();
void dataDiri();
void loginInput(int pilihan);

// Main function
int main() {
    mainMenu();
}

// Main menu
void mainMenu() {
    int mainMenuChoice;

    do {
        system("cls");
        cout << "=== Sistem Peminjaman Buku Perpustakaan ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Sign Up" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> mainMenuChoice;

        switch (mainMenuChoice) {
            case 1:
                login();  // Login
                break;
            case 2:
                signUp();  // Sign Up
                break;
            case 3:
                cout << "\nKeluar dari sistem. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (mainMenuChoice != 3);
}

// Login function
void login() {
    int loginChoice;
    string username, password;

    system("cls");

    cout << "\n=== Pilih Jenis Login ===" << endl;
    cout << "1. Login sebagai Admin" << endl;
    cout << "2. Login sebagai Pengunjung" << endl;
    cout << "3. Kembali\n";
    cout << "Pilihan: ";
    cin >> loginChoice;

    switch (loginChoice)
    {
    case 1:
    loginInput(loginChoice);
    break;
    case 2:
        loginInput(loginChoice);
        break;
    case 3:
        mainMenu();
    break;
    default:
        cout << "Pilihan tidak valid";
        break;
    }
    
}

// Sign Up function
void signUp() {
    string username, password;

    system("cls");


    cout << "\n=== Sign Up ===" << endl;
    cout << "Masukkan username baru: ";
    cin >> username;
    cout << "Masukkan password baru: ";
    cin >> password;

    cout << "\nAkun berhasil dibuat! Silakan login.\n";
}

// Menu Admin
void menuAdmin() {
    int userMenuChoice;
    do {

        system("cls");

        cout << "\n=== Menu Admin ===" << endl;
        cout << "1. Tambah Data Buku" << endl;
        cout << "2. Hapus Data Buku" << endl;
        cout << "3. Ubah Data Buku" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilihan: ";
        cin >> userMenuChoice;

        switch (userMenuChoice) {
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
                cout << "\nLogout dari akun Admin.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (userMenuChoice != 4);
}

// Menu Pengunjung
void menuPengunjung() {
    int userMenuChoice;
    do {
        system("cls");

        cout << "\n=== Menu Pengunjung ===" << endl;
        cout << "1. Lihat Daftar Buku" << endl;
        cout << "2. Pinjam Buku" << endl;
        cout << "3. Data Diri" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilihan: ";
        cin >> userMenuChoice;

        switch (userMenuChoice) {
            case 1:
                lihatDataBuku();
                break;
            case 2:
                pinjamBuku();
                break;
            case 3:
                cout << "\nFitur Data Diri belum tersedia.\n";
                break;
            case 4:
                dataDiri();
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (userMenuChoice != 4);
}

// Tambah Data Buku
void tambahDataBuku() {
    system("cls");

    //Fitur Tambah Data Buku
}

// Hapus Data Buku
void hapusDataBuku() {
    system("cls");

    //Fitur Hapus Data Buku
}

// Ubah Data Buku
void ubahDataBuku() {
    system("cls");

    //Fitur Ubah Data Buku
}

// Lihat Data Buku
void lihatDataBuku() {
    system("cls");

    //Fitur Lihat Daftar Buku 
}

// Pinjam Buku
void pinjamBuku() {
    system("cls");

    //Fitur Pinjam Buku
}

void dataDiri(){
    system("cls");

    //fitur data diri
};

void loginInput(int pilihan) {
    string username, password;
    (pilihan==1)? "login admin\n" : "login pengunjung\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    switch (pilihan)
    {
    case 1:
        menuAdmin();
        break;
    case 2:
        menuPengunjung();
        break;
    }
}