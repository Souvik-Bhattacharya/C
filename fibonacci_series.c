#include<stdio.h>
void main()
{
    int n1=0,n2=1,l,sum=0,count=0;
    printf("Enter the end limit of the series:\n");
    scanf("%d",&l);
    printf("%d,%d,",n1,n2);
    while(count<(l-2))
    {
        sum = n1+n2;
        n1 = n2;
        n2 = sum;
        printf("%d,",sum);
        count+=1;
    }
}