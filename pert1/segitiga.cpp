#include <iostream>
using namespace std;

float luas_segitiga (float alas,float tinggi){
    float hasil;
    hasil = 0.5*alas*tinggi;
    return hasil;
}

int main(){
    float alas;
    float tinggi;
    cout << "masukkan alas: ";cin >> alas;
    cout <<"masukkan tinggi" ;cin >> tinggi;
    cout << luas_segitiga(alas,tinggi)<<endl;
    return 0;

}