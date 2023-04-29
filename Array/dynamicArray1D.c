#include<stdio.h>
#include<stdlib.h>

void insertion(int *arr,int size,int pos,int ele){
    int i;
    arr=(int *)realloc(arr,size+1);
    for(i=size-1;i>=pos-1;i--)
    arr[i+1]=arr[i];
    arr[pos-1]=ele;
}

void deletion(int * arr,int size,int pos){
    int i;
    for(i=pos-1;i<size;i++)
    arr[i]=arr[i+1];
    arr=(int *)realloc(arr,size);
}

int main(){
    int size,*arr,i,j,k,pos_in,pos_del,ele;

    printf("Enter the size of array:");
    scanf("%d",&size);
    arr=(int *)malloc(size*(sizeof(int)));
    printf("Enter the array elements:\n");
    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);
    
    printf("Enter the position of element to be inserted:");
    scanf("%d",&pos_in);
    printf("Enter the element:");
    scanf("%d",&ele);

    insertion(arr,size,pos_in,ele);

    printf("The new array after insertion is:\n");
    for(j=0;j<=size;j++)
    printf("%d ",arr[j]);
    
    printf("\nEnter the position of element to be deleted:");
    scanf("%d",&pos_del);
    
    deletion(arr,size,pos_del);
    
    printf("The new array after deletion is:\n");
    for(k=0;k<size;k++)
    printf("%d ",arr[k]);

    free(arr);
    
    return 0;
}