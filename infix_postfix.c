#include<stdio.h>
#define max 50

void push(char stack[],int *top,char e){
    stack[++(*top)]=e;
}

char pop(char stack[],int *top){
    return stack[(*top)--];
    
}

int precedence(char e){
    if(e=='('){
        return 0;
    }
    else if(e=='+' || e=='-'){
        return 1;
    }
    else if(e=='*' || e=='/'){
        return 2;
    }
    else{
        return -1;
    }
}

void main(){
    char stack[max];
    int top=-1;
    char x;
    char exp[max];
    char *e;
    printf("Enter the infix expression: ");
    scanf("%s",exp);
    e=exp;

    while(*e!='\0'){
        if(isalnum(*e)){
            printf("%c",*e);
        }
        else if(*e=='('){
            push(stack,&top,*e);
        }
        else if(*e==')'){
            while((x=pop(stack,&top))!='('){
                printf("%c",x);
            }
            pop(stack,&top);
        }
        else{
            while(precedence(stack[top])>precedence(*e)){
                x=pop(stack,&top);
                printf("%c",x);
            }
            push(stack,&top,*e);
        }
        e++;
    }

    while(top!=-1){
        x=pop(stack,&top);
        printf("%c",x);
    }
}