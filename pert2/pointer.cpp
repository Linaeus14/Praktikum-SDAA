#include <iostream>
using namespace std;

int main()
{
    int angka;
    cout << "Array 1D" << "\n Masukan banyak angka : ";
    cin >> angka;
    cout << endl;

    int array[angka], *n; // deklarasi array langung mengambil memori di RAM sejumlah panjang array(angka)
    int **p;

    // penggunaan & sebelum array untuk mengambil alamat (Address-Of Operator)
    n = &array[0]; // mengambil alamat array pertama(0) untuk anchor

    for (int x = 0; x < angka; x++)
    {
        cout << " Array[" << x << "] = ";
        cin >> array[x];
    }
    for (int x = 0; x < angka; x++)
    {
        cout << endl
             << "Array[" << x << "}"
             << "\n Nilai : " << *n // penggunaan * sebelum pointer untuk melihat isi (Dereference Operator)
             << "\n Alamat : " << n << endl;
        n++; // bergerak ke kanan dari alamat  index array sebelumnya untuk mengambil alamtnya
    }
    return 0;
}
