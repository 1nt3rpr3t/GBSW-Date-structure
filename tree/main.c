#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *root;

Node* insert(Node *root, int data){
    if(root == NULL){
        root = (Node *) malloc(sizeof(Node));
        root -> data = data;
        root -> left = NULL;
        root -> right = NULL;
    }
    else if(root -> data < data){
        root -> right = insert(root -> right, data);
    }
    else{
        root -> left =  insert(root -> left, data);
    }

    return root;
}

void preorder(Node *root){ //VLR
    if(root){
        printf("%d ", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(Node *root){ //LVR
    if(root){
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root -> right);
    }
}

void postorder(Node *root){ //LRV
    if(root){
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ", root -> data);
    }
}

int main(){
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 14);
    root = insert(root, 11);
    root = insert(root, 16);
    preorder(root);
    inorder(root);
    postorder(root);
}
