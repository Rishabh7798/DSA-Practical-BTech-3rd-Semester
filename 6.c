// Create a linked list with nodes having information about a student. Insert a new node at the specified position 
#include<stdio.h>
#include<stdlib.h>
struct student {
    int roll;
    char name[20];
    float marks;
    struct student *next;
};
void insertAtPosition(struct student** head, int roll, char name[20], float marks, int pos){
    int k = 1;
    struct student *p, *q, *newNode;
    newNode = (struct student*)malloc(sizeof(struct student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->marks = marks;
    p = *head;
    if (pos == 1){
        newNode->next = p;
        *head = newNode;
    }
    else{
        while ((p != NULL) && (k < pos)){
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
    }
}
void displayList(struct student *head){
    struct student *p;
    p = head;
    while (p != NULL){
        printf("%d\t%s\t%f\n", p->roll, p->name, p->marks);
        p = p->next;
    }
}
int main(){
    int i, n, pos;
    int roll;
    char name[20];
    float marks;
    struct student *head;
    head = NULL;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        printf("Enter roll, name and marks of student %d: ", i + 1);
        scanf("%d%s%f", &roll, name, &marks);
        insertAtPosition(&head, roll, name, marks, i + 1);
    }
    printf("Enter the position where you want to insert a new node: ");
    scanf("%d", &pos);
    printf("Enter the roll, name and marks of new student: ");
    scanf("%d%s%f", &roll, name, &marks);
    insertAtPosition(&head, roll, name, marks, pos);
    printf("Student List:\n");
    displayList(head);
    return 0;
}
/* Here is an algorithm to insert a new node into a linked list at a specified position:
1. Create a new node with the student information.
2. Check if the linked list is empty or the position is 0. If so, set the new node as the head of the linked list.
3. If the position is not 0, start from the head of the linked list and traverse the linked list until you reach the node before the specified position.
4. Set the next pointer of the new node to the node currently at the specified position.
5. Set the next pointer of the node before the specified position to the new node.
6. End the algorithm.
Note: The position is a zero-based index, and the head of the linked list is considered to be at position 0. If the specified position is greater than the number of nodes in the linked list, the new node can be inserted at the end of the linked list.
*/