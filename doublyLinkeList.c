#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}Node;

void insert_at_front(Node **head,int data){
    Node *new_node=(Node*)malloc(sizeof(Node));

    new_node->prev=NULL;
    new_node->data=data;

    if(*head==NULL){
        new_node->next=NULL;
        *head=new_node;
        return;
    }
    new_node->next=*head;
    (*head)->prev=new_node;
    *head=new_node;
}

void delete_the_node(Node **head,int value){
    if(*head==NULL){
        printf("List is empty.\n");
        return;
    }
    Node *temp=*head;
    while(temp!=NULL && temp->data!=value){
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Value is not found in the list.\n");
        return;
    }

    if(temp==*head){
        *head=temp->next;
        (*head)->prev=NULL;
        free(temp);
        return;
    }

    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
    }
}

void display(Node **head){
    Node *temp=*head;

    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void main(){
    Node *head=NULL;
    int ch;
    printf("D.Linked List\n");
    printf("1. Insert at front\n");
    printf("2. Delete a node\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                int data;
                printf("Enter data: ");
                scanf("%d",&data);
                insert_at_front(&head,data);
                break;
            case 2:
                int value;
                printf("Enter value to delete: ");
                scanf("%d",&value);
                delete_the_node(&head,value);
                break;
            case 3:
                display(&head);
                break;
            case 4:
                exit(0);
        }
    }
}