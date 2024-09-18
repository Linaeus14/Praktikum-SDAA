#include <iostream>
using namespace std;

struct Matrix
{
    int a, b, c, d;
};

void printMatrix(const Matrix &m) // parameter alamt
{
    cout << m.d << m.b << m.a << m.c;
    // Di dalam fungsi printMatrix, anggota-anggota dari struktur Matrix
    // diakses menggunakan operator titik (.) karena m adalah referensi
    // ke objek Matrix, bukan pointer. Saat menggunakan referensi, ia
    // berperilaku seperti alias untuk objek asli, sehingga mengakses
    // anggota-anggota tersebut sama seperti jika Anda melewatkan objek itu sendiri.
    // Walaupun &m sendiri merupakan alamat dalam parameter fungsi, m (local) akan bererilaku seperti variabel biasa
    // sama seperti halnya pada variabel asli di parameter (global).
}

int main()
{
    Matrix m = {0, 1, 1, 0};
    printMatrix(m);
    return 0;
}
