#include<stdio.h>

int adjacency[25][25] = {0}, visited[25] = {0}, v, e;

void DFS(int start){
    visited[start] = 1;
    printf(" %d",start);
    for(int column = 1; column <= v; column++){
        if(adjacency[start][column] != 0 && visited[column] != 1) DFS(column);
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
    printf("\nThe DFS traversal of the graph is:");
    DFS(start);
    return 0;
}