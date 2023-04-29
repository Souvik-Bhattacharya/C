#include<stdio.h>
int size;

int linear_search(int arr[], int i, int k){
    int index;
    if(arr[i] == k) index = i;
    else{
        if(i != size - 1) index = linear_search(arr,i + 1,k);
        else index = -1;
    }
    return index;
}

int main(){
    int i, arr[100], key, index;
    printf("Enter the array size:");
    scanf("%d",&size);
    printf("Enter the array elements:\n");
    for(i = 0;i < size;i++) scanf("%d",&arr[i]);
    printf("Enter the element for searching:");
    scanf("%d",&key);
    i = 0;
    index = linear_search(arr,i, key);
    if(index != -1) printf("%d is present in the array at the position %d\n",key,index+1);
    else printf("%d is not present in the array!\n",key);
    return 0;
}