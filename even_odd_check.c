#include<stdio.h>
int main()
{
    int number;
    printf("Please ! Enter an integer number to check :\n");
    scanf("%d",&number);
    (number%2 == 0)?(printf("The given number %d is an even number !",number)):(printf("The given number %d is an odd number !",number));
    return 0;
}