#include<stdio.h>
#include<stdlib.h>

int main(){
    int **arr,*col_arr,row,col,i,j;
    printf("Enter the row size:");
    scanf("%d",&row);
    arr=(int **)malloc(row*sizeof(int *));
    col_arr=(int *)malloc(row*sizeof(int));
    for(i=0;i<row;i++){
        printf("Enter the coloumn size of row %d:",i+1);
        scanf("%d",&col);
        col_arr[i]=col;
        arr[i]=(int *)malloc(col*sizeof(int));
        printf("Enter the elements of row %d:\n",i+1);
        for(j=0;j<col;j++)
        scanf("%d",&arr[i][j]);
    }
    printf("The array entered is:\n");
    for(i=0;i<row;i++){
        for(j=0;j<col_arr[i];j++)
        printf("%d ",arr[i][j]);
        printf("\n");
    }
    return 0;
}