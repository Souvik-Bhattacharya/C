#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,x,y,d;
    printf("Enter valid a , b ,c coefficients :\n");
    scanf("%f%f%f",&a,&b,&c);
    d = (b*b)-4*(a*c);
    if (d<0)
    {
        printf("There are two imaginary roots");
    }
    else if (d == 0)
    {
        x = ((-b)+sqrt(d))/(2*a);
        y = x;
        printf("There are two equal roots %f,%f",x,y);
    }
    else
    {
        x = ((-b)+sqrt(d))/(2*a);
        y = ((-b)-sqrt(d))/(2*a);
        printf("The two distinct roots are %f,%f",x,y);
    }
    return 0;
}