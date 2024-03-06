#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void insertAtEnd(struct node **head_ref, int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    struct node *temp = *head_ref;
    newNode->data = data;
    newNode->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return;
}

void traversal(struct node *head)
{
    struct node *temp = head;
    printf("\nElements in the linked List:");
    while (temp != NULL)
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int size, data;
    printf("Enter the size of the Sorted Array:");
    scanf("%d", &size);
    struct node *head = NULL;
    printf("\nEnter the Elements of the array:");
    
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    traversal(head);
    printf("\nRemoving duplicate Elements:");
    struct node *temp = head;
    while(temp->next != NULL)
    {
        struct node *nextNode = temp->next;
        if(temp->data == nextNode->data)
        {
            temp->next = nextNode->next;
            free(nextNode);
        }else{
            temp = temp->next;
        }
    }
    traversal(head);



    return 0;
}
