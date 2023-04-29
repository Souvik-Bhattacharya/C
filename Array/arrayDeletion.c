#include<stdio.h>

void deletion(int * arr,int size,int pos){
    int i;
    for(i=pos-1;i<size-1;i++)
    arr[i]=arr[i+1];
}

int main(){
    int size,arr[50],i,j,pos;

    printf("Enter the size of array:");
    scanf("%d",&size);
    printf("Enter the array elements:\n");
    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);
    printf("Enter the position of element:");
    scanf("%d",&pos);

    deletion(arr,size,pos);

    printf("The new array is:\n");
    for(j=0;j<size-1;j++)
    printf("%d ",arr[j]);

    return 0;
}