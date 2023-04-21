#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int size, front = 0, rear = 0;
bool qEmpty = true, qFull = false;

void enqueue(int *q, int data){
    if(!qFull){
        q[rear] = data;
        rear = (rear+1)%size;
        qEmpty = false;
        if(rear == front) qFull = true;
    }
    return;
}

int dequeue(int *q){
    int data = -1;
    if(!qEmpty){
        data = q[front];
        front = (front + 1) % size;
        qFull = false;
        if(front == rear) qEmpty = true;
    }
    return data;
}

int main(){
    int *visited, **adjacency, i, j, temp, start, *queue;
    printf("\nGive the no of nodes of the graph:");
    scanf("%d",&size);
    visited = (int *)malloc(size*sizeof(int));
    queue = (int *)malloc(size*sizeof(int));
    adjacency = (int **)malloc(size*sizeof(int *));
    for(i = 0; i < size; i++){
        adjacency[i] = (int *)malloc(size*sizeof(int));
        printf("\nGive the connected nodes for node %d: \n", i + 1);
        while(1){
            scanf("%d",&temp);
            if(temp == -1) break;
            else adjacency[i][temp - 1] = 1;
        }
        for(j = 0; j < size; j++){
            if(adjacency[i][j] != 1) adjacency[i][j] = 0;
        }
    }
    printf("\nAdjacency matrix is:\n");
    for(i = 0;i< 5;i++){
        for(j = 0;j<5;j++){
            printf("%d ",adjacency[i][j]);
        }
        printf("\n");
    }
    printf("\nGive the starting node:");
    scanf("%d", &start);
    printf("\nThe given graph is:\n");
    visited[start - 1] = 1;
    printf("%d ",start);
    enqueue(queue, start - 1);
    while(!qEmpty){
        start = dequeue(queue);
        for(i = 0; i < size; i++){
            if(adjacency[start][i] == 1 && visited[i] != 1){
                visited[i] = 1;
                printf("%d ",i+1);
                enqueue(queue, i);
            }
        }
    }
    return 0;
}