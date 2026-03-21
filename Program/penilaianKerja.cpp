#include <iostream>
#include <iomanip>
using namespace std;

//deklarasi untuk array dll.
string namaPegawai[100], ketKategori, ketTeladan;
int jumlahPegawaiAwal = 0, jumlahPegawai, pilihan;
int nilaiD[100], nilaiTJ[100], nilaiK[100], nilaiI[100], nilaiHK[100];
float rataRata;

//untuk hiasan judul setiap menu
void headerMenu(string headName){
    cout << setw(30) << left << " " << headName << endl;
}

//fungsi untuk menu
void menu(string judulMenu){
    for (int i = 0; i < 60; i++){
        cout << "=";
    }

    cout << endl << setw(10) << left << " " << judulMenu << endl;
    
    for (int i = 0; i < 60; i++){
        cout << "=";
    }

    //daftar menu
    cout << "\n1. Input Nilai Pegawai" << endl;
    cout << "2. Tampilkan Hasil Penilaian" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilihan Menu (1 -3) : ";
    cin >> pilihan;
    cout << endl;
}

// fungsi untuk menu input nilai
void inputNilai(){
    cout << "Note : Total hanya bisa menampung sampai 100 data pegawai" << endl;
    cout << "Mau input nilai berapa pegawai : ";
    cin >> jumlahPegawai;
    cout << endl;

    for (int i = jumlahPegawaiAwal; i < (jumlahPegawaiAwal + jumlahPegawai); i++){
        cout << "=======================" << endl;
        cout << "|    Pegawai ke-" << i+1 << "     |" << endl;
        cout << "=======================" << endl;
        cout << "Nama Pegawai : ";
        cin.ignore();
        getline(cin, namaPegawai[i]);
        cout << "\nNilai Disiplin \t\t: ";
        cin >> nilaiD[i];
        cout << "Nilai Tanggung Jawab \t: ";
        cin >> nilaiTJ[i];
        cout << "Nilai Kerjasama \t: ";
        cin >> nilaiK[i];
        cout << "Nilai Inisiatif \t: ";
        cin >> nilaiI[i];
        cout << "Nilai Hasil Kerja \t: ";
        cin >> nilaiHK[i];
        cout << endl;
    }

    //untuk menambahkan jumlah pegawai awal yg semulanya 0
    for (int i = 0; i < jumlahPegawai; i++){
        jumlahPegawaiAwal++;
    }
}

// fungsi untuk menghitung rata-rata
float rata(float nilaid, float nilaitj, float nilaik, float nilaii, float nilaihk){
    return nilaid * 0.2 + nilaitj * 0.15 + nilaik * 0.2 + nilaii * 0.3 + nilaihk * 0.15;
}

// fungsi untuk menentukan kategori
string kategori(){
    if (rataRata >= 90){
        ketKategori = "Sangat Baik";
    } else if (rataRata >= 80){
        ketKategori = "Baik";
    } else if (rataRata >= 70){
        ketKategori = "Cukup";
    } else if (rataRata < 70){
        ketKategori = "Kurang";
    }
    return ketKategori;
}

// fungsi untuk menentukan termasuk teladan atau tidak
string teladan(){
    if (rataRata >= 90){
        ketTeladan = "Ya";
    } else if (rataRata < 90){
        ketTeladan = "Tidak";
    }
    return ketTeladan;
}

//hiasan close program
void exit(){
    cout << "____________________________" << endl;
    cout << "      PROGRAM CLOSED";
}

//menu utama
main(){
    char lanjut;

    //do untuk perulangan
    do {
        //memanggoil fungsi menu
        menu("PROGRAM PENILAIAN KINERJA PEGAWAI");

        //pengecekan pilihan user
        if (pilihan != 1 && pilihan != 2 && pilihan != 3){
            do{
                system("cls");
                cout << "\tPILIHAN ANDA TIDAK TERSEDIA DI MENU !!\n\t\tSILAKAN ULANGI !!\n";
                menu("PROGRAM PENILAIAN KINERJA PEGAWAI");
            } while (pilihan != 1 && pilihan != 2 && pilihan != 3);
        }
        system("cls");

        if (pilihan == 1){
            headerMenu("INPUT NILAI PEGAWAI");
            cout << endl;
            inputNilai();
        } else if (pilihan == 2) {
            headerMenu("TABEL HASIL PENILAIAN");
            cout << endl;
            
            //untuk cek apakah data sudah ada sebelumnya
            if (jumlahPegawaiAwal == 0){
                cout << "DATA ANDA KOSONG, SILAHKAN INPUT NILAI TERLEBIH DAHULU!\nINPUT NILAI DAPAT DILAKUKAN DI MENU 'INPUT NILAI PEGAWAI'\n";
            } else {
                for (int i = 0; i < 92; i++){
                    cout << "=";
                }
                cout << endl;

                cout << setw(2) << left << "|" << setw(4) << left << "No" << setw(2) << left << "|" << setw(10) << left << " " << setw(30) << "Nama Pegawai" << setw(2) << left << "|" << setw(12) << left << "Rata-rata" << setw(2) << left << "|" << setw(15) << left << "Kategori" << setw(2) << left << "|" << setw(10) << "Teladan" << setw(2) << left << "|" << endl;

                for (int i = 0; i < 92; i++){
                    cout << "=";
                }
                cout << endl;
                
                //untuk menampilkan tabel hasil penilaian
                for (int i = 0; i < jumlahPegawaiAwal; i++){
                    rataRata = rata(nilaiD[i], nilaiTJ[i], nilaiK[i], nilaiI[i], nilaiHK[i]);
                    cout << setw(2) << left << "|" << setw(4) << left << i+1 << setw(2) << left << "|" << setw(40) << left << namaPegawai[i] << setw(2) << left << "|" << setw(12) << left << rataRata << setw(2) << left << "|" << setw(15) << left << kategori() << setw(2) << left << "|" << setw(10) << left << teladan() << setw(2) << left << "|" << endl;
                }

                for (int i = 0; i < 92; i++){
                    cout << "=";
                }
            }
        } else if (pilihan == 3){
            exit();
            return 0;
        }
        
        //validasi lanjut program
        do{
            cout << "\nApakah mau lanjut program ? (Y/N) : ";
            cin >> lanjut;
        } while (toupper(lanjut) != 'Y' && toupper(lanjut) != 'N');
        system("cls");

    } while (toupper(lanjut) != 'N');

    //exit
    exit();
    return 0;
}