#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter the three values of sides:\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a+b>c && b+c>a && c+a>b)
    {
        printf("The triangle exists.");
    }
    else
    {
        printf("The triangle doesn't exist.");
    }
    return 0;
}