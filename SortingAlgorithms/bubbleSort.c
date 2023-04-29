#include<stdio.h>

void bubble(int arr[],int n){
    int i,j,temp;
    for(i = 0;i<n-1;i++){
        for(j = 0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;
}

int main(){
    int arr[50], size, i;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the elements of the array:\n");
    for(i = 0;i<size;i++) scanf("%d",&arr[i]);
    bubble(arr,size);
    printf("The sorted array is: ");
    for(i = 0;i<size;i++) printf("%d ",arr[i]);
    return 0;
}