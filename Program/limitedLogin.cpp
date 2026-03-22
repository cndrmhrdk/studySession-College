#include <iostream>
using namespace std;

int main(){
    string namaUser = "candra", password = "087", inputNama, inputPass;

    cout << "masukkan nama anda : ";
    cin >> inputNama;
    cout << "masukkan password : ";
    cin >> inputPass;

    if (inputNama == namaUser && inputPass == password){
        cout << "login berhasil\n" << endl;
    } else {
        int i = 1;
        while (i >= 0){
            cout << "\nlogin gagal, kesempatan anda sisa " << i+1 << " silahkan ulangi!" << endl;
            cout << "masukkan nama anda : ";
            cin >> inputNama;
            cout << "masukkan password : ";
            cin >> inputPass;
            if (i == 0 && (inputNama != namaUser || inputPass != password)){
                cout << "Kesempatan anda habis, Program dihentikan!\n\n";
                return 0;
            } else if (i==0 && inputNama == namaUser && inputPass == password) {
                cout << "login berhasil!\n" << endl;
                i = i-1;
            } else if (i==1 && inputNama == namaUser && inputPass == password) {
                cout << "login berhasil!\n" << endl;
                i = i-2;
            }
            i--;
        }
    }
    cout << "Continue your code!";
}