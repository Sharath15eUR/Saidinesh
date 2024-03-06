#include <stdio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();
void sortQueue();

int items[SIZE], front = -1, rear = -1;

int main()
{

    enQueue(4);
    enQueue(2);
    enQueue(7);
    enQueue(5);
    enQueue(1);

    printf("\nOriginal queue:");
    display();

    sortQueue();

    printf("\nSorted queue:");
    display();

    return 0;
}

void enQueue(int value)
{
    if (rear == SIZE - 1)
        printf("\nQueue is Full");
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = value;
        printf("\nInserted at the end -> %d", value);
    }
}

void deQueue()
{
    if (front == -1)
        printf("\nQueue is Empty!!");
    else
    {
        printf("\nDeleted the front item : %d", items[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display()
{
    if (rear == -1)
        printf("\nQueue is Empty!!!");
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for (i = front; i <= rear; i++)
            printf("%d  ", items[i]);
    }
    printf("\n");
}

void sortQueue()
{
    int i, j, temp;
    for (i = front; i <= rear; i++)
    {
        for (j = i + 1; j <= rear; j++)
        {
            if (items[i] > items[j])
            {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
