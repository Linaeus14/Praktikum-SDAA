#include <iostream>

using namespace std;

int faktorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * faktorial(n - 1); // rekursi terjadi disini
    }
}

int main()
{
    int angka;
    cout << "Masukkan sebuah angka: ";
    cin >> angka;
    cout << "Faktorial dari " << angka << " adalah " << faktorial(angka) << endl;

    return 0;
}
