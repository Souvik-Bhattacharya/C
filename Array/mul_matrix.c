#include<stdio.h>
int main(){
    int mat1[10][10],mat2[10][10];
    int m1,m2,n1,n2,i,j,k,sum;
    L:
    printf("Enter the dimensions of 1st matrix: ");
    scanf("%d%d",&m1,&n1);
    printf("Enter the dimensions of 2nd matrix: ");
    scanf("%d%d",&m2,&n2);
    if(n1!=m2){
        printf("Invlid dimensions for mul.\n");
        goto L;
    }
    printf("Enter the elements of 1st matrix:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n1;j++) scanf("%d",&mat1[i][j]);
    }
    printf("Enter the elements of 2nd matrix:\n");
    for(i=0;i<m2;i++){
        for(j=0;j<n2;j++) scanf("%d",&mat2[i][j]);
    }
    printf("The mutiplied matrix is:\n");
    for(i=0;i<m1;i++){
        for(j=0;j<n2;j++){
            sum=0;
            for(k=0;k<n1;k++){
                sum+=(mat1[i][k])*(mat2[k][j]);
            }
            printf("%d ",sum);
        }
        printf("\n");
    }
    return 0;
}