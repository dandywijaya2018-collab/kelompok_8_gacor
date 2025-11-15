#include <iostream>
#include <string>
using namespace std;


void inputBarang() {
    int tambah;
    cout << "\nBerapa barang baru yang ingin dimasukkan? ";
    cin >> tambah;
    cin.ignore();

    for(int i = jumlahBarang; i < jumlahBarang + tambah; i++) {
        cout << "\nBarang ke-" << i+1 << endl;

        cout << "Nama Barang  : ";
        getline(cin, dataBarang[i].nama);

        cout << "Stok Barang  : ";
        cin >> dataBarang[i].stok;
        cin.ignore();

        cout << "Lokasi Rak   : ";
        getline(cin, dataBarang[i].lokasi);
    }

    jumlahBarang += tambah;
}
