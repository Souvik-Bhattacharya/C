#include<stdio.h>
#include<math.h>
int main()
{
    int time;
    float initial,rate,si,ci;
    printf("Please ! Enter values in the order of initial_value , interest_rate and time :\n");
    scanf("%f%f%d",&initial,&rate,&time);
    si = ((initial*rate)*time)/100;
    ci = initial*(pow(1+(rate/100),time))-initial;
    printf("The simple_interest is %f\n",si);
    printf("The compound_interest is %f\n",ci);
    return 0;
}