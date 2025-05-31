# Sistem Peminjaman Buku Perpustakaan (C++)

Aplikasi ini merupakan proyek sederhana berbasis C++ untuk mengelola peminjaman buku di perpustakaan. Sistem ini menyediakan dua jenis user, yaitu **Pustakawan** (admin) dan **Pengunjung** (user), yang masing-masing memiliki hak akses berbeda.

## Fitur Utama

- **Login & Registrasi**
  - Pustakawan: Login menggunakan username dan password yang sudah disimpan dalam array di kode.
  - Pengunjung: Bisa melakukan sign up dan sign in.

- **Manajemen Data Buku (Pustakawan)**
  - Tambah data buku
  - Hapus data buku
  - Ubah data buku

- **Manajemen Peminjaman (Pengunjung)**
  - Cari buku berdasarkan judul, pengarang, penerbit, atau tahun terbit
  - Lihat daftar buku (diurutkan secara ascending berdasarkan ID, judul, dan tahun terbit)
  - Pinjam buku
  - Kembalikan buku yang dipinjam 

- **Data Diri Pengunjung**
  - Pengunjung dapat melihat data diri yang ada di akunnya sendiri

## Struktur Data

- Data buku disimpan dalam array of struct dan file eksternal (`data_buku.txt`)
- Data pengunjung disimpan dalam file eksternal (`data_pengunjung.txt`)
- Data peminjaman buku disimpan di file yang terpisah dari data buku dan data pengunjung ('peminjaman.txt')

> Proyek ini dibuat untuk tugas akhir Praktikum Algoritma pemrograman Lanjut dengan menggunakan bahasa C++.
