#include<stdio.h>
#include<stdlib.h>
void adding(char num[100],int n){
    int no,j,sum=0;
    no=atoi(num);
    while(no!=0){
        sum+=no%10;
        no/=10;
    }
    printf("%d",sum);
}
int main()
{
    char num[100],c;
    int n,i=0;
    while(c!='\n'){
        c=getchar();
        num[i]=c;
        i++;
    }
    i--;
    n=i;
    num[i]='\0';
    adding(num,n);
    return 0;
}