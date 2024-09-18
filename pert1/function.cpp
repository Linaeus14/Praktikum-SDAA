#include <iostream>

using namespace std;

//fungsi
float luas_segitiga(float alas, float tinggi)
{
    float hasil;
    hasil = 0.5 * alas * tinggi;
    return hasil;
}

//prosedur
void input(string prompt, float &input)
{
    cout << prompt;
    cin >> input;
}

//overloading prosedur
void input(string prompt, int &input)
{
    cout << prompt;
    cin >> input;
}

int main()
{
    float alas;
    float tinggi;
    input("masukkan alas: ", alas);
    input("masukkan tinggi: ", tinggi);
    cout << luas_segitiga(alas, tinggi) << endl;

    return 0;
}