#include<stdio.h>
#include<limits.h>

int m[25][25] = {0}, s[25][25] = {0}, p[25] = {0};

void multiplicationOrder(int i, int j){
    if(i == j) printf(" A%d", i);
    else{
        printf(" (");
        multiplicationOrder(i, s[i][j]);
        multiplicationOrder(s[i][j] + 1, j);
        printf(" )");
    }
}

void matrixChainMul(int n){
    for(int diff = 1; diff <= n - 1; diff++){
        for(int row = 1; row <= n - diff; row++){
            int column = row + diff;
            int min = INT_MAX;
            for(int k = row; k < column; k++){
                int value = m[row][k] + m[k + 1][column] + p[row - 1]*p[k]*p[column];
                if(value < min){
                    min = value;
                    s[row][column] = k;
                }
            }
            m[row][column] = min;
        }
    }
    printf("\nThe minimum no of multiplication is: %d", m[1][n]);
}

int main(){
    int n;
    printf("\nEnter the no of matrices:");
    scanf("%d", &n);
    printf("\nEnter the dimensions of the matrices:");
    for(int i = 0; i <= n; i++) scanf("%d", &p[i]);
    matrixChainMul(n);
    printf("\nThe optimized order of multiplication is:");
    multiplicationOrder(1, n);
    return 0;
}