// Create a Binary Tree and perform Tree Traversals (Preorder, Postorder, lnorder) using the concept of recursion 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
}; 
struct node *newNode(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void preOrder(struct node *root){
    if(root){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct node *root){
    if(root){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void postOrder(struct node *root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
/* Here is an algorithm for tree traversals in a binary tree using recursion:
    • Preorder Traversal:
        1. Visit the root node.
        2. Traverse the left subtree using the preorder traversal.
        3. Traverse the right subtree using the preorder traversal.
    • Inorder Traversal:
        1. Traverse the left subtree using the inorder traversal.
        2. Visit the root node.
        3. Traverse the right subtree using the inorder traversal.
    • Postorder Traversal:
        1. Traverse the left subtree using the postorder traversal.
        2. Traverse the right subtree using the postorder traversal.
        3. Visit the root node.
Note: For each subtree, the algorithm recursively calls itself with the root of the subtree as the new root until it reaches a leaf node. The leaf nodes have a ‘null’ value for both the left and right child.
*/