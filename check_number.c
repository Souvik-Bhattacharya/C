#include<stdio.h>
int main()
{
    float number;
    printf("Enter a valid number :\n");
    scanf("%f",&number);
    (number>0)?(printf("The given number %f is a positive number!",number)):((number<0)?(printf("The given number %f is a negative number!")):(printf("You have entered zero!")));
    return 0;
}