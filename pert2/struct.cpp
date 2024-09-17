#include <iostream>

using namespace std;

// mendefnisikan tipe data baru bernama mesin dengan struktur mengikuti struct
typedef struct
{
    float horsepower;
    int rpm;
} Mesin;

// mendefinisikan struct dengan nama mobil
struct Mobil
{
    string model;
    int tempat_duduk;
    Mesin mesin; // Mesin menjadi tipe data baru
};

// Ubah signature fungsi untuk menerima referensi
void inputMobil(Mobil *mobil)
{
    cout << "Masukkan Elemen Mobil\n"
         << "Model               : ";
    cin >> mobil->model; // pengaksesan atribut dari pointer menggunakan ->
    cout << "Jumlah Tempat Duduk : ";
    cin >> mobil->tempat_duduk;
    cout << "Horsepower          : ";
    cin >> mobil->mesin.horsepower; // menggunakan . setelah -> karna atrikut mesin bukan pointer
    cout << "RPM                 : ";
    cin >> mobil->mesin.rpm;
    cout << endl;
}

// Fungsi untuk menampilkan data array Mobil
void tampilkanMobil(const Mobil mobil[], int size)
{
    cout << "Hasil Masukan:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << "Mobil " << i + 1 << ":\n";
        cout << "Model               : " << mobil[i].model << endl;
        cout << "Jumlah Tempat Duduk : " << mobil[i].tempat_duduk << endl;
        cout << "Horsepower          : " << mobil[i].mesin.horsepower << endl;
        cout << "RPM                 : " << mobil[i].mesin.rpm << endl;
        cout << endl;
    }
}

int main()
{
    // contoh lain penggunaan typedef
    typedef unsigned long long int BigInt;
    BigInt largeNumber;

    struct Mobil garasi[2], *p; // Deklarasi array struct dan pointer
    p = &garasi[0];
    // Membaca data untuk setiap elemen array
    for (int i = 0; i < 2; ++i)
    {
        cout << "Input untuk Mobil " << i + 1 << ":\n";
        inputMobil(p);
        p++;
    }

    // Menampilkan data dari array
    tampilkanMobil(garasi, 2);

    return 0;
}