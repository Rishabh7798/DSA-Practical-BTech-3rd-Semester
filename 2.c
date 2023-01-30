// Create a stack and perform Pop, Push, and Traverse operations on the stack using a Linear Linked list 
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}
void pop() {
    if (top == NULL)
        printf("Stack is empty\n");
    else {
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
}
void traverse() {
    if (top == NULL)
        printf("Stack is empty\n");
    else {
        struct Node *temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    push(1);
    push(2);
    push(3);
    traverse();
    pop();
    traverse();
    return 0;
}

/* 
Stack Algorithm Using Linear Linked List:
1.	Create a class Node that contains a value and a pointer to the next node.
2.	Create a class Stack that contains a pointer to the top node of the stack.
3.	Implement the following operations:
    •	Push:
        1.	Create a new node and set its value to the value to be pushed.
        2.	Set the next pointer of the new node to the current top node.
        3.	Update the top pointer to the new node.
    •	Pop:
        1.	If the stack is empty, return null.
        2.	Store the value of the top node in a variable.
        3.	Update the top pointer to the next node.
        4.	Return the stored value.
    •	Traverse:
        1.	Create a current pointer and set it to the top node.
        2.	Repeat the following until the current pointer is null:
            a.	Print the value of the current node.
            b.	Update the current pointer to the next node.
*/