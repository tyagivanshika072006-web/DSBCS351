#include <iostream>
using namespace std;

int data[100];
int nextNode[100];
int head = -1;
int count = 0;

void insertBeginning(int value)
{
    data[count] = value;
    nextNode[count] = head;
    head = count;
    count++;
}

void insertAtKthPosition(int value, int k)
{
    if (k == 1)
    {
        insertBeginning(value);
        return;
    }
    int temp = head;

    for (int i = 1; i < k - 1 && temp != -1; i++)
    {
        temp = nextNode[temp];
    }
    if (temp == -1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    data[count] = value;

    nextNode[count] = nextNode[temp];

    nextNode[temp] = count;

    count++;
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
    insertBeginning(40);
    insertBeginning(30);
    insertBeginning(20);
    insertBeginning(10);

    cout << "Before insertion: ";
    display();

    insertAtKthPosition(25, 3);

    cout << "After insertion: ";
    display();

    return 0;
}