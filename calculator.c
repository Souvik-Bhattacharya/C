#include<stdio.h>
int main()
{
    int num1,num2;
    char ch;
    printf("Enter the 1st number:\n");
    scanf("%d",&num1);
    printf("Enter the character from (%%+-*/):\n");
    scanf(" %c",&ch);
    printf("Enter the 2nd number:\n");
    scanf("%d",&num2);
    switch(ch)
    {
        case '+': printf("The sum is %d",num1+num2);break;
        case '-': printf("The subtraction is %d",num1-num2);break;
        case '*': printf("The product is %d",num1*num2);break;
        case '/': printf("The division is %d",num1/num2);break;
        case '%': printf("The modulo is %d",num1%num2);break;
        default: printf("Invalid Operator!");break;
    }
    return 0;
}