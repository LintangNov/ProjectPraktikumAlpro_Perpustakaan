#include <iostream>
#include <string>

using namespace std;

int main() {
    int mainMenuChoice;
    int userMenuChoice;
    string username, password;

    do {
        cout << "=== Sistem Peminjaman Buku Perpustakaan ===" << endl;
        cout << "1. Login sebagai Admin" << endl;
        cout << "2. Login sebagai Pengunjung" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> mainMenuChoice;

        switch (mainMenuChoice) {
            case 1:
                // Admin login
                cout << "\n=== Login Admin ===" << endl;
                cout << "Masukkan username: ";
                cin >> username;
                cout << "Masukkan password: ";
                cin >> password;

                // Menu Admin
                do {
                    cout << "\n=== Menu Admin ===" << endl;
                    cout << "1. Tambah Data Buku" << endl;
                    cout << "2. Hapus Data Buku" << endl;
                    cout << "3. Ubah Data Buku" << endl;
                    cout << "4. Logout" << endl;
                    cout << "Pilihan: ";
                    cin >> userMenuChoice;

                    switch (userMenuChoice) {
                        case 1:
                            // Tambah Data Buku
                            break;
                        case 2:
                            // Hapus Data Buku
                            break;
                        case 3:
                            // Ubah Data Buku
                            break;
                        case 4:
                            // Logout
                            cout << "\nLogout dari akun Admin.\n";
                            break;
                        default:
                            cout << "Pilihan tidak valid.\n";
                    }
                } while (userMenuChoice != 4);
                break;

            case 2:
                // Pengunjung login
                cout << "\n=== Login Pengunjung ===" << endl;
                cout << "Masukkan username: ";
                cin >> username;
                cout << "Masukkan password: ";
                cin >> password;

                // Menu Pengunjung
                do {
                    cout << "\n=== Menu Pengunjung ===" << endl;
                    cout << "1. Lihat Daftar Buku" << endl;
                    cout << "2. Pinjam Buku" << endl;
                    cout << "3. Edit Data Diri" << endl;
                    cout << "4. Logout" << endl;
                    cout << "Pilihan: ";
                    cin >> userMenuChoice;

                    switch (userMenuChoice) {
                        case 1:
                            // Lihat Daftar Buku
                            break;
                        case 2:
                            // Pinjam Buku
                            break;
                        case 3:
                            // Edit Data Diri
                            break;
                        case 4:
                            // Logout
                            cout << "\nLogout dari akun Pengunjung.\n";
                            break;
                        default:
                            cout << "Pilihan tidak valid.\n";
                    }
                } while (userMenuChoice != 4);
                break;

            case 3:
                cout << "\nKeluar dari sistem. Terima kasih!\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (mainMenuChoice != 3);

    return 0;
}
