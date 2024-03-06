#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* rotateByN(struct Node* head, int N) {
    if (head == NULL || N <= 0) {
        return head;
    }

    struct Node* current = head;
    int count = 1;

    while (count < N && current != NULL) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return head;
    }

    struct Node* newHead = current->next;

    if (newHead != NULL) {
        newHead->prev = NULL;
        current->next = NULL;

        struct Node* temp = newHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = head;
        head->prev = temp;
    }

    return newHead;
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n; 
    printf("Enter the size of the list:");
    scanf("%d", &n);

    char inputChar;
    printf("Enter characters:\n");

    for (int i=0;i<n;i++) {
        scanf(" %c", &inputChar);

        struct Node* newNode = createNode(inputChar);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    printf("Input: ");
    display(head);

    int N;
    printf("Enter the number of nodes to rotate by: ");
    scanf("%d", &N);

    head = rotateByN(head, N);

    printf("Output: ");
    display(head);

    return 0;
}
