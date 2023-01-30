//  Implement insertion, deletion, and display (Inorder, Preorder, postorder) on binary search tree with the information in the tree about the details of an automobile (type, company, year of make).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
    char type[20];
    char company[20];
    int year;
    struct node *left;
    struct node *right;
};
struct node *newNode(char type[], char company[], int year){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->type, type);
    strcpy(temp->company, company);
    temp->year = year;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *insert(struct node *root, char type[], char company[], int year){
    if (root == NULL){
        return newNode(type, company, year);
    }
    if (strcmp(type, root->type) < 0){
        root->left = insert(root->left, type, company, year);
    } else if (strcmp(type, root->type) > 0){
        root->right = insert(root->right, type, company, year);
    }
    return root;
}
void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        printf("Type: %s, Company: %s, Year: %d\n", root->type, root->company, root->year);
        inorder(root->right);
    }
}
void preorder(struct node *root){
    if (root != NULL){
        printf("Type: %s, Company: %s, Year: %d\n", root->type, root->company, root->year);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("Type: %s, Company: %s, Year: %d\n", root->type, root->company, root->year);
    }
}
int main(){
    struct node *root = NULL;
    root = insert(root, "SUV", "Tesla", 2021);
    insert(root, "Sedan", "Toyota", 2019);
    insert(root, "Hatchback", "Honda", 2020);
    insert(root, "Crossover", "Ford", 2022);
    printf("\nInorder Traversal: \n");
    inorder(root);
    printf("\nPreorder Traversal: \n");
    preorder(root);
    printf("\nPostorder Traversal: \n");
    postorder(root);
    return 0;
}
/* Here is an algorithm for performing insertion, deletion, and display (Inorder, Preorder, Postorder) on a binary search tree:
    • Insertion:
        1. Create a new node with the automobile information.
        2. Start from the root node and traverse the tree until you reach a leaf node.
        3. If the value of the new node is less than the value of the current node, go to the left child.
        4. If the value of the new node is greater than the value of the current node, go to the right child.
        5. When you reach a leaf node, set the new node as the left or right child depending on the value comparison.
    • Deletion:
        1. Start from the root node and traverse the tree until you reach the node to be deleted.
        2. If the node to be deleted has no children, simply remove the node by setting its parent's left or right child to null.
        3. If the node to be deleted has one child, remove the node by setting its parent's left or right child to the child of the node to be deleted.
        4. If the node to be deleted has two children, find the minimum value in the right subtree and replace the value of the node to be deleted with the minimum value. Then delete the node with the minimum value in the right subtree.
    • Display (Inorder, Preorder, Postorder):
         Inorder Traversal:
            1. Traverse the left subtree using the inorder traversal.
            2. Visit the root node and display the automobile information.
            3. Traverse the right subtree using the inorder traversal.
         Preorder Traversal:
            1. Visit the root node and display the automobile information.
            2. Traverse the left subtree using the preorder traversal.
            3. Traverse the right subtree using the preorder traversal.
         Postorder Traversal:
            1. Traverse the left subtree using the postorder traversal.
            2. Traverse the right subtree using the postorder traversal.
            3. Visit the root node and display the automobile information.
Note: The value of the node in the binary search tree is determined based on the automobile information, such as type, company, and year of make. The algorithm assumes that the binary search tree is implemented using a node class with ‘left’, ‘right’, and ‘parent’ pointers, as well as a value representing the automobile information.
*/