#include <iostream>
#define max 4

using namespace std;

struct Node
{
    int lantai;
    Node *next;
};

void push(Node *&head, int &counter);
void pop(Node *&head, int &counter);

int main()
{
    Node *head = nullptr;
    int counter = 0, input;
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
        cout << "\nStack\n 1. Push\n 2. Pop\n Pilih : ";
        cin >> input;
        switch (input)
        {
        case 1:
            push(head, counter);
            break;

        case 2:
            pop(head, counter);
            break;

        default:
            break;
        }
    }
}

void push(Node *&head, int &counter)
{
    if (counter == max)
    {
        cout << "Stack Overflow";
    }
    else
    {
        Node *nodeBaru = new Node;
        nodeBaru->next = head;
        nodeBaru->lantai = counter + 1;
        head = nodeBaru;
        counter++;
    }
}

void pop(Node *&head, int &counter)
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
