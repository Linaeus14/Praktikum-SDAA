#include <iostream>
#include <limits>

using namespace std;

struct Identitas
{
    string nama;
    string gender;
    int umur;
};

struct Data
{
    int sid;
    Identitas bio;
    string tiket;
};

struct Node
{
    Node *prev;
    Data data;
    Node *next;
};

void Cek(Node *&head, Node *&tail, int &jumlah);
void addFirst(Node *&head, Node *&tail, int &jumlah);
void deleteLast(Node *&head, Node *&tail, int &jumlah);
void inputPilihan(string namaPilihan, const string array[], int panjang, string &data);
Node inputData();
void errorInput(int &input);

int main()
{
    int jumlah = 0, input;
    bool loop = true;
    Node *head = nullptr;
    Node *tail = nullptr;

    string menuUtama = "\n == Data Roster Karakter ==\n 1. Submit Tiket\n 2. Cek Tiket\n 3. Keluar\n Masukan pilihan : ";
    while (loop == true)
    {
        cout << menuUtama;
        cin >> input;
        switch (input)
        {
        case 1:
            addFirst(head, tail, jumlah);
            break;

        case 2:
            Cek(head, tail, jumlah);
            break;

        case 3:
            loop = false;
            break;

        default:
            cout << " \n Terjadi Kesalahan\n";
            break;
        }
    }

    return 0;
}

void Cek(Node *&head, Node *&tail, int &jumlah)
{
    if (jumlah == 0)
    {
        cout << ">> Tidak ada tiket untuk di cek! <<" << endl;
        return;
    }

    string input;
    cout << endl
         << "SID: " << tail->data.sid << endl
         << "    Nama      : " << tail->data.bio.nama << endl
         << "    Gender    : " << tail->data.bio.gender << endl
         << "    Umur      : " << tail->data.bio.umur << endl
         << "    Tiket     : " << tail->data.tiket << endl
         << "\nSelsaikan tiket(y/N)? :";
    cin >> input;

    if (input == "y" || input == "Y")
    {
        deleteLast(head, tail, jumlah);
        if (tail == nullptr)
        {
            cout << ">> Semua tiket sudah selesai! Tidak ada lagi tiket untuk di cek. <<" << endl;
        }
    }
}

void addFirst(Node *&head, Node *&tail, int &jumlah)
{
    Node *nodeBaru = new Node;
    nodeBaru->data = inputData().data;

    if (tail == nullptr)
    {
        nodeBaru->prev = nodeBaru;
        nodeBaru->next = nodeBaru;
        tail = nodeBaru;
    }
    else
    {
        nodeBaru->prev = tail;
        nodeBaru->next = head;
    }

    head = nodeBaru;
    (head->next)->prev = head;
    tail->next = head;

    jumlah = jumlah + 1;
}

void deleteLast(Node *&head, Node *&tail, int &jumlah)
{
    Node *cur = tail;
    if (jumlah == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }
    delete cur;
    jumlah = jumlah - 1;
    cout << "\n Telah dihapus! \n";
}

void inputPilihan(string namaPilihan, const string array[], int panjang, string &data)
{
    int input = 1;
    cout << "\n  " << namaPilihan << endl;
    for (int i = 0; i < panjang; i++)
    {
        cout << "   " << i + 1 << ". " << array[i];
        if (i < panjang - 1)
        {
            cout << endl;
        }
    }

    do
    {
        cout << " \nMasukan angka 1-" << panjang << "! \n Input : ";
        cin >> input;
        errorInput(input);
    } while (input <= 0 or input > panjang);
    data = array[input - 1];
}

Node inputData()
{
    Node *dataBaru = new Node;
    int input;
    cout << " \nTambah Data Karakter\n "
         << " SID     : ";
    cin >> dataBaru->data.sid;
    errorInput(dataBaru->data.sid);

    cout << "  Nama    : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, dataBaru->data.bio.nama);

    const string genders[] = {"Laki-laki", "Perempuan", "Tidak Terdefinisi"};
    inputPilihan("Gender", genders, 3, dataBaru->data.bio.gender);

    cout << "\n  Umur  :  ";
    cin >> dataBaru->data.bio.umur;
    errorInput(dataBaru->data.bio.umur);

    cout << "  Tiket :  ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, dataBaru->data.tiket);

    cout << " \nBerhasil!\n ";
    return *dataBaru;
}

void errorInput(int &input)
{
    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mohon masukan angka untuk input di atas!\n input :  ";
            cin >> input;
        }
        else
        {
            break;
        }
    }
}
