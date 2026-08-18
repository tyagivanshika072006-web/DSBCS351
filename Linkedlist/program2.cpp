#include <iostream>
using namespace std;

class LinkedList {
    int data[100];
    int next[100];
    int head;
    int size;

public:
    LinkedList() {
        head = -1;
        size = 0;
    }

    
    void insertBeginning(int value) {
        data[size] = value;
        next[size] = head;
        head = size;
        size++;
    }

    
    void display() {
        int temp = head;

        while (temp != -1) {
            cout << data[temp] << " -> ";
            temp = next[temp];
        }

        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertBeginning(30);
    list.insertBeginning(20);
    list.insertBeginning(10);

    cout << "Linked List: ";
    list.display();

    return 0;
}