// Create a Linear Queue using Linked List and implement different operations such as insert, delete, and display the queue elements
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Queue {
    struct Node *front, *rear;
};
void enqueue(struct Queue *q, int value) {
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}
void dequeue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}
void display(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Queue q;
    q.front = q.rear = NULL;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}
/* Linear Queue Using Linked List Algorithm:
1. Create a class Node that contains a value and a pointer to the next node.
2. Create a class Queue that contains two pointers, front and rear, pointing to the front and rear nodes of the queue, respectively.
3. Implement the following operations:

    • Insert (Enqueue):
        1. Create a new node and set its value to the value to be inserted.
        2. If the queue is empty, set the front and rear pointers to the new node.
        3. If the queue is not empty, set the next pointer of the rear node to the new node and update the rear pointer to the new node.

    • Delete (Dequeue):
        1. If the queue is empty, return null.
        2. Store the value of the front node in a variable.
        3. Update the front pointer to the next node.
        4. If the front pointer becomes null, update the rear pointer to null as well.
        5. Return the stored value.

    • Display:
        1. Create a current pointer and set it to the front node.
        2. Repeat the following until the current pointer is null:
            a. Print the value of the current node.
            b. Update the current pointer to the next node.
*/