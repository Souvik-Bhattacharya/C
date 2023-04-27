#include<stdio.h>
#include<limits.h>

int m[25][25];

void display(int n){
    printf("\nThe resultant matrix is:");
    for(int row = 1; row <= n; row++){
        printf("\n");
        for(int column = 1; column <= n; column++){
            printf(" %d", m[row][column]);
        }
    }
}

void floydWarshall(int n){
    for(int k = 1; k <= n; k++){
        for(int row = 1; row <= n; row++){
            for(int column = 1; column <= n; column++){
                if(m[row][k] + m[k][column] < m[row][column]) m[row][column] = m[row][k] + m[k][column];
            }
        }
    }
    display(n);
}

int main(){
    int n;
    printf("\nEnter no of vertices:");
    scanf("%d",&n);
    for(int row = 1; row <= n; row++){
        printf("\nEnter the row %d of matrix:\n", row);
        for(int column = 1; column <= n; column++){
            scanf(" %d", &m[row][column]);
            if(m[row][column] == -1) m[row][column] = INT_MAX - 100;
        }
    }
    floydWarshall(n);
    return 0;
}