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
void quickSort(Node *&headRef, int &callstack, bool descending = false);
Node *getTail(Node *cur);
Node *quickSortRecur(Node *head, Node *end, int &callstack, bool descending);
Node *partition(Node *head, Node *end, Node *&newHead, Node *&newEnd, int callstack, bool descending);
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

        cout << "\n\nQuick sort\n 1. Ascending\n 2. Descending\n Pilih: ";
        cin >> input;
        switch (input)
        {
        case 1:
            quickSort(head, callstack);
            break;
        case 2:
            quickSort(head, callstack, true);
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

void quickSort(Node *&headRef, int &callstack, bool descending)
{
    headRef = quickSortRecur(headRef, getTail(headRef), callstack, descending);
    return;
}

Node *getTail(Node *cur)
{
    while (cur && cur->next)
    {
        cur = cur->next;
    }
    return cur;
}

Node *quickSortRecur(Node *head, Node *end, int &callstack, bool descending)
{
    callstack++;
    cout << "Callstack " << callstack << " : Start\n";
    if (!head || head == end)
    {
        cout << "Callstack " << callstack << " : End\n";
        callstack--;
        return head;
    }

    // Divide and Conquer
    Node *newHead = nullptr, *newEnd = nullptr;
    cout << "Callstack " << callstack << " : Divide\n";
    Node *pivot = partition(head, end, newHead, newEnd, callstack, descending);

    // Mutiple Divide and Conquer (Recur)
    if (newHead != pivot)
    {
        Node *tmp = newHead;
        while (tmp->next != pivot)
        {
            tmp = tmp->next;
        }
        tmp->next = nullptr;
        newHead = quickSortRecur(newHead, tmp, callstack, descending);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next, newEnd, callstack, descending);
    cout << "Callstack " << callstack << " : End\n";
    callstack--;
    return newHead;
}

Node *partition(Node *head, Node *end, Node *&newHead, Node *&newEnd, int callstack, bool descending)
{
    Node *pivot = end;
    Node *prev = nullptr, *cur = head, *tail = pivot;

    cout << "Callstack " << callstack << " : Conquer\n";
    while (cur != pivot)
    {
        if (compare(cur, pivot, descending))
        {
            // Addfirst
            if (newHead == nullptr)
            {
                newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        else
        {
            // Addlast
            if (prev)
            {
                prev->next = cur->next;
            }
            Node *tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (newHead == nullptr)
    {
        newHead = pivot;
    }
    newEnd = tail;
    return pivot;
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