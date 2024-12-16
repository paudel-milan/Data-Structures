#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *front=NULL,*rear=NULL;

void enqueue(){
    int data;
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data to be inserted: ");
    scanf("%d",&data);
    new_node->data=data;
    new_node->next=NULL;
    if(front==NULL && rear==NULL){
        front=rear=new_node;
    }
    else{
        rear->next=new_node;
        rear=new_node;
    }
    printf("%d has been enqueued.\n",rear->data);
}

void dequeue(){
    struct Node *temp=front;
    if(front==NULL && rear==NULL){
        printf("Queue is empty.\n");
        return;
    }
    printf("%d has been dequeued.\n",front->data);
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
    }
    free(temp);
}

void display(){
    struct Node *temp=front;
    if(front==NULL && rear==NULL){
        printf("Queue is empty.\n");
        return;
    }
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void main(){
    
    int ch;
    
    printf("Queue operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please choose between 1-4.\n");
        }
    }
}