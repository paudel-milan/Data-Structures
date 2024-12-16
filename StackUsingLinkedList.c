#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//Insertion at beginning
void push(struct Node**head,struct Node **top){
    int data;
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data to insert: ");
    scanf("%d",&data);
    new_node->data=data;
    
    new_node->next=(*head);
    *head=new_node;
    *top=new_node;
    printf("%d has been inserted.\n",(*top)->data);

}

//Deletion at beginning
void pop(struct Node**head,struct Node **top){
    if(*head==NULL){
        printf("Stack underflow.\n");
        return;
    }
    printf("%d has been deleted.\n",(*top)->data);
    struct Node *temp=(*head);
    (*head)=(*head)->next;
    free(temp);
    *top=(*head);
}

void display(struct Node **head,struct Node **top){
    if(*head==NULL){
        printf("Stack underflow.\n");
        return;
    }
    struct Node *temp=*head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

void main() {
    int ch;
    struct Node *head=NULL;
    struct Node *top=head;
    
    printf("Stack operations:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push(&head,&top);
                break;
            case 2:
                pop(&head,&top);
                break;
            case 3:
                display(&head,&top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please choose between 1-4.\n");
        }
    }
}

