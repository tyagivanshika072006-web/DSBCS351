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

void display()
{
    int temp = head;

    while (temp != -1)
    {
        cout << data[temp] << " -> ";
        temp = nextNode[temp];
    }

    cout << "NULL";
}

int main()
{
    insertBeginning(30);
    insertBeginning(20);
    insertBeginning(10);
    insertBeginning(5);

    display();

    return 0;
}