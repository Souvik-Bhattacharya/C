#include<stdio.h>
int main()
{
    int n,sum;
    printf("Enter the number:\n");
    scanf("%d",&n);
    sum = 0;
    while(n!=0)
    {
        sum+=(n%10);
        n/=10;
    }
    printf("The sum of the digits is %d",sum);
    return 0;
}