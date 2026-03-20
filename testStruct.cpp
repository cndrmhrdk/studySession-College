#include <iostream>
using namespace std;

struct daftar_matkul{
	string nama_matkul;
	int nilai;
};

struct mahasiswa{
	string nama;
	int nim;
	daftar_matkul matkul[3];
};

mahasiswa mhs[3];

main(){
	cout << "\n---MENU INPUT DATA MAHASISWA---" << endl;
	cout << "Jumlah data Mahasiswa : 3\n\nSilakan isi data berikut :" << endl;
	for (int i = 0; i < 3; i++){
		cout << "Data-" << i+1 << endl;
		cout << "Masukkan nama mahasiswa\t: ";
		getline(cin, mhs[i].nama);
		cout << "Masukkan nim mahasiswa\t: ";
		cin >> mhs[i].nim;
		for (int j = 0; j < 1; j++){
			cout << "Masukkan nama matkul\t: ";
			cin.ignore();
			getline(cin, mhs[i].matkul[j].nama_matkul);
			cout << "Masukkan nilai matkul\t: ";
			cin >> mhs[i].matkul[j].nilai;
			cout << endl;
			cin.ignore();
		}
	}
	cout << "\n====Data Hasil Input====" << endl;
	for (int i = 0; i < 3; i++){
		cout << "Data-" << i+1 << endl;
		cout << "Nama mahasiswa\t: " << mhs[i].nama << endl;
		cout << "Nim mahasiswa\t: " << mhs[i].nim << endl;
		for (int j = 0; j < 1; j++){
			cout << "Nama matkul\t: " << mhs[i].matkul[j].nama_matkul << endl;;
			cout << "Nilai matkul\t: " << mhs[i].matkul[j].nilai << endl;
			cout << endl;
		}
	}
}
