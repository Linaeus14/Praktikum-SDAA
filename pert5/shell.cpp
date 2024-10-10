#include <iostream>
#include <random>

using namespace std;

#define max 7

struct Node
{
    int angka;
    Node *next;
};

void push(Node *&head, int &counter);
void linkedList2Array(Node *head, int counter, int arr[]);
void array2LinkedList(Node *head, int counter, int arr[]);
void shellSort(Node *&head, int arr[], int counter, int &callstack, bool descending = false);
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

    int tempOrder[counter];

    while (loop)
    {
        printList(head);

        cout << "\n\nQuick sort\n 1. Ascending\n 2. Descending\n Pilih: ";
        cin >> input;
        switch (input)
        {
        case 1:
            shellSort(head, tempOrder, counter, callstack);
            break;
        case 2:
            shellSort(head, tempOrder, counter, callstack, true);
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

void shellSort(Node *&head, int arr[], int counter, int &callstack, bool descending)
{
    linkedList2Array(head, counter, arr);

    // Loop gap
    for (int gap = counter / 2; gap > 0; gap /= 2)
    {
        // loop sorting yang bergeser ke kanan
        for (int i = gap; i < counter; i++)
        {
            int temp = arr[i];
            int j;

            // j >= gap di kondidi for menjadi pembatas agar array tidak out of bound
            if (descending)
            {
                // loop untuk menukar value, dimana hanya terjadi 2x (j-=gap meubah index array ke pasangan)
                for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
            }
            else
            {
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                {
                    arr[j] = arr[j - gap];
                }
            }

            arr[j] = temp;
        }
    }
    array2LinkedList(head, counter, arr);
}

void linkedList2Array(Node *head, int counter, int arr[])
{
    for (int i = 0; i < counter; i++)
    {
        arr[i] = head->angka;
        head = head->next;
    }
}
void array2LinkedList(Node *head, int counter, int arr[])
{
    for (int i = 0; i < counter; i++)
    {
        head->angka = arr[i];
        head = head->next;
    }
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
