#include<stdio.h>

void insertion_sort(int arr[],int n){
    int i,j,val;
    for(i = 1;i<n;i++){
        val = arr[i];
        for(j = i-1;j>=0;j--){
            if(arr[j]>val){
                arr[j+1] = arr[j];
                arr[j] = val;
            }
            else break;
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
    insertion_sort(arr,size);
    printf("The sorted array is: ");
    for(i = 0;i<size;i++) printf("%d ",arr[i]);
    return 0;
}