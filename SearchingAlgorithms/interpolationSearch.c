#include<stdio.h>

int interpolation_search(int arr[], int low, int high, int k){
    int point, index = -1;
    if(low <= high){
        point = low + ((k - arr[low])*(high - low))/(arr[high] - arr[low]);
        if(arr[point] == k) return point;
        else if(k < arr[point]) index = interpolation_search(arr,low,point - 1,k);
        else index = interpolation_search(arr,point + 1,high,k);
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
    index = interpolation_search(arr,0,size - 1,key);
    if(index != -1) printf("%d is present in the array at the position %d\n",key,index+1);
    else printf("%d is not present in the array!\n",key);
    return 0;
}