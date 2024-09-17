#include <iostream>

using namespace std;

int main()
{
    int variable[2][2] = {
        {0, 1},
        {1, 0}};
    int variable[3][4][3] = {
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
    int var[] = {0, 2, 4};

    cout << variable[1][1];
    cout << var[1];

    int *ptr;
    int *ptr2;
    int **ptr3 = &ptr;

    cout << ptr3;
    cout << **ptr3;
    cout << *ptr;

    struct orang
    {
        string nama;
        int umur;
    };

    orang dia = {"christian", 19};
    cout << dia.nama;
    cout << dia.umur;

    orang *dia2;
    dia2->nama = "christian";
    dia2->umur = 19;
    cout << dia2->nama;
    cout << dia2->umur;
}
