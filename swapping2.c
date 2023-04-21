#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter the two numbers:\n");
    scanf("%d%d",&a,&b);
    c = a;
    a = b;
    b = c;
    printf("The two numbers are: %d,%d",a,b);
    return 0;
}