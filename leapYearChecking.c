#include<stdio.h>
int main()
{
    int year,d;
    d=0;
    while(d==0)
    {
        printf("Enter a valid year :\n");
        scanf("%d",&year);
        if(year>0)
        {
            (year%400==0 || year%2!=0 && year%4==0)?(printf("The given year %d is a leap year!",year)):(printf("The given year %d is not a leap year!"));
            d+=1;
        }
        else
        {
            printf("Enter a year greater than zero!\n");
        }
    }
    return 0;
}