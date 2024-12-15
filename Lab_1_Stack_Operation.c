#include<stdio.h>
#include<stdlib.h>
#define max 5

void push(int stack[],int *top){
    int ele;
    if(*top==max-1){
        printf("Stack Overflow.\n");
        return;
    }
    printf("Enter the element: ");
    scanf("%d",&ele);
    stack[++(*top)]=ele;
    printf("%d has been pushed into the stack.\n",stack[*top]);
}

void pop(int stack[],int *top){
    if(*top==-1){
        printf("Stack Underflow.\n");
        return;
    }
    printf("%d has been poped from the stack.\n",stack[(*top)--]);
}

void display(int stack[],int *top){
    if(*top==-1){
        printf("Stack Underflow.\n");
        return;
    }
    for(int i=0;i<=(*top);i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){
    int stack[max],top=-1;
    int ch;
    printf("Stack Operation\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while(1){
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push(stack,&top);
                break;
            case 2:
                pop(stack,&top);
                break;
            case 3:
                display(stack,&top);
                break;
            case 4:
                exit(0);
        }
    }

    return 0;

}