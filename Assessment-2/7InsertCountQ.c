#include <stdio.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();
int countElements();
int isEmpty();

int items[SIZE], front = -1, rear = -1;

int main()
{

    printf("Initialize a queue!\n");

    if (isEmpty())
    {
        printf("Check the queue is empty or not? Yes\n");
    }
    else
    {
        printf("Check the queue is empty or not? No\n");
    }

    printf("Number of elements in queue: %d\n", countElements());

    printf("Insert some elements into the queue:\n");
    enQueue(1);
    enQueue(2);
    enQueue(3);
    display();
    printf("Number of elements in queue: %d\n", countElements());

    printf("Delete two elements from the said queue:\n");
    deQueue();
    deQueue();
    display();
    printf("Number of elements in queue: %d\n", countElements());

    printf("Insert another element into the queue:\n");
    enQueue(4);
    display();
    printf("Number of elements in the queue: %d\n", countElements());

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

int countElements()
{
    if (front == -1)
        return 0;
    else
        return (rear - front + 1);
}

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
