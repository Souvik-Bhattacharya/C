#include<stdio.h>
int main()
{
    int i,j,n,count;
    printf("Enter the limiting value:\n");
    scanf("%d",&n);
    printf("The prime numbers between 1 to %d are:\n",n);
    for(i=2;i<=n;++i)
    {
        count = 0;
        for(j=1;j<=i;++j)
        {
            if(i%j==0)
            {
                count+=1;
            }
        }
        if(count==2)
        {
            printf("%d,",i);
        }
    }
    return 0;
}