#include <iostream>
#include <random>

#define max 7

using namespace std;

struct Node
{
    int angka;
    Node *next;
};

void push(Node *&head, int &counter);
void mergeSort(Node *&head, int &callstack, bool descending = false);
Node *merge(Node *left, Node *right, bool descending);
bool compare(Node *a, Node *b, bool descending);
void printList(Node *head);

int main()
{
    Node *head = nullptr;
    int counter = 0, input, callstack = 0;
    bool loop = true;

    for (int i = 0; i < max; i++)
    {
        push(head, counter);
    }

    while (loop)
    {
        printList(head);

        cout << "\n\nMerge sort\n 1. Ascending\n 2. Descending\n Pilih: ";
        cin >> input;
        switch (input)
        {
        case 1:
            mergeSort(head, callstack);
            break;
        case 2:
            mergeSort(head, callstack, true);
            break;
        default:
            loop = false;
            break;
        }
    }

    return 0;
}

void push(Node *&head, int &counter)
{
    Node *nodeBaru = new Node;
    nodeBaru->next = head;

    // Define range
    int leftRange = 1;
    int rightRange = 20;

    // Initialize a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(leftRange, rightRange);

    nodeBaru->angka = distrib(gen);
    head = nodeBaru;
    counter++;
}

void mergeSort(Node *&head, int &callstack, bool descending)
{
    callstack++;
    cout << "Callstack " << callstack << " : Start\n";
    if (!head || !head->next)
    {
        cout << "Callstack " << callstack << " : End\n";
        callstack--;
        return;
    }

    // Divide
    cout << "Callstack " << callstack << " : Divide\n";
    Node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *mid = slow->next;
    slow->next = nullptr;

    // Mutiple Divide (Recur)
    mergeSort(head, callstack, descending);
    mergeSort(mid, callstack, descending);

    // Conquer
    cout << "Callstack " << callstack << " : Conquer\n";
    head = merge(head, mid, descending);
    cout << "Callstack " << callstack << " : End\n";
    callstack--;
}

Node *merge(Node *left, Node *right, bool descending)
{
    // temp sebagai head sementara yang kosong untuk diisi hasil sort
    Node *temp = new Node;
    Node *tail = temp;
    while (left && right)
    {
        if (compare(left, right, descending))
        {
            // Addfirst
            tail->next = left;
            left = left->next;
        }
        else
        {
            // Addlast
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = left ? left : right;

    Node *result = temp->next;
    delete temp;
    return result;
}

bool compare(Node *a, Node *b, bool descending)
{
    return descending ? a->angka > b->angka : a->angka <= b->angka;
}

void printList(Node *head)
{
    Node *temp = head;
    cout << "\nCurrent List: ";
    while (temp)
    {
        cout << temp->angka << " ";
        temp = temp->next;
    }
}
