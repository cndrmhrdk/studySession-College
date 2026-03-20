#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    //deklarasi array menu dan harga, serta kebutuhan tipe data lainnya
    string namaMenu[100] = {"Espresso", "Cappuccino", "Creamy Latte", "Americano", "Brownie Cake"};
    int hargaMenu[100] = {25000, 30000, 35000, 28000, 20000};
    int pilihanUser, nomorBeli, jumlahBeli, totalHarga = 0, pembayaran, jumlahMenu = 5, jumlahMenuBaru;
    char lanjutProgram, member;
    string namaUser;

    do{
        //menampilkan judul program
        for (int i = 1; i <= 100; i++){
            cout << "=";
        }
        cout << endl;
        cout << setw(40) << left << " " << "PROGRAM CAFE" << endl;

        for (int i = 1; i <= 100; i++){
            cout << "=";
        }

        //menampilkan menu
        cout << endl;
        cout << "1. Daftar Menu" << endl;
        cout << "2. Pembelian" << endl;
        cout << "3. Tambah Menu Baru" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihanUser;
        cout << endl;

        //pengecekan pilihan user
        if (pilihanUser != 1 && pilihanUser != 2 && pilihanUser != 3 && pilihanUser != 4){
            do{
                cout << "Pilihan tidak valid!\nPilihan : ";
                cin >> pilihanUser;
                cout << endl;
            } while (pilihanUser != 1 && pilihanUser != 2 && pilihanUser != 3 && pilihanUser != 4);
            system("cls");
        
        //menampilkan menu
        } else  if (pilihanUser == 1){
            cout << "DAFTAR MENU CAFE" << endl;
            for (int i = 1; i <= 80; i++){
                    cout << "-";
            }
            cout << endl;
            cout << setw(4) << left << "No" << setw(2) << left << "|" << setw(30) << left << "Nama Menu" << setw(2) << left << "|" << setw (10) << left << "Harga" << endl;
            for (int i = 1; i <= 80; i++){
                    cout << "-";
            }
            cout << endl;
            for (int i = 0; i < jumlahMenu; i++){
                cout << setw(4) << left << i+1 << setw(2) << left << "|" << setw(30) << left << namaMenu[i] << setw(2) << left << "|" << setw (10) << left << hargaMenu[i] << endl;
            }
            for (int i = 1; i <= 80; i++){
                    cout << "-";
            }
        
        //menu input pembelian
        } else if (pilihanUser == 2){
            cout << "INPUT PEMBELIAN" << endl;
            for (int i = 1; i <= 80; i++){
                cout << "-";
            }
            cout << "\nNama Pembeli \t\t\t: ";
            cin.ignore();
            getline(cin, namaUser);
            cout << "Nomor menu yang ingin dibeli \t: ";
            cin >> nomorBeli;
            while (nomorBeli > jumlahMenu || nomorBeli <= 0){
                cout << "Nomor yang anda inputkan tidak ada di pilihan!\nSilahkan ulangi!\n\n";
                cout << "Nomor menu yang ingin dibeli \t: ";
                cin >> nomorBeli; 
            }
            cout << "Jumlah pesanan \t\t\t: ";
            cin >> jumlahBeli;
            totalHarga = hargaMenu[nomorBeli-1] * jumlahBeli;
            cout << "Apakah anda pembeli member(Y/N) : ";
            cin >> member;
            system("cls");

            //menampilkan data pembelian
            cout << endl << "DATA PEMBELIAN" << endl;
            for (int i = 1; i <= 80; i++){
                cout << "-";
            }
            cout << "\nNama Pembeli \t\t: " << namaUser << endl;
            cout << "Menu yang dipesan \t: " << namaMenu[nomorBeli-1] << endl;
            cout << "Harga per menu \t\t: " << hargaMenu[nomorBeli-1] << endl;
            cout << "Jumlah pesanan \t\t: " << jumlahBeli << endl;
            cout << "Total harga \t\t: " << totalHarga << endl;

            //untuk seleksi member serta diskon
            if (toupper(member) == 'Y'){
                totalHarga = totalHarga * 0.8;
                cout << "Diskon \t\t\t: " << totalHarga << endl;
                cout << endl;
            } else if (toupper(member) == 'N'){
                cout << endl;
            }

            //menu input pembayaran
            cout << "INPUT PEMBAYARAN" << endl;
            for (int i = 1; i <= 80; i++){
                cout << "-";
            }

            //input nominal pembayaran
            cout << "\nInputkan total uang yang kamu bayarkan \t: ";
            cin >> pembayaran;

            //output pembayaran beserta kembalian
            if (pembayaran > totalHarga){
                cout << "Kembalian anda\t\t\t\t: " << pembayaran - totalHarga << endl;
                cout << "TRANSAKSI BERHASIL!" << endl;
                cout << "\nTERIMA KASIH SUDAH BERBELANJA" << endl;
            } else if (pembayaran == totalHarga){
                cout << "TRANSAKSI BERHASIL!" << endl;
                cout << "\nTERIMA KASIH SUDAH BERBELANJA" << endl;
            } else if (pembayaran < totalHarga){
                cout << "\n!!TRANSAKSI GAGAL!!\nUang anda tidak mencukupi!\nSilahkan ulangi program pembelian!" << endl;
            } else{
                cout << "Pembayaran tidak valid";
            }

        //menu tambah menu cafe
        } else if (pilihanUser == 3){
            cout << "TAMBAH MENU" << endl;
            for (int i = 1; i <= 80; i++){
                cout << "-";
            }
            cout << "\nJumlah menu yang akan ditambahkan : ";
            cin >> jumlahMenuBaru;
            cout << endl;

            //input nama menu dan harga baru
            for (int i = jumlahMenu; i < jumlahMenu + jumlahMenuBaru; i++){
                cout << "DATA MENU KE " << i + 1 << " : " << endl;
                for (int i = 1; i <= 24; i++){
                    cout << "=";
                }
                cout << "\nMasukkan nama menu \t: ";
                cin.ignore();
                getline(cin, namaMenu[i]);
                cout << "Masukkan harga menu \t: ";
                cin >> hargaMenu[i];
                
                for (int i = 1; i <= 24; i++){
                    cout << "=";
                }
                cout << endl;
            }
            for (int i = 1; i <= jumlahMenuBaru; i++){
                jumlahMenu++;
            }

        //keluar program
        } else if (pilihanUser == 4){
            system("cls");
            for (int i = 1; i <= 100; i++){
                cout << "=";
            }
            cout << endl;
            cout << setw(20) << left << " " << "TERIMA KASIH SUDAH MENGUNJUNGI CAFE KAMI" << endl;
            for (int i = 1; i <= 100; i++){
                cout << "=";
            }
            return 0;
        }

        //lanjut program
        do{
            cout << "\nApakah kamu ingin melanjutkan program ? (y/n)\n" << "Pilihan : ";
            cin >> lanjutProgram;
        } while (toupper(lanjutProgram) != 'Y' && toupper(lanjutProgram) != 'N');
        system("cls");

    } while (toupper(lanjutProgram) != 'N');
    for (int i = 1; i <= 100; i++){
        cout << "=";
    }
    cout << endl;
    cout << setw(20) << left << " " << "TERIMA KASIH SUDAH MENGUNJUNGI CAFE KAMI" << endl;

    for (int i = 1; i <= 100; i++){
        cout << "=";
    }
}