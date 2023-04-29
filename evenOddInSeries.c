#include<stdio.h>
int main()
{
    int i,n;
    printf("Enter the limiting value:\n");
    scanf("%d",&n);
    printf("The even numbers between %d are:\n",n);
    for(i=0;i<=n;i+=2)
    {
        printf("%d\n",i);
    }
    printf("The odd numbers between %d are:\n",n);
    for(i=1;i<=n;i+=2)
    {
        printf("%d\n",i);
    }
    return 0;
}