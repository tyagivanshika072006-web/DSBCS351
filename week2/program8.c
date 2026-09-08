#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};


void insertBeginning(struct Node **head, int data)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;

    printf("Node inserted successfully.\n");
}


void insertEnd(struct Node **head, int data)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

  
    if (*head == NULL)
    {
        *head = newNode;
        printf("Node inserted successfully.\n");
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    printf("Node inserted successfully.\n");
}


void insertPosition(struct Node **head, int data, int position)
{
    struct Node *newNode;
    struct Node *temp;
    int i;

    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (position == 1)
    {
        insertBeginning(head, data);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;

    temp = *head;

    for (i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position does not exist!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}


void deleteBeginning(struct Node **head)
{
    struct Node *temp;

    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;

    free(temp);

    printf("Node deleted successfully.\n");
}

void deleteEnd(struct Node **head)
{
    struct Node *temp;
    struct Node *prev;

    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;

        printf("Node deleted successfully.\n");
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

    printf("Node deleted successfully.\n");
}

void deletePosition(struct Node **head, int position)
{
    struct Node *temp;
    struct Node *prev;
    int i;

    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    
    if (position == 1)
    {
        deleteBeginning(head);
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
        printf("Position does not exist!\n");
        return;
    }

    prev->next = temp->next;

    free(temp);

    printf("Node deleted successfully.\n");
}

void display(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


void search(struct Node *head, int key)
{
    struct Node *temp;
    int position = 1;

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element %d found at position %d.\n",
                   key, position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element %d not found.\n", key);
}


int countNodes(struct Node *head)
{
    struct Node *temp;
    int count = 0;

    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}


void reverse(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL)
    {
   
        next = current->next;

        current->next = prev;

        prev = current;

        current = next;
    }

    *head = prev;

    printf("Linked list reversed successfully.\n");
}


void freeList(struct Node **head)
{
    struct Node *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}


int main()
{
    struct Node *head = NULL;

    int choice;
    int data;
    int position;
    int key;

    while (1)
    {
        printf("\n");
        printf("====================================\n");
        printf("   SINGLY LINKED LIST MENU\n");
        printf("====================================\n");
        printf("1.  Insert at Beginning\n");
        printf("2.  Insert at End\n");
        printf("3.  Insert at Given Position\n");
        printf("4.  Delete from Beginning\n");
        printf("5.  Delete from End\n");
        printf("6.  Delete from Given Position\n");
        printf("7.  Display / Traverse\n");
        printf("8.  Search Element\n");
        printf("9.  Count Nodes\n");
        printf("10. Reverse List\n");
        printf("11. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                insertBeginning(&head, data);
                break;

            case 2:
                printf("Enter data: ");
                scanf("%d", &data);

                insertEnd(&head, data);
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &position);

                insertPosition(&head, data, position);
                break;

            case 4:
                deleteBeginning(&head);
                break;

            case 5:
                deleteEnd(&head);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);

                deletePosition(&head, position);
                break;

            case 7:
                display(head);
                break;

            case 8:
                printf("Enter element to search: ");
                scanf("%d", &key);

                search(head, key);
                break;

            case 9:
                printf("Number of nodes = %d\n",
                       countNodes(head));
                break;

            case 10:
                reverse(&head);
                break;

            case 11:
                freeList(&head);

                printf("Program terminated.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
