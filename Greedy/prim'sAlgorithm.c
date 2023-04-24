#include<stdio.h>
#include<limits.h>

int visited[25] = {0}, minimumCost = 0;

void display(int n, int cost[25][25]){
    printf("\nThe input cost matrix is:\n");
    for(int row = 1; row <= n; row++){
        printf("\n");
        for(int column = 1; column <= n; column++){
            if(cost[row][column] == INT_MAX) printf(" 0");
            else printf(" %d", cost[row][column]);
        }
    }
}

void prims(int n, int cost[25][25]){
    int e = 1, a, b;
    visited[1] = 1;
    printf("\nThe edges of the minimal spanning tree is:\n");
    while(e < n){
        int min = INT_MAX;
        for(int row = 1; row <= n; row++){
            for(int column = 1; column <= n; column++){
                if(cost[row][column] < min){
                    if(visited[row] == 1){
                        min = cost[row][column];
                        a = row;
                        b = column;
                    }
                }
            }
        }
        visited[b] = 1;
        printf("\nThe edge %d is: %d-%d with weight %d", e++, a, b, min);
        minimumCost += min;
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    printf("\nThe minimum cost is: %d", minimumCost);
}

int main(){
    int v, e, x, y, w, cost[25][25];
    printf("\nEnter the no of vertices:");
    scanf("%d", &v);
    for(int row = 1; row <= v; row++){
        for(int column = 1; column <= v; column++) cost[row][column] = INT_MAX;
    }
    printf("\nEnter the no of edges:");
    scanf("%d", &e);
    for(int i = 1; i <= e; i++){
        printf("\nEnter the edge %d and its weight: ", i);
        scanf("%d %d %d", &x, &y, &w);
        cost[x][y] = w;
        cost[y][x] = w;
    }
    display(v, cost);
    prims(v, cost);
    return 0;
}
