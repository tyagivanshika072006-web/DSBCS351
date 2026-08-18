#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }

    
    void insertBeginning(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

   
    void insertEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

   
    void display()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;

    list.insertBeginning(30);
    list.insertBeginning(20);
    list.insertBeginning(10);

    list.insertEnd(40);
    list.insertEnd(50);

    cout << "Linked List: ";
    list.display();

    return 0;
}