#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node *insertSorted(struct Node *head, int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        return newNode;
    }

    if (value < head->data)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    struct Node *current = head;

    while (current->next != NULL && current->next->data < value)
    {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

int main()
{
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    struct Node *head = NULL;

    printf("Enter %d elements in random order:\n", size);
    for (int i = 0; i < size; i++)
    {
        int value;
        scanf("%d", &value);
        head = insertSorted(head, value);
    }

    printf("Sorted Doubly Linked List: ");
    display(head);

    return 0;
}
