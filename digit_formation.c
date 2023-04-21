#include<stdio.h>
#include<math.h>
void main()
{
    int i,p,l,digit=0,a[1000];
    printf("Enter the length of the no.:\n");
    scanf("%d",&l);
    printf("Enter the array elements:\n");
    for(i=0;i<l;i++)
    scanf("%d",&a[i]);
    for(i=0,p=l-1;i<l,p>=0;i++,p--)
    digit+=a[i]*(pow(10,p));
    printf("The digit is:%d",digit);
}