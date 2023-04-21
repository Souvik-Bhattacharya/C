#include<stdio.h>

void selection_sort(int arr[],int n){
    int i,j,minVal,minInd,temp;
    for(i = 0;i<n-1;i++){
        minVal = arr[i];
        minInd = i;
        for(j = i;j<n;j++){
            if(arr[j]<minVal){
                minVal = arr[j];
                minInd = j;
            }
        }
        if(minVal != arr[i]){
            temp = arr[i];
            arr[i] = minVal;
            arr[minInd] = temp;
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
    selection_sort(arr,size);
    printf("The sorted array is: ");
    for(i = 0;i<size;i++) printf("%d ",arr[i]);
    return 0;
}