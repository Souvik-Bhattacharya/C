#include<stdio.h>

void insertion(int * arr,int size,int pos,int ele){
    int i;
    for(i=size-1;i>=pos-1;i--)
    arr[i+1]=arr[i];
    arr[pos-1]=ele;
}

int main(){
    int size,arr[50],i,j,pos,ele;

    printf("Enter the size of array:");
    scanf("%d",&size);
    printf("Enter the array elements:\n");
    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);
    printf("Enter the position of element:");
    scanf("%d",&pos);
    printf("Enter the element:");
    scanf("%d",&ele);

    insertion(arr,size,pos,ele);

    printf("The new array is:\n");
    for(j=0;j<=size;j++)
    printf("%d ",arr[j]);

    return 0;
}