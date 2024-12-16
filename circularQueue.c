//Circular Queue

#include<stdio.h>
#include<stdlib.h>

#define max 2

int Queue[max];

int isFull(int *front,int *rear){
    if((*front==*rear+1) || (*front==0 && *rear==max-1)){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(int *front,int *rear){
    if(*front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int *front,int *rear){
    int ele;
    if(isFull(front,rear)){
        printf("Queue is full\n");
    }
    else{
        if(*front==-1){
            *front=0;
        }
        
        *rear=(*rear+1)%max;
    
        printf("Enter the element to insert: ");
        scanf("%d",&ele);
        Queue[*rear]=ele;
        printf("%d has been enqueued into the queue.\n",Queue[*rear]);
    }
}

void dequeue(int *front,int *rear){
    if(isEmpty(front,rear)){
        printf("Queue is empty\n");
    }
    else{
        printf("%d has been dequeue from the queue.\n",Queue[*front]);
        if(*front==*rear){
            *front=*rear=-1;
        }
        else{
            *front=(*front+1)%max;
        }
    }
}

void display(int *front,int *rear){
    if(isEmpty(front,rear)){
        printf("Queue is empty.\n");
    }
    else{
        printf("Queue elements are: ");
        if(*rear>*front){
            for(int i=*front;i<=*rear;i++){
                printf("%d\n",Queue[i]);
            }
        }
        else{
            for(int i=0;i<=*rear;i++){
                printf("%d\n",Queue[i]);
            }
            for(int i=*front;i<=max-1;i++){
                printf("%d\n",Queue[i]);
            }
        }
    }
}

void main(){
    int front=-1,rear=-1;
    int ch;
    while(1){
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
            enqueue(&front,&rear);
            break;
            case 2:
            dequeue(&front,&rear);
            break;
            case 3:
            display(&front,&rear);
            break;
            case 4:
            exit(0);
            default:
            printf("Invalid choice.\n");
        }
    }
}

