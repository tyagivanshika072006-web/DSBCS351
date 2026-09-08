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


void deleteBeginning(struct Node **head)
{
    struct Node *temp;

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    free(temp);
}

void deleteEnd(struct Node **head)
{
    struct Node *temp;
    struct Node *prev;

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}


void deletePosition(struct Node **head, int position)
{
    struct Node *temp;
    struct Node *prev;
    int i;

    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (position < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (position == 1)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    temp = *head;

    for (i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position does not exist\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
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

    printf("Original list:\n");
    display(head);

    deleteBeginning(&head);

    printf("After deletion from beginning:\n");
    display(head);

    deleteEnd(&head);

    printf("After deletion from end:\n");
    display(head);

    deletePosition(&head, 2);

    printf("After deletion from position 2:\n");
    display(head);

    return 0;
}
