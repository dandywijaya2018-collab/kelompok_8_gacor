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

