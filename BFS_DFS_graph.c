#include<stdio.h>
#include<stdlib.h>
#define max 5

void bfs(int adj[][max],int visited[],int start){
    int queue[max],front=-1,rear=-1;

    for(int k=0;k<5;k++){
        visited[k]=0;
    }
    queue[++rear]=start;
    front++;
    visited[start]=1;

    for(int i=0;i<max;i++){
        start=queue[rear--];
        printf("%d ",start);

        if(adj[start][i]==1 && visited[i]==0){
            queue[++rear]=i;
            visited[i]=1;
        }
    }
}

void dfs(int adj[][max],int visited[],int start){
    int stack[max],top=-1;

    for(int k=0;k<,5;k++){
        visited[k]=0;
    }
    stack[++top]=start;
    visited[start]=1;

    for(int i=0;i<max;k++){
        start=stack[top--];
        printf("%d ",start);

        if(adj[start][i]==1 && visitor[i]==0){
            stack[++top]=i;
            visited[i]=1
        }
    }
}

void main(){
    int adj[max][max];
    int visited[max]={0};
    int ch;

    printf("Main---Menu\n");
    printf("1. Enter the values in graph\n");
    printf("2. DFS Traversal\n");
    printf("3. BFS Traversal\n");
    printf("4. Exit\n");

    while(1){
        printf("Enter the choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter the adjacency matrix: ");
                for(int i=0;i<max;i++){
                    for(int j=0;j<max;j++){
                        scanf("%d",&adj[i][j]);
                    }
                }
                break;
            case 2:
                printf("DFS Traversal\n");
                dfs(adj,visited,0);
                break;
            case 3:
                printf("BFS Traversal\n");
                bfs(adj,visited,0);
                break;
            case 4:
                exit(0);
        }
    
    }
}