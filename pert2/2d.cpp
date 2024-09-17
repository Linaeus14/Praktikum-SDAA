#include <iostream>

using namespace std;

int main()
{
    int baris, kolom;

    // Input dimensi matriks
    cout << "Masukkan jumlah baris dan kolom: ";
    cin >> baris >> kolom;

    // Deklarasi array untuk matriks
    int matriks[baris][kolom];

    // Inisialisasi matriks dengan nilai 0
    for (int i = 0; i < baris; ++i)
    {
        for (int j = 0; j < kolom; ++j)
        {
            matriks[i][j] = 0;
        }
    }

    // Mencetak matriks
    cout << "Matriks dengan dimensi " << baris << "x" << kolom << " adalah:" << endl;
    for (int i = 0; i < baris; ++i)
    {
        for (int j = 0; j < kolom; ++j)
        {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
