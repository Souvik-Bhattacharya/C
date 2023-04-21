#include<stdio.h>
#include<math.h>
int fac(int p)
{
    int x;
    if(p==0) return 1;
    else x=p*fac(p-1);
    return x;
}
int main()
{
    int r,i,j,k,y,a,b,c;
    printf("Enter the no. of rows of triangle:\n");
    scanf("%d",&r);
    printf("The Pascal's trinagle for %d rows is:\n",r);
    for(i=0;i<r;i++)
    {
        for(k=0;k<r-1-i;k++)
        printf(" ");
        for(j=0;j<=i;j++)
        {
            a=fac(i);
            b=fac(j);
            y=i-j;
            c=fac(y);
            printf("%Ld",(a/(b*c)));
            if(j!=i) printf(" ");
        }
        printf("\n");
    }
    return 0;
}