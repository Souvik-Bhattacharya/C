#include<stdio.h>
#include<math.h>
int main()
{
    int num,dummy;
    int i=0,count=0,sum=0,a;
    printf("Enter number: ");
    scanf("%d",&num);
    dummy=num;
    while(dummy!=0){
        dummy/=10;
        count++;
    }
    while(num!=0){
        a=num%10;
        sum+=a*pow(10,count-1);
        count--;
        num/=10;
    }
    printf("rev_num:%d",sum);
    return 0;
}