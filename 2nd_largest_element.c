#include<stdio.h>
#include<string.h>
void main()
{
    int i,j,l;
    char a[1000],tmp;
    printf("Enter the array:\n");
    scanf("%s",a);
    l=strlen(a);
    for(i=1;i<l;i++)
    {
        for(j=1;j<=l;j++)
        {
            if(a[j]<a[j-1])
            {
                tmp=a[j-1];
                a[j-1]=a[j];
                a[j]=tmp;
            }
        }
    }
    for(i=l-1;i>=0;i--)
    {
        if(a[i]!=a[i-1])
        {
            printf("The 2nd largest element is %c",a[i-1]);
            break;
        }
    }
}