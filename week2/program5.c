#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


void insertEnd(struct Node **head, int data)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}


void search(struct Node *head, int key)
{
    struct Node *temp = head;
    int position = 1;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element %d found at position %d\n",
                   key, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element %d not found\n", key);
}


void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Linked List: ");
    display(head);

    search(head, 30);

    search(head, 50);

    return 0;
}
