#include <iostream>

using namespace std;

int main()
{
    // array
    int v[1];
    int v2[2] = {1, 2};
    int variable[2][2] = {
        {0, 1},
        {1, 0}};
    int variable2[3][4][3] = {
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
    int var[] = {0, 2, 4};

    cout << endl << endl << variable[1][1];
    cout << endl << var[1];

    // pointer
    int *ptr = &variable[1][1];
    int *ptr2;
    int **ptr3 = &ptr; // pointer yang menyimpan alamat pointer lain

    cout << endl << endl << ptr3;
    cout << endl << **ptr3;
    cout << endl << *ptr;

    // struct
    struct orang
    {
        string nama;
        int umur;
    };

    orang dia = {"christian", 19};
    cout << endl << endl << dia.nama;
    cout << endl << dia.umur;

    // pointer di struct
    orang *diaPtr;
    diaPtr = &dia;
    cout << endl << endl << diaPtr->nama;
    cout << endl << diaPtr->umur;
}
