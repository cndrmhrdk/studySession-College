#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    //deklarasi utk login
    string namaPanggilan = "candra";
    int NIM = 124250087;
    string username;
    int password;

    //input username dan password
    cout << "Username : "; cin >> username;
    cout << "Password : "; cin >> password;
    cout << endl;

    //pengecekan username dan password
    if (username == namaPanggilan && password == NIM){
        cout << "LOGIN BERHASIL\nselamat datang di toko " << namaPanggilan << "!\n\n";

        string selamatDatang = "== SELAMAT DATANG DI KASIR ==";
        string garis = "=";

        cout << selamatDatang << endl;
        for (int i = 1; i <= selamatDatang.length(); i++){
            cout << "=";
        }
        
        //deklarasi array
        string barang[5];
        int stok[5];
        string keterangan[5] = {"Stok Habis", "Stok Menipis", "Stok Relatif Aman", "Stok Banyak"};
        char validInput;
        
        cout << "\nApakah anda ingin input barang?\n(Y/T) : ";
        cin >> validInput;
        cout << endl;

        //menu input barang dan stok
        if (toupper(validInput) == 'Y'){
            cout << "-- INPUT BARANG DAN STOK --\n";
            for (int n = 1; n <= 5; n++){
                cout << "Masukkan barang ke-" << n << " : ";
                cin.ignore();
                getline(cin, barang[n - 1]);

                cout << "Masukkan stok barang ke-" << n << " : ";
                cin >> stok[n - 1];
            }  

            //tabel daftar stok dan keterangan
            string output[3] = {"Nama Barang", "Stok", "Keterangan"};
            cout << "\n-- DAFTAR STOK BARANG --\n\n";
            cout << setw(25) << left << output[0] << setw(10) << left << " | " << setw(10) << left << output[1] << setw(10) << left << " | " << setw(10) << left << output[2] << endl;

            for (int i = 1; i <= 75; i++){
                cout << "-";
            }

            cout << endl;
            for (int i = 0; i < 5; i++){
                if (stok[i] < 0){
                    continue;
                } else if (stok[i] == 0) {
                    cout << setw(25) << left << barang[i] << setw(10) << left << " | " << setw(10) << left << stok[i] << setw(10) << left << " | " << setw(10) << left << keterangan[0] << endl;
                } else if (stok[i] <= 50) {
                    cout << setw(25) << left << barang[i] << setw(10) << left << " | " << setw(10) << left << stok[i] << setw(10) << left << " | " << setw(10) << left << keterangan[1] << endl;
                } else if (stok[i] <= 100) {
                    cout << setw(25) << left << barang[i] << setw(10) << left << " | " << setw(10) << left << stok[i] << setw(10) << left << " | " << setw(10) << left << keterangan[2] << endl;
                } else if (stok[i] > 100) {
                    cout << setw(25) << left << barang[i] << setw(10) << left << " | " << setw(10) << left << stok[i] << setw(10) << left << " | " << setw(10) << left << keterangan[3] << endl;
                } 
            }

            for (int i = 1; i <= 75; i++){
                cout << "-";
            }
            
        } else if (toupper(validInput) == 'T') {
            cout << "Terima kasih, program selesai!";
        } else{
            cout << "Input anda salah!";
        }

    } else {
        cout << "LOGIN GAGAL!" << endl;
    }
    return 0;
}
