#include<stdio.h>

int create(int arr[]){
    int size,i;
    printf("Enter size:");
    scanf("%d",&size);
    printf("Enter the elements:\n");
    for(i = 0;i<size;i++) scanf("%d",&arr[i]);
    return size;
}

void display(int arr[],int n){
    int i;
    printf("The sorted array is: ");
    for(i = 0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");
    return;
}

void pass(int arr[],int n,int exp){
    int count[10],result[n],i;
    for(i = 0;i<10;i++) count[i] = 0;
    for(i = 0;i<n;i++) count[(arr[i]/exp)%10] += 1;
    for(i = 1;i<10;i++) count[i] += count[i-1];
    i = n-1;
    while(i>=0){
        result[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10] -= 1;
        i--;
    }
    for(i = 0;i<n;i++) arr[i] = result[i];
    return;
}

void radix_sort(int arr[],int n){
    int exp = 1;
    int max = arr[0];
    int i;
    for(i = 1;i<n;i++){
        if(arr[i]>max) max = arr[i];
    }
    while(max/exp >= 1){
        pass(arr,n,exp);
        exp *= 10;
    }
    return;
}

int main(){
    int arr[50],size;
    size = create(arr);
    radix_sort(arr,size);
    display(arr,size);
    return 0;
}