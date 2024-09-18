#include <iostream>

using namespace std;

// pogram nerima input terus print semua yang sudah di input + alamat
// panajng data berdasarkan input

typedef struct
{
    string hari;
    int tahun;
} tanggal_lahir;

struct Mahasiswa
{
    string nim;
    string nama;
    tanggal_lahir tgl;
    Mahasiswa *next;
};

void input(string &nim, string &nama, string &hari, int &tahun)
{
    cout << "\n nim :";
    cin >> nim;
    cout << " nama :";
    cin >> nama;
    cout << " hari lahir :";
    cin >> hari;
    cout << " tanggal lahir :";
    cin >> tahun;
}

void output(Mahasiswa mhs)
{
    cout << "\n\n NIM : " << mhs.nim
         << "\n Nama : " << mhs.nama
         << "\n hari lahir : " << mhs.tgl.hari
         << "\n tahun lahir : " << mhs.tgl.tahun;
}

int main()
{
    int panjang, *p;
    cout << "\n Panjang data : ";
    cin >> panjang;
    p = &panjang;

    cout << "\n Panjang Data : " << *p;

    Mahasiswa mhs[panjang];

    for (int i = 0; i < panjang; i++)
    {
        input(mhs[i].nim, mhs[i].nama, mhs[i].tgl.hari, mhs[i].tgl.tahun);
        if (i < panjang - 1)
        {
            mhs[i].next = &mhs[i + 1];
        }
    }

    Mahasiswa *head = &mhs[0];
    for (int i = 0; i < panjang; i++)
    {
        Mahasiswa *ptr = head;
        output(*head);
        cout << "\n Alamat : " << ptr;
        head = head->next;
    }

    return 0;
}
