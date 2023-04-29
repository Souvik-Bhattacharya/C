#include<stdio.h>
#include<string.h>
void main()
{
    int i,length,l,n;
    char a[1000],tmp;
    printf("Enter the array elements:\n");
    scanf("%s",a);
    length=strlen(a);
    // It rotates the array in clockwise direction
    printf("Enter the no. of rotation:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        l=length-1;
        tmp=a[l];
        while(a[l]!=a[0])
        {
            a[l]=a[l-1];
            l=l-1;
        }
        a[0]=tmp;
    }
    printf("The rotated array is: %s",a);
}