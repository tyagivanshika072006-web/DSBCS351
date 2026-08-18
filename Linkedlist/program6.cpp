#include <iostream>
using namespace std;

int data[100];
int nextNode[100];
int head = -1;
int count = 0;

void insertEnd(int value)
{
    data[count] = value;
    nextNode[count] = -1;

    if (head == -1)
    {
        head = count;
    }
    else
    {
        int temp = head;

        while (nextNode[temp] != -1)
        {
            temp = nextNode[temp];
        }

        nextNode[temp] = count;
    }

    count++;
}

void deleteBeginning()
{
    if (head == -1)
    {
        cout << "List is empty!" << endl;
        return;
    }

    head = nextNode[head];
}

void display()
{
    int temp = head;

    while (temp != -1)
    {
        cout << data[temp] << " -> ";
        temp = nextNode[temp];
    }

    cout << "NULL" << endl;
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    cout << "Before deletion: ";
    display();

    deleteBeginning();

    cout << "After deletion: ";
    display();

    return 0;
}