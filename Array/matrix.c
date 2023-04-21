#include<stdio.h>
int row_sorting(int mat[10][10],int m,int n){
    int i,j,k,tmp;
    for(i=0;i<m;i++){
        for(j=1;j<n;j++){
            for(k=1;k<=n-j;k++){
                if(mat[i][k]<mat[i][k-1]){
                    tmp=mat[i][k];
                    mat[i][k]=mat[i][k-1];
                    mat[i][k-1]=tmp;
                }
            }
        }
        printf("The largest no. of row %d is: %d\n",i+1,mat[i][n-1]);
        printf("The smallest no. of row %d is: %d\n",i+1,mat[i][0]);
        printf("\n");
    }   
}
int coloumn_sorting(int mat[10][10],int m,int n){
    int i,j,k,tmp;
    for(j=0;j<n;j++){
        for(i=1;i<m;i++){
            for(k=1;k<=m-i;k++){
                if(mat[k][j]<mat[k-1][j]){
                    tmp=mat[k][j];
                    mat[k][j]=mat[k-1][j];
                    mat[k-1][j]=tmp;
                }
            }
        }
        printf("The largest no. of coloumn %d is: %d\n",j+1,mat[m-1][j]);
        printf("The smallest no. of coloumn %d is: %d\n",j+1,mat[0][j]);
        printf("\n");
    }
}
int main()
{
    int i,j,m,n,mat[10][10];
    printf("Enter the no. of rows & col.:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){ 
        scanf("%d",&mat[i][j]);
        }
    }
    row_sorting(mat,m,n);
    coloumn_sorting(mat,m,n);
    return 0;
}