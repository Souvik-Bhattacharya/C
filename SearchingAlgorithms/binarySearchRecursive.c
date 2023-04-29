#include<stdio.h>

int binary_search(int arr[], int low, int high, int k){
    int mid, index = -1;
    if(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == k) return mid;
        else if(k < arr[mid]) index = binary_search(arr,low,mid - 1,k);
        else index = binary_search(arr,mid + 1,high,k);
    }
    return index;
}

int main(){
    int size, key, i, arr[100], index;
    printf("Enter the array size:");
    scanf("%d",&size);
    printf("Enter the array elements:\n");
    for(i = 0;i < size;i++) scanf("%d",&arr[i]);
    printf("Enter the element for searching:");
    scanf("%d",&key);
    index = binary_search(arr,0,size - 1,key);
    if(index != -1) printf("%d is present in the array at the position %d\n",key,index+1);
    else printf("%d is not present in the array!\n",key);
    return 0;
}