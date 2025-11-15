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

void barangAwal() {
    dataBarang[0] = {"Rokok Marlboro", 20, "Rak 4"};
    dataBarang[1] = {"Rokok Sampoerna", 20, "Rak 4"};
    dataBarang[2] = {"Kopi", 10, "Rak 1"};
    dataBarang[3] = {"Gula", 50, "Rak 2"};
    dataBarang[4] = {"Teh", 60, "Rak 3"};
    
    jumlahBarang = 5; 

}

void cariBarang() {
    string key;
    cout << "\nMasukkan nama barang yang dicari: ";
    cin.ignore();
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

    if (!ditemukan) {
        cout << "\nBarang tidak ditemukan!\n";
    }
}

void tampilBarang() {
    cout << " ===DATA BARANG=== " << endl;
    for (int i = 0; i < jumlahBarang; i++){
        cout << i+1 << "." << dataBarang[i].nama << "| Stok: " << dataBarang[i].stok << "| Lokasi: " << dataBarang[i].lokasi << endl;
    }
}