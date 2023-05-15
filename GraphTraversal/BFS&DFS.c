#include<stdio.h>

int adjacency[25][25] = {0}, visited[25] = {0}, visitedDFS[25] = {0}, queue[25] = {0}, v, e, front = -1, rear = -1;

void display(int vertex){
    printf(" %d", vertex);
}

void enqueue(int data){
    rear++;
    queue[rear] = data;
}

int dequeue(){
    front++;
    return queue[front];
}

void BFS(int s){
    printf("\nThe BFS traversal of the graph is:");
    visited[s] = 1;
    enqueue(s);
    while(front != rear){
        int vertex = dequeue();
        display(vertex);
        for(int column = 1; column <= v; column++){
                if(adjacency[vertex][column] != 0 && visited[column] != 1){
                    visited[column] = 1;
                    enqueue(column);
                }
        }
    }
}

void DFS(int start){
    visitedDFS[start] = 1;
    display(start);
    for(int column = 1; column <= v; column++){
        if(adjacency[start][column] != 0 && visitedDFS[column] != 1) DFS(column);
    }
}

int main(){
    int s, d, start;
    printf("\nEnter the no of vertices of the graph:");
    scanf("%d", &v);
    printf("\nEnter the no of edges of the graph:");
    scanf("%d", &e);
    for(int edge = 1; edge <= e; edge++){
        printf("\nEnter the edge %d: ",edge);
        scanf("%d %d", &s, &d);
        adjacency[s][d] = 1;
        adjacency[d][s] = 1;
    }
    printf("\nEnter the starting vertex:");
    scanf("%d", &start);
    BFS(start);
    printf("\nThe DFS traversal of the graph is:");
    DFS(start);
    return 0;
}