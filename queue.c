#include<stdio.h>
#include<stdlib.h>
#define max 100

int queue[max];

void insert(int *front,int *rear){
    int ele;
    if(rear==max-1){
        printf("Queue is full.\n");
    }
    else{
        *rear=*rear+1;
        printf("Enter the element to insert in the queue: ");
        scanf("%d",&ele);
        queue[*rear]=ele;
        printf("%d has been inserted in the queue.\n",queue[*rear]);
    }
}

void delete(int *front,int *rear){
    if(*front==-1 || *front>*rear){
        printf("Queue is empty.\n");
    }
    if(*front==-1){
        *front=0;
    }
    printf("%d has been deleted from the queue.\n",queue[*front]);
    *front++;
}

void display(int *front,int *rear){
    if(*front==-1 || *front>*rear){
        printf("Queue is empty.\n");
    }
    printf("Queue Elements are: \n");
    for(int i=*front;i<=*rear;i++){
        printf("%d",queue[i]);
    }
    if(*front>*rear){
        *front=*rear=-1;
    }
}

void main(){
    int ch;
    int front=-1,rear=-1;
    while(1){
        printf("Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                insert(&front,&rear);
                break;
            case 2: 
                delete(&front,&rear);
                break;
            case 3:
                display(&front,&rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.");

        }

    }
}

