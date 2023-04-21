#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int size, *visited, **adjacency;

void DFS(int start){
    visited[start] = 1;
    printf("%d ",start+1);
    for(int i = 0; i < size; i++){
        if(adjacency[start][i] == 1 && visited[i] != 1) DFS(i);
    }
}

int main(){
    int i, j, temp, start;
    printf("\nGive the no of nodes of the graph:");
    scanf("%d",&size);
    visited = (int *)malloc(size*sizeof(int));
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
    DFS(start-1);
    return 0;
}