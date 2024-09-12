#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // tanpa namespace std
    std::cout << "Hello World" << endl;
    // menggunakan namespace std
    cout << "Hello world";

    return 0;
}

/*
 * Menggunakan 'namespace std' dalam C++ bisa praktis, tetapi ada beberapa
 * kelemahan:
 *
 * 1. Pencemaran Namespace:
 *    Mengimpor semua dari 'std' ke namespace global bisa menyebabkan
 *    tabrakan nama jika ada nama identifikasi yang sama dengan
 *    di 'std', menimbulkan ambiguitas dan kesalahan.
 *
 * 2. Keterbacaan Kode:
 *    Menggunakan 'namespace std' secara global dapat membuat sulit bagi pembaca kode
 *    untuk memahami asal usul identifikasi. Menyebutkan namespace secara eksplisit
 *    membuat kode lebih jelas dan mudah dipelihara.
 *
 * 3. Masalah Scope Global:
 *    'using namespace std;' mempengaruhi seluruh file,
 *    yang bisa menyebabkan masalah di kode besar atau dalam file header yang
 *    disertakan di banyak tempat.
 *
 * 4. Potensi Konflik:
 *    Dalam proyek besar atau saat menggunakan pustaka pihak ketiga,
 *    konflik antara nama identifikasi Anda dan nama dari pustaka
 *    standar bisa terjadi. Menyebutkan namespace secara spesifik dapat mencegah
 *    konflik ini.
 *
 * 5. Masalah File Header:
 *    Menggunakan 'using namespace std;' di file header menyebarkan pencemaran
 *    namespace ke file sumber lain yang menyertakan header tersebut,
 *    yang bisa menyebabkan masalah di proyek besar.
 *
 * Rekomendasi:
 * Untuk pembelajaran, penggunaan namespace std akan mempermudah pemahaman.
 * Akan tetapi jangan menjadi kebiasaan untuk proyek besar.
 * Gunakan 'std::' secara eksplisit atau batasi direktif 'using'
 * ke ruang lingkup terbatas (misalnya, di dalam fungsi atau blok kode) untuk
 * menjaga kejelasan kode dan menghindari interaksi namespace yang tidak diinginkan.
 */