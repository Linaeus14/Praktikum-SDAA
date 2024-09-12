#include <iostream>
using namespace std;

int main() {
    cout << "MENU" <<endl;
    cout << "(1) A"<< endl;
    cout << "(2) B"<< endl;
    cout << "(3) C"<< endl;
    cout << "(4) D"<< endl;

    int pilihan;
    cout << "Masukkan Pilihan (1-4)";
    cin >> pilihan;
    switch (pilihan){
        case 1:
            cout << "Struktur Data";
            break;
        case 2:
            cout << "Basis Data";
            break;
        case 3:
            cout << "Orsikom";
            break;
        case 4:
            cout << "Web";
            break;
        default:
            cout << "coba lagi";
    return 0;
    }
}