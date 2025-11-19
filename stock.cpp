#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string nama;
    int stok;
    string lokasi;
};

Barang dataBarang[50];
int jumlahBarang = 0;

void barangAwal();
void inputBarang();
void tampilBarang();
void cariBarang();
void tambahStok();

int main() {
    barangAwal();

    int pilihan;
    char ulang;

    do {
        cout << "\n===== MENU PROGRAM =====\n";
        cout << "1. Input Barang Baru\n";
        cout << "2. Lihat Semua Barang\n";
        cout << "3. Cari Barang\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: inputBarang(); break;
            case 2: tampilBarang(); break;
            case 3: cariBarang(); break;
            case 4: cout << "Program selesai.\n"; return 0;
            default: cout << "Pilihan tidak valid!\n"; break;
        }

        cout << "\nIngin kembali ke menu? (y/n): ";
        cin >> ulang;

    } while(ulang == 'y' || ulang == 'Y');

    return 0;
}

void barangAwal() {
    dataBarang[0] = {"Rokok Marlboro", 20, "Rak 4"};
    dataBarang[1] = {"Rokok Sampoerna", 20, "Rak 4"};
    dataBarang[2] = {"Kopi", 10, "Rak 1"};
    dataBarang[3] = {"Gula", 50, "Rak 2"};
    dataBarang[4] = {"Teh", 60, "Rak 3"};
    
    jumlahBarang = 5; 
}

void inputBarang() {
    int tambah;
    cout << "\nBerapa barang baru yang ingin dimasukkan? ";
    cin >> tambah;
    cin.ignore(10000, '\n'); 

    if (jumlahBarang + tambah > 50) {
        cout << "Kapasitas penyimpanan penuh! Maksimal 50 barang.\n";
        return;
    }

    for(int i = jumlahBarang; i < jumlahBarang + tambah; i++) {
        cout << "\nBarang ke-" << i+1 << endl;
        
        cout << "Nama Barang  : ";
        getline(cin, dataBarang[i].nama);

        cout << "Stok Barang  : ";
        cin >> dataBarang[i].stok;
        cin.ignore(10000, '\n'); 

        cout << "Lokasi Rak   : ";
        getline(cin, dataBarang[i].lokasi);
    }

    jumlahBarang += tambah;
    cout << "Data berhasil ditambahkan!\n";
}

void tampilBarang() {
    if (jumlahBarang == 0) {
        cout << "\nBelum ada data barang.\n";
        return;
    }

    cout << "\n=== DATA BARANG ===\n";
    for(int i = 0; i < jumlahBarang; i++) {
        string warning ="";
        if (dataBarang[i].stok < 5){
            warning = " <-- PERINGATAN: Stok hampir habis!";
        }
        cout << i+1 << ". " << dataBarang[i].nama
             << " | Stok: " << dataBarang[i].stok
             << " | Lokasi: " << dataBarang[i].lokasi << endl;
    }
}

void cariBarang() {
    string key;
    cout << "\nMasukkan nama barang yang dicari: ";
    cin.ignore(10000, '\n'); 
    getline(cin, key);

    bool ditemukan = false;

    for(int i = 0; i < jumlahBarang; i++) {
        if(dataBarang[i].nama == key) {
            cout << "\n--- Barang Ditemukan ---\n";
            cout << "Nama   : " << dataBarang[i].nama << endl;
            cout << "Stok   : " << dataBarang[i].stok << endl;
            cout << "Lokasi : " << dataBarang[i].lokasi << endl;
            ditemukan = true;
            break; 
        }
    }

    if(!ditemukan) {
        cout << "\nBarang \"" << key << "\" tidak ditemukan!\n";
    }
}

void tambahStok() {
    string key;
    cout << "\nmasukan nama barang yang akan ditambahakan stoknya: ";
    cin.ignore(10000, '\n')
    getline(cin, key)

    int idx = -1;
    for (int i = 0; i < jumlahBarang; i++){
        if (dataBarang[i].nama == key) {
            idx = 1;
            break;
        }
    }
    if (idx == -1) {
        cout << "Barang \"" << key << "\" tidak ditemukan. Tidak ada perubahan.\n";
        return;
    }
    int tambah;
    cout << "Stok saat ini: " << dataBarang[idx].stok << endl;
    cout << "Berapa jumlah yang ingin ditambahkan? ";
    cin >> tambah;
    if (tambah <= 0) {
        cout << "Jumlah tambahan harus > 0.\n";
    return;
    }
    dataBarang[idx].stok += tambah;
    cout << "Stok berhasil diperbarui. Stok baru " << dataBarang[idx].nama
         << " : " << dataBarang[idx].stok << endl;
}
