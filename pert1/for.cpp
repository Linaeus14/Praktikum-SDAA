#include <iostream>

using namespace std;

int main()
{
    int angka, a;
    cout << "Masukan banyak angka untuk di print : ";
    cin >> angka;
    for (int x = 0; x < angka / 10; x++)
    {
        for (int y = 0; y < 9; y++)
        {
            a++;
            cout << a << " ";
        }
        a++;
        cout << a << endl;
    }
    for (int x = 0; x < angka % 10; x++)
    {
        a++;
        cout << a << " ";
    }

    return 0;
}
