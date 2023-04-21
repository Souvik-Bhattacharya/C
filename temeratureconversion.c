#include<stdio.h>
int main()
{
    int d=0;
    float a,b;
    char ch;
    while(d==0)
    {
        printf("Please input c to convert into farenheihte , else input f !\n");
        scanf(" %c",&ch);
        printf("Please input the temperature !\n");
        scanf("%f",&a);
        if(ch=='c'||ch=='C')
        {
            b=((a/5)*9)+32;
            printf("The F value of temperature is %.2f",b);
            d+=1;
        }
        else if(ch=='f'||ch=='F')
        {
            b=((a-32)/9)*5;
            printf("The C value of temperature is %.2f",b);
            d+=1;
        }
        else
        {
            printf("Invalid mode,please give a suitable mode of temperature !\n");
            d+=0;
        }
    }
    return 0;
}