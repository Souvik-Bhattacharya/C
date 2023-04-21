#include<stdio.h>
#include<stdlib.h>
int main(){
    char i[100];
    int j;
    L:
    printf("Enter: ");
    scanf(" %[^\n]",i);
    if((j=atoi(i))==0){
        printf("Wrong data type input!plz reenter!\n");
        goto L; 
    }
    printf("%d",j);
    return 0;
}