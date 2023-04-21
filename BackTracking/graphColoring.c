#include<stdio.h>

int graph[25][25], color[25];

void display(int v){
    printf("\nThe colors of the %d vertices are:\n",v);
    for(int vertex = 1; vertex <= v; vertex++){
        printf("\nVertex %d -> color %d",vertex, color[vertex]);
    }
}

void nextColor(int node, int v){
    if(node == v + 1) display(v);
    else{
        color[node] = 1;
        for(int vertex = 1; vertex <= v - 1; vertex++){
            if(graph[vertex][node] == 1 && color[vertex] == color[node]) color[node]++;
        }
        nextColor(node + 1, v);
    }
}

int main(){
    int v, e, x, y;
    printf("\nEnter the no of vertices:");
    scanf("%d",&v);
    printf("\nEnter the no of edges:");
    scanf("%d",&e);
    for(int row = 1; row <= v; row++){
        for(int column = 1; column <= v; column++) graph[row][column] = 0;
    }
    printf("\nEnter the edges:\n");
    for(int i = 1; i <= e; i++){
        printf("\nEnter the edge %d: ",i);
        scanf("%d %d",&x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    nextColor(1,v);
    return 0;
}