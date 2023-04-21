#include<stdio.h>
int main()
{
    float a,b,c;
    printf("Enter three valid number :\n");
    scanf("%f%f%f",&a,&b,&c);
    if(a>b && a>c)
    {
        printf("The largest number is %f",a);
    }
    else if(b>c && b>a)
    {
        printf("The largest number is %f",b);

    }
    else if(c>a && c>b)
    {
        printf("The largest number is %f",c);

    }
    else
    {
        printf("The given numbers are equal");

    }
    return 0;
}