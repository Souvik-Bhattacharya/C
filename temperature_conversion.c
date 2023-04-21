#include<stdio.h>
int main()
{
    float a,b;
    char ch;
    printf("Please input c to convert into f , else input f !\n");
    scanf("%c",&ch);
    printf("Please input the temperature !\n");
    scanf("%f",&a);
    if(ch=='c'||ch=='C')
    {
        b=((a/5)*9)+32;
        printf("The F value of temperature is %f",b);
    }
    else if(ch=='f'||ch=='F')
    {
        b=((a-32)/9)*5;
        printf("The C value of temperature is %f",b);
    }
    else
    {
        printf("Invalid mode,please give a suitable mode of temperature !\n");
    }
    return 0;
}