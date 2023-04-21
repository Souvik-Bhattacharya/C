#include<stdio.h>

int arr[100];
int size;

void display(){
    int i;
    printf("The sorted array is: ");
    for(i = 0;i < size;i++) printf("%d ",arr[i]);
    printf("\n");
    return;
}

void heap_sort(){
    int p, c1, c2, r = size - 1, temp;
    while(r != 0){
        temp = arr[0];
        arr[0] = arr[r];
        arr[r] = temp;
        r--;
        p = 0;
        while(p <= ((r + 1)/2 -1)){
            c1 = 2*(p + 1) - 1;
            c2 = 2*(p + 1);
            if(c1 <= r && c2 <= r){
                if(arr[c1] >= arr[c2]){
                    if(arr[p] < arr[c1]){
                        temp = arr[p];
                        arr[p] = arr[c1];
                        arr[c1] = temp;
                        p = c1;
                    }
                    else break;
                }
                else{
                    if(arr[p] < arr[c2]){
                        temp = arr[p];
                        arr[p] = arr[c2];
                        arr[c2] = temp;
                        p = c2;
                    }
                    else break;
                }
            }
            else if(c1 <= r && c2 > r){
                if(arr[p] < arr[c1]){
                    temp = arr[p];
                    arr[p] = arr[c1];
                    arr[c1] = temp;
                    p = c1;
                }
                else break;
            }
        }        
    }
    return;
}

int main(){
    int i;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    printf("Enter the array elements for a max heap:\n");
    for(i = 0;i < size;i++) scanf("%d",&arr[i]);
    heap_sort();
    display();
    return 0;
}