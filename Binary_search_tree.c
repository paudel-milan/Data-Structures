#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));

    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

Node* insert(Node* root,int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }

    return root;
}

void preOrder(Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(Node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

void main(){
    Node* root=NULL;

    root=insert(root,50);
    insert(root,80);
    insert(root,10);
    insert(root,70);
    insert(root,30);
    insert(root,20);
    insert(root,90);

    printf("PreOrder Traversal: \n");
    preOrder(root);
    printf("\n");

    printf("InOrder Traversal: \n");
    inOrder(root);
    printf("\n");

    printf("PostOrder Traversal: \n");
    postOrder(root);
    printf("\n");


}