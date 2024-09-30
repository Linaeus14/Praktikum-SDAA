#include <iostream>
#include <limits>

using namespace std;

struct Node
{
    Node *prev;
    int lantai;
    Node *next;
};

void addFirst(Node *&head, Node *&tail, int &jumlah);
void deleteFirst(Node *&head, Node *&tail, int &jumlah);
void errorInput(int &input);

int main()
{
    int jumlah = 0, input;
    bool loop = true;
    Node *head = nullptr;
    Node *tail = nullptr;

    string menuUtama = "\n\n == Data Roster Karakter ==\n 1. Tambah lantai\n 2. Kurangi lantai\n 3. Keluar\n Masukan pilihan : ";
    while (loop == true)
    {
        if (tail != nullptr)
        {
            Node *temp = head;
            do
            {
                cout << "\n Lantai " << temp->lantai;
                temp = temp->next;
            } while (temp != head);
        }

        cout << menuUtama;
        cin >> input;
        switch (input)
        {
        case 1:
            addFirst(head, tail, jumlah);
            break;

        case 2:
            deleteFirst(head, tail, jumlah);
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

void addFirst(Node *&head, Node *&tail, int &jumlah)
{
    Node *nodeBaru = new Node;
    nodeBaru->lantai = jumlah + 1;

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

void deleteFirst(Node *&head, Node *&tail, int &jumlah)
{
    Node *cur = head;
    if (jumlah == 1)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    delete cur;
    jumlah = jumlah - 1;
    cout << "\n Telah dihapus! \n";
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
