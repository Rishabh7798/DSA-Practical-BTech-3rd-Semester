// Create a doubly linked list with nodes having information about an employee and perform Insertion at front of doubly linked list and perform deletion at end of that doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct employee {
    int id;
    char name[20];
    float salary;
    struct employee *prev;
    struct employee *next;
};
void insertAtFront(struct employee **head, int id, char name[20], float salary){
    struct employee *newNode;
    newNode = (struct employee*)malloc(sizeof(struct employee));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->salary = salary;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}
void deleteAtEnd(struct employee **head){
    struct employee *temp, *prev;
    temp = *head;
    if (*head == NULL)
        printf("List is empty.\n");

    else{
        while (temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Deleted node is: %d\t%s\t%f\n", temp->id, temp->name, temp->salary);
        free(temp);
    }
}
void displayList(struct employee *head){
    struct employee *temp;
    temp = head;
    printf("Employee Information:\n");
    while (temp != NULL){
        printf("%d\t%s\t%f\n", temp->id, temp->name, temp->salary);
        temp = temp->next;
    }
}
int main(){
    int i, n, id;
    char name[20];
    float salary;
    struct employee *head;
    head = NULL;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Enter id, name and salary of employee %d: ", i + 1);
        scanf("%d%s%f", &id, name, &salary);
        insertAtFront(&head, id, name, salary);
    }
    deleteAtEnd(&head);
    displayList(head);
    return 0;
}
/* Here is an algorithm to perform insertion at the front of a doubly linked list and deletion at the end of the doubly linked list:
    • Insertion at the front:
        1. Create a new node with the employee information.
        2. If the linked list is empty, set the new node as the head and tail of the linked list.
        3. If the linked list is not empty, set the next pointer of the new node to the current head, and the previous pointer of the current head to the new node.
        4. Update the head of the linked list to be the new node.
    • Deletion at the end:
        1. If the linked list is empty, do nothing.
        2. If the linked list has only one node, set the head and tail to ‘null’.
        3. If the linked list has multiple nodes, set the next pointer of the second to last node to ‘null’ and the previous pointer of the tail to the second to last node.
        4.	Update the tail of the linked list to be the second to last node.
Note: The doubly linked list is assumed to be implemented with a head and tail pointer pointing to the first and last node respectively. The head node has a previous pointer equal to ‘null’, and the tail node has a next pointer equal to ‘null’.
*/