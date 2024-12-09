#include <iostream>
#include <fstream>
using namespace std;

void BuatDapus() {
    ofstream myfile;
	
	myfile.open("DaftarPustaka.txt", ios::app);
	
    if (myfile.fail()) {
        cout << "Gagal membuka file" << endl;
        return;
    }

    int pilihan;
    cout << endl << " -------------------------------" << endl;
    cout << "|          Pilih Sumber         |" << endl;
    cout << " -------------------------------" << endl;
    cout << "| 1. Artikel                    |" << endl;
    cout << "| 2. Jurnal                     |" << endl;
    cout << "| 3. Buku                       |" << endl;
    cout << " -------------------------------" << endl;
    cout << "Masukkan pilihan : ";
    cin >> pilihan;
    cin.ignore();

    char penulis[100], tahun[10], judul[100], sumber[100], penerbit[100], volume[10], issue[10], halaman[20], kota[50], link[1000];

    cout << "Masukkan nama penulis (Nama belakang dahulu, Nama depan) : ";
    cin.getline(penulis, 100);
	cout << "Masukkan tahun publikasi : ";
    cin.getline(tahun, 10);
    cout << "Masukkan judul : ";
    cin.getline(judul, 100);
    
    if (pilihan == 1) { 
        cout << "Masukkan sumber (Nama Website atau Media) : ";
        cin.getline(sumber, 100);
        cout << "Masukkan URL : ";
        cin.getline(link, 1000);

        myfile << penulis << ".(" << tahun << "). " << judul << ". " << sumber << ". Diakses dari " << link << "." << endl;
	    
     } else if (pilihan == 2) { 
        cout << "Masukkan nama jurnal : ";
        cin.getline(sumber, 100);
        cout << "Masukkan volume : ";
        cin.getline(volume, 10);
        cout << "Masukkan issue (nomor jurnal) : ";
        cin.getline(issue, 10);
        cout << "Masukkan halaman : ";
        cin.getline(halaman, 20);

        myfile << penulis << ".(" << tahun << "). " << judul << ". " << sumber << ", " << volume << "(" << issue << "), " << halaman << "." << endl;

    } else if (pilihan == 3) { 
        cout << "Masukkan kota publikasi : ";
        cin.getline(kota, 50);
        cout << "Masukkan nama penerbit : ";
        cin.getline(penerbit, 100);

        myfile << penulis << ".(" << tahun << "). " << judul << ". " << kota << " : " << penerbit << "." << endl;

    } else {
        cout << "Pilihan tidak ada, coba kembali." << endl;
        return;
    }

    myfile.close();
    cout << "Daftar pustaka berhasil disimpan!" << endl;
}

void ListDapus() {
    ifstream ifile;
	
	ifile.open("DaftarPustaka.txt", ios::app);
    if (ifile.fail()) {
        cout << "Gagal membuka file" << endl;
        return;
    }

    char dapus[500];
    cout << endl << "Daftar Pustaka Tersimpan : " << endl;
    while (ifile.getline(dapus, 500)) {
        cout << dapus << endl;
    }
    ifile.close();
}
