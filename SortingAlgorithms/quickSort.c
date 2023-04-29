#include<stdio.h>

void display(int arr[],int n){
    int i;
    printf("The sorted array is: ");
    for(i = 0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return;
}

int partition(int arr[],int low,int high){
    int i,j,pivot,temp;
    pivot = arr[low];
    i = low + 1;
    j = high;
    do{
        while(arr[i] <= pivot){
            if(i == high) break;
            else i++;
        }
        while(arr[j] > pivot) j--;
        if(i < j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i < j);
    if(arr[j] != pivot){
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
    }
    return j;
}

void quick_sort(int arr[],int low,int high){
    int partition_index;
    if(low<high){
        partition_index = partition(arr,low,high);
        quick_sort(arr,low,partition_index-1);
        quick_sort(arr,partition_index+1,high);
    }
    return;
}

int main(){
    int arr[50], size, i;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the elements of the array:\n");
    for(i = 0;i<size;i++) scanf("%d",&arr[i]);
    quick_sort(arr,0,size-1);
    display(arr,size);
    return 0;
}