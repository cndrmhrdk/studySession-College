#include <iostream>
#include <iomanip>
using namespace std;

int pilihMenu, jumlahAwalBuku = 5;

struct kategori{
    int id;
    string namaKategori;
};

struct dataBuku{
    string judul;
    int stok;
    int harga;
    kategori kat;
};

//array untuk simpan judul, harga, stok, id, kategori buku
dataBuku infoBuku[100] = {
    {"Marine Ford", 10, 50000, {2, "Non-Fiksi"}},
    {"Forever Young", 1890, 45000, {2, "Non-Fiksi"}},
    {"Spring Day", 7, 91000, {3, "Pendidikan"}},
    {"One Piece", 100, 50000, {2, "Non-Fiksi"}},
    {"Dynamite", 9, 90000, {3, "Pendidikan"}}
};

//fungsi untuk menampilkan daftar menu utama
void daftarMenu(string judul){

    //tampilan judul
    for (int i = 0; i < 70; i++){
        cout << "=";
    }
    cout << endl;
    cout << setw(30) << left << " " << judul; 
    cout << endl;
    for (int i = 0; i < 70; i++){
        cout << "=";
    }
    cout << endl;

    //daftar menu
    cout << "1. Daftar Buku" << endl;
    cout << "2. Pembelian Buku" << endl;
    cout << "3. Tambah Data Buku" << endl;
    cout << "4. Total Harga Buku Berdasarkan Kategori" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan : ";
    cin >> pilihMenu;
    cout << endl;
}

//fungsi untuk menu 1, menampilkan daftar buku
void daftarBuku(){
    cout << "\nDAFTAR BUKU" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 98; i++){
        cout << "-";
    }
    cout << endl;
    cout << setw(3) << left << "|" << setw(3) << left << "No" << setw(2) << left << "|" << setw(40) << left << "Judul Buku" << setw(3) << left << "|" << setw(10) << left << "Stok" << setw(3) << left << "|" << setw(15) << left << "Harga" << setw(3) << left << "|" << setw(15) << left << "Kategori" << setw(3) << left << "|" << endl;
    for (int i = 0; i < 98; i++){
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < jumlahAwalBuku; i++){
        cout << setw(3) << left << "|" << setw(3) << left << i + 1 << setw(2) << left << "|" << setw(40) << left << infoBuku[i].judul << setw(3) << left << "|" << setw(10) << left << infoBuku[i].stok << setw(3) << left << "|" << setw(15) << left << infoBuku[i].harga << setw(3) << left << "|" << setw(15) << left << infoBuku[i].kat.namaKategori << setw(3) << left << "|" << endl;
    }
    for (int i = 0; i < 98; i++){
        cout << "-";
    }
}

//fungsi untuk menu 2, tambah menu
void tambahBuku(){
    cout << "\nTAMBAH BUKU" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    int jumlahTambah;

    cout << "Jumlah buku yang akan ditambahkan : "; cin >> jumlahTambah;
    for (int i = jumlahAwalBuku; i < jumlahAwalBuku + jumlahTambah; i++){
        cout << "\nData Buku ke-" << i + 1 << endl;
        cout << "=======================================================" << endl;
        cout << "Judul Buku \t\t: ";
        cin.ignore();
        getline(cin, infoBuku[i].judul);
        cout << "Stok Buku \t\t: "; cin >> infoBuku[i].stok;        
        cout << "Harga Buku \t\t: "; cin >> infoBuku[i].harga;  
        
        //pengecekan input id kategori buku
        do {
            cout << "ID kategori buku (1-4) \t: "; cin >> infoBuku[i].kat.id;        
            
            if (infoBuku[i].kat.id != 1 && infoBuku[i].kat.id != 2  && infoBuku[i].kat.id != 3 && infoBuku[i].kat.id != 4){
                cout << "id yang anda input tidak tersedia!\n";
            }
            
            if (infoBuku[i].kat.id == 1){
                infoBuku[i].kat.namaKategori = "Fiksi";
            } else if (infoBuku[i].kat.id == 2){
                infoBuku[i].kat.namaKategori = "Non-Fiksi";
            } else if (infoBuku[i].kat.id == 3){
                infoBuku[i].kat.namaKategori = "Pendidikan";
            } else if (infoBuku[i].kat.id == 4){
                infoBuku[i].kat.namaKategori = "Teknologi";
            }
        } while (infoBuku[i].kat.id != 1 && infoBuku[i].kat.id != 2  && infoBuku[i].kat.id != 3 && infoBuku[i].kat.id != 4);
        cout << "=======================================================" << endl;
    }
    //menambah jumlah buku yang semulanya 5
    jumlahAwalBuku += jumlahTambah;
    cout << "\nBUKU BERHASIL DITAMBAHKAN\n";
}

//fungsi untuk menu 3, pembelian buku
void pembelian(){
    cout << "\nMENU PEMBELIAN" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    string nama;
    int noBuku, jumlahBeli, diskon, jumlahBayar;
    char grade;

    //input pembelian
    cout << "INPUT PEMBELIAN" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "Masukkan nama pembeli (nama anda) \t: ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan nomor buku yang ingin dibeli \t: "; cin >> noBuku;

    //cek jumlah beli dan stok
    do {
        cout << "Masukkan jumlah buku yang ingin dibeli \t: "; cin >> jumlahBeli;
        if (jumlahBeli > infoBuku[noBuku - 1].stok){
            cout << "Stok yang tersedia tidak mencukupi\n";
        } 
    } while (jumlahBeli > infoBuku[noBuku - 1].stok);
    
    //menentukan grade
    if (jumlahBeli > 5){
        grade = 'A';
    } else if (jumlahBeli >= 3){
        grade = 'B';
    } else {
        grade = 'C';
    }

    //
    cout << "\nDATA PEMBELIAN" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "Nama Pembeli \t\t: " << nama;
    cout << "\nGrade Pembeli \t\t: " << grade;
    cout << "\nJudul Buku \t\t: " << infoBuku[noBuku - 1].judul;
    cout << "\nHarga Buku \t\t: " << infoBuku[noBuku - 1].harga;
    cout << "\nJumlah Pembelian \t: " << jumlahBeli;
    int totalHrg = jumlahBeli * infoBuku[noBuku - 1].harga;
    cout << "\nTotal Harga \t\t: " << totalHrg;

    //pengecekan diskon
    if (grade == 'A'){
        diskon = totalHrg * 0.15;
        totalHrg = totalHrg - diskon;
        cout << "\ndiskon (15%) \t\t: " << diskon;
    } else if(grade == 'B'){
        diskon = totalHrg * 0.10;
        totalHrg = totalHrg - diskon;
        cout << "\ndiskon (10%) \t\t: " << diskon;
    } else {
        if (totalHrg > 90000){
            diskon = totalHrg * 0.05;
            totalHrg = totalHrg - diskon;
            cout << "\ndiskon (5%) \t\t: " << diskon;
        }
    }
    cout << "\nTotal Bayar \t\t: " << totalHrg;

    cout << "\n\nINPUT PEMBAYARAN" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "Masukkan jumlah uang yang dibayarkan \t: "; cin >> jumlahBayar;
    
    //cek jumlah bayar untuk kembalian, beserta pengurangan stok setelah dibeli
    if (jumlahBayar > totalHrg){
        infoBuku[noBuku - 1].stok -= jumlahBeli;
        cout << "Kembalian \t\t\t\t: " << jumlahBayar - totalHrg;
        cout << "\n\nTerima kasih sudah mengunjungi\n";
    } else if (jumlahBayar == totalHrg){
        infoBuku[noBuku - 1].stok -= jumlahBeli;
        cout << "\n\nTerima kasih sudah mengunjungi\n";
    } else {
        cout << "\njumlah uang yang anda inputkan tidak cukup, silahkan ulangi program pembelian!";
    }
}

//fungsi menu 4, hitung jumlah harga per kategori dgn rekursif
float hitung(int nomor, string nama){
    int jum = 0;
    if (nomor == jumlahAwalBuku - 1){
        if (nama == infoBuku[nomor].kat.namaKategori){
            cout << " + " << infoBuku[nomor].harga << " = ";
            return infoBuku[nomor].harga;
        } else {
            cout << " = ";
            return jum;
        }
    }
    if (nama == infoBuku[nomor].kat.namaKategori){
        bool cek = false;
        for (int i = 0; i < nomor; i++){
            if (infoBuku[i].kat.namaKategori == nama){
                cek = true;
                break;
            }
        }
        if (cek){
            cout << " + ";
        }
        cout << infoBuku[nomor].harga;
        return jum = jum + infoBuku[nomor].harga + hitung(nomor + 1, nama);
    } else {
        return hitung(nomor + 1, nama);
    }
}

//fungsi tambahan untuk jumlah harga per kategori
void hitungHargaKategori(){
    cout << "\nHITUNG HARGA KATEGORI" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

    string namaKat;
    int nomor = 0;
    do {
        cout << "Masukkan nama kategori yang ingin dihitung : ";
        cin >> namaKat;
    } while (namaKat != "Fiksi" && namaKat != "Non-Fiksi" && namaKat != "Pendidikan" && namaKat != "Teknologi");
    
    cout << hitung(nomor, namaKat);
    cout << endl;
}

//fungsi utama
main(){
    char ulangProgram;
    do{
        daftarMenu("Program Toko Buku");

        if (pilihMenu != 1 && pilihMenu != 2 && pilihMenu != 3 && pilihMenu != 4 && pilihMenu != 5){
            do{
                cout << "\t\tPILIHAN ANDA TIDAK ADA DI MENU!\n\t\t\tSilahkan ulangi!\n";
                daftarMenu("Program Toko Buku");
            } while (pilihMenu != 1 && pilihMenu != 2 && pilihMenu != 3 && pilihMenu != 4 && pilihMenu != 5);
        }

        if (pilihMenu == 1){
            daftarBuku();
        } else if(pilihMenu == 2){
            pembelian();
        } else if (pilihMenu == 3){
            tambahBuku();
        } else if (pilihMenu == 4){
            hitungHargaKategori();
        } else if (pilihMenu == 5){
            //keluar program
            system("cls");
            cout << "______________\nPROGRAM CLOSED";
            return 0;
        }

        //validasi lanjut program
        do{
            cout << "\nApakah mau ulang program? (y/n) : ";
            cin >> ulangProgram;
        } while (toupper(ulangProgram) != 'Y' && toupper(ulangProgram) != 'N');
        system("cls");
    } while (toupper(ulangProgram) != 'N');

    //keluar program
    cout << "______________\nPROGRAM CLOSED";
    return 0;
}
