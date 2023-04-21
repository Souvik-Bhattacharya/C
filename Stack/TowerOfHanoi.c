#include<stdio.h>

void TOH(int n, char a, char b, char c){
    if(n > 0){
        TOH(n - 1, a, c, b);
        printf("%d is transfered from %c to %c\n", n, a, c);
        TOH(n - 1, b, a, c);
    }
    return;
}

int main(){
    int n;
    char a = 'A', b = 'B', c = 'C';
    printf("Enter the no of disks in the column %c:", a);
    scanf("%d", &n);
    printf("The path of transfer is as follows:\n");
    TOH(n, a, b, c);
    return 0;
}