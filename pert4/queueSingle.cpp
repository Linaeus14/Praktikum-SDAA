#include <iostream>
#define max 4

using namespace std;

struct Node
{
    int lantai;
    Node *next;
};

void enqueue(Node *&head, Node *&tail, int &counter, int &queue);
void dequeue(Node *&head, Node *&tail, int &counter, int &queue);

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int counter = 0, queue = 0, input;
    bool loop = true;

    while (loop)
    {
        if (counter > 0)
        {
            Node *temp = head;
            do
            {
                cout << "\nLantai " << temp->lantai;
                temp = temp->next;
            } while (temp != nullptr);
        }
        cout << "\nQueue\n 1. enqueue\n 2. dequeue\n Pilih : ";
        cin >> input;
        switch (input)
        {
        case 1:
            enqueue(head, tail, counter, queue);
            break;

        case 2:
            dequeue(head, tail, counter, queue);
            break;

        default:
            break;
        }
    }
}

void enqueue(Node *&head, Node *&tail, int &counter, int &queue)
{
    if (counter == max)
    {
        cout << "Stack Overflow";
    }
    else
    {

        Node *nodeBaru = new Node;
        nodeBaru->lantai = queue + 1;
        nodeBaru->next = nullptr;
        if (counter == 0)
        {
            head = nodeBaru;
            tail = nodeBaru;
        }
        else
        {
            tail->next = nodeBaru;
            tail = nodeBaru;
        }
        queue++;
        counter++;
    }
}

void dequeue(Node *&head, Node *&tail, int &counter, int &queue)
{
    if (counter == 0)
    {
        cout << "Stack Underflow";
    }
    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        counter--;
    }
}
