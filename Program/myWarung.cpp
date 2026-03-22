#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	string namaUser = "candra", password = "087", inputNama, inputPass;

    cout << "masukkan nama anda : ";
    cin >> inputNama;
    cout << "masukkan password : ";
    cin >> inputPass;

    if (inputNama == namaUser && inputPass == password){
        cout << "login berhasil" << endl;
    } else {
        int i = 1;
        while (i >= 0){
            cout << "login gagal, kesempatan anda sisa " << i+1 << " silahkan ulangi!" << endl;
            cout << "masukkan nama anda : ";
            cin >> inputNama;
            cout << "masukkan password : ";
            cin >> inputPass;
            if (i == 0 && inputNama != namaUser || inputPass != password ){
                return 0;
            } else if (i==0 && inputNama == namaUser && inputPass == password) {
                cout << "login berhasil" << endl;
                i = i-1;
            } else if (i==1 && inputNama == namaUser && inputPass == password) {
                cout << "login berhasil" << endl;
                i = i-2;
            }
            i--;
        }
    }
	
	string namaMenu [100] = {"Rendang",  "Ayam Pop",  "Gulai Ikan", "Sate Padang", "Dendeng Balado"};
	string namaPembeli;
	int hargaMenu [100] = {25000, 22000, 20000, 23000, 27000};
	int pilihanMenu, jumlahMenu = 5, totalHarga = 0, jumlahBayar, nomorBeli, jumlahBeli, diskon, jumlahPendapatan=0;
	char lanjutProgram;
	
	do{
		for (int i =1; i<= 50; i++){
			cout << "=";
		} cout << endl;
		cout << setw(20) << left << " "<< "MENU UTAMA" << endl;
		for (int i =1; i<= 50; i++){
			cout << "=";
		} cout << endl;
		
		cout << "1. LIhat Daftar Menu" << endl;
		cout << "2. Tambah Menu Baru"<< endl;
		cout << "3. Pembelian Menu"<< endl;
		cout << "4. Tampilan Total Penjualan"<< endl;
		cout << "5. Keluar"<< endl;
		
		for (int i =1; i<= 50; i++){
			cout << "=";
		} cout << endl;
		
		cout << "Menu Pilihan : ";
		cin >> pilihanMenu;
		cout << endl;
		if (pilihanMenu !=1 && pilihanMenu !=2 && pilihanMenu !=3 && pilihanMenu !=4 && pilihanMenu !=5){
			do {
				cout << "Menu Pilihan : ";
				cin >> pilihanMenu;
				cout << endl;
			} while (pilihanMenu !=1 && pilihanMenu !=2 && pilihanMenu !=3 && pilihanMenu !=4 && pilihanMenu !=5);
		}
		if (pilihanMenu ==1){
			for (int i =1; i<= 50; i++){
				cout << "=";
			} cout << endl;
			cout << setw(15) << left << " "<< "DAFTAR MENU MAKANAN"<< endl;
			for (int i =1; i<= 50; i++){
				cout << "=";
			} cout << endl;
			
			cout << setw(4) << left <<  "No"<< setw(2) << left << "|"<< setw(20) << left << "Makanan" << setw(2) << "|"<< setw(20) << left << "Harga"<< endl;
			for (int i =1; i<= 50; i++){
					cout << "-";
			} cout << endl;
				
			for (int i= 0; i < jumlahMenu; i++){\
				cout << setw(4) << left <<  i+1<< setw(2) << left << "|"<< setw(20) << left << namaMenu[i] << setw(2) << "|"<< setw(20) << left << "Rp" << hargaMenu[i]<< endl;
			}
			for (int i =1; i<= 50; i++){
				cout << "-";
			} cout << endl;
		} else if (pilihanMenu == 2){
			for (int i =1; i<= 50; i++){
				cout << "=";
			} cout << endl;
			cout << setw(15) << left << " "<< "TAMBAH MENU BARU"<< endl;
			for (int i =1; i<= 50; i++){
				cout << "=";
			} cout << endl;
			
			cout << "masukkan nama makanan baru :  ";
			cin.ignore();
			getline(cin, namaMenu[jumlahMenu]);
			cout << "masukkan harga menu : ";
			cin >> hargaMenu[jumlahMenu];
			jumlahMenu++;
			cout << "Menu baru berhasil ditambahkan" << endl;
		} else if (pilihanMenu == 3){
			for (int i =1; i<= 50; i++){
				cout << "=";
			} cout << endl;
			cout << setw(15) << left << " "<< "PEMBELIAN MENU"<< endl;
			for (int i =1; i<= 50; i++){
				cout << "=";
			} cout << endl;
			
			cout << "masukkan nama pembeli : ";
			cin.ignore();
			getline(cin, namaPembeli);
			cout << endl;
			
			cout << "Daftar Menu"<< endl;
			for (int i = 0; i < jumlahMenu; i++){
				cout << i+1 << ". "<< namaMenu[i] << " - Rp"<< hargaMenu[i] << endl;
			}
			cout <<  "pilih nomor menu yang ingin dibeli : ";
			cin >> nomorBeli;
			cout << "\njumlah pesanan : ";
			cin >> jumlahBeli;
			totalHarga = jumlahBeli * hargaMenu[nomorBeli-1];
			if (namaPembeli == "krisna" || namaPembeli == "cahya" || namaPembeli == "rizky" || namaPembeli == "robihul"){
				cout << "\nselamat! anda pelanggan tetap, anda mendapatkan diskon 5%" << endl;
				cout << "\ntotal harga : Rp" << totalHarga;
				diskon = totalHarga * 0.05; 
				cout << "\ndiskon : " << diskon ;
				totalHarga= totalHarga * 0.95;
				cout << "\ntotal yang harus dibayarkan : Rp" << totalHarga;
				cout << "\nmasukkan jumlah orang yang dibayarkan : ";
				cin >> jumlahBayar;
				jumlahPendapatan += totalHarga;
			} else {
				cout << "\ntotal harga : Rp" << totalHarga;
				cout << "\ntotal yang harus dibayarkan : Rp" << totalHarga;
				cout << "\nmasukkan jumlah uang yang dibayarkan : ";
				cin >> jumlahBayar;
				jumlahPendapatan += totalHarga;
			}
			
			for (int i =1; i<= 50; i++){
				cout << "-";
			} cout << endl;
			cout << setw(15) << left << " "<< "KUITANSI PEMBELIAN"<< endl;
			for (int i =1; i<= 50; i++){
				cout << "-";
			} cout << endl;
			
			cout << "\nnama pembeli : " << namaPembeli;
			cout << "\nmenu dibeli : " << namaMenu[nomorBeli-1];
			cout << "\n jumlah : "<< jumlahBeli;
			cout << "\nharga satuan : " << hargaMenu[nomorBeli-1];
			cout << "\ntotal harga : " << totalHarga;
			if (namaPembeli == "krisna" || namaPembeli == "cahya" || namaPembeli == "rizky" || namaPembeli == "robihul"){
				cout << "\ndiskon : "<< diskon;
			}
			cout << "\ntotal bayar : " << totalHarga;
			cout << "\nuang diterima : "<< jumlahBayar;
			if (jumlahBayar > totalHarga){
				cout << "\nkembalian : "<< jumlahBayar - totalHarga;
			} cout << endl;
			for (int i =1; i<= 50; i++){
				cout << "-";
			} cout << endl;
		} else if (pilihanMenu == 4){
			for (int i =1; i<= 50; i++){
				cout << "=";
			} cout << endl;
			cout << setw(15) << left << " "<< "TOTAL PENJUALAN HARI INI"<< endl;
			for (int i =1; i<= 50; i++){
				cout << "=";
			} cout << endl;
			
			cout << "total harga dari seluruh pembelian : Rp"<< jumlahPendapatan;
			cout << endl;
		}
		
		cout << "apakah anda ingin melanjutkan program (Y/N) : ";
		cin >> lanjutProgram;
		
		if (toupper(lanjutProgram) != 'Y'  && toupper(lanjutProgram) != 'N'){
			do {
				cout << "apakah anda ingin melanjutkan program (Y/N) : ";
				cin >> lanjutProgram;
			} while (toupper(lanjutProgram) != 'N' && toupper(lanjutProgram) != 'Y');
		}
		if (toupper(lanjutProgram) == 'N'){
			for (int i =1; i<= 50; i++){
				cout << "=";
			} cout << endl;
			cout << setw(15) << left << " "<< "TERIMA KASIH ATAS KUNJUNGAN ANDA"<< endl;
			for (int i =1; i<= 50; i++){
				cout << "=";
			} cout << endl;
			return 0;
		} else if (toupper(lanjutProgram) == 'Y'){
			cout << endl;
		}
		
	} while (pilihanMenu != 5);
}
