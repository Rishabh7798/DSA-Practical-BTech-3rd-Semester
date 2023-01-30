// Create a circular linked list having information about a college and perform Insertion at the front end and perform deletion at the end.
#include <stdio.h> 
#include <stdlib.h> 
// Structure to represent a node in the linked list 
struct node{ 
    char college_name[20]; 
    char location[20]; 
    int year_established; 
    struct node* next; 
}; 
// Function to insert a node at the front end 
void insertAtFront(struct node** head, char name[], char location[], int year){ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    strcpy(new_node->college_name, name); 
    strcpy(new_node->location, location); 
    new_node->year_established = year; 
    struct node* last = *head; 

    // If the linked list is empty 
    if(*head == NULL){ 
        *head = new_node; 
        new_node->next = *head; 
        return; 
    } 
    // Else, traverse the linked list to find the last node 
    while(last->next != *head) 
        last = last->next; 
    // Insert the new node at the front end 
    new_node->next = *head; 
    *head = new_node; 
    last->next = *head; 
} 
// Function to delete the last node 
void deleteAtEnd(struct node** head){ 
    struct node* last = *head; 
    struct node* prev; 

    // If the linked list has only one node 
    if (last->next == *head){ 
        free(last); 
        *head = NULL; 
        return; 
    } 
    // Else, traverse the linked list to find the last node 
    while (last->next != *head){ 
        prev = last; 
        last = last->next; 
    } 

    // Delete the last node 
    prev->next = *head; 
    free(last); 
} 
// Function to print the linked list 
void printList(struct node* head){ 
    struct node* temp = head; 

    if (head != NULL) { 
        do { 
            printf("\nCollege Name: %s\n", temp->college_name); 
            printf("Location: %s\n", temp->location); 
            printf("Year Established: %d\n", temp->year_established); 
            temp = temp->next; 
        } while (temp != head); 
    } 
} 
// Driver program 
int main(){ 
    struct node* head = NULL; 

    insertAtFront(&head, "MIT", "Boston", 1861); 
    insertAtFront(&head, "Harvard", "Boston", 1852); 
    insertAtFront(&head, "Caltech", "California", 1891); 
    printList(head); 

    deleteAtEnd(&head); 
    printf("\nAfter deletion at end:\n"); 
    printList(head); 

    return 0; 
}
/* Here is an algorithm for performing insertion and deletion in a circular linked list:
     Insertion at front end:
        1. Create a new node with the college information.
        2. If the list is empty, set the new node as the head and make it point to itself.
        3. If the list is not empty, set the new node as the head and make it point to the previous head.
        4. Update the next pointer of the previous head to point to the new node.
     Deletion at end:
        1. Start from the head node and traverse the list until you reach the node before the last node.
        2. Update the next pointer of the node before the last node to point to the head node.
        3. Remove the last node.
Note: The algorithm assumes that the circular linked list is implemented using a node class with a next pointer and a value representing the college information.
*/