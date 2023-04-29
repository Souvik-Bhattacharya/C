#include<stdio.h>
int main()
{
    int i,j,tmp,c=0,m,n,mat[10][10];
    printf("Enter no. of rows & col.:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    printf("The transpose of the matrix is:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d",mat[j][i]);
            if(j!=n-1) printf(" ");
        }
        printf("\n");
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(mat[i][j]==mat[j][i]) c+=1;
        }
    }
    if(c==(m*n)) printf("It's a symmetric matrix.");
    else printf("it's not a symmetric matrix.");
}