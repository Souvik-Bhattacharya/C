#include<stdio.h>
int count=1;
void fib(int a,int b,int n){
    if(count<=n-2){
    printf("%d",a+b);
    if(count<n-2) printf(",");
    count++;
    fib(b,a+b,n);
    }
}
int main(){
    int a,b,n;
    a=0;
    b=1;
    printf("Enter the limit: ");
    scanf("%d",&n);
    printf("The fibonacci series for %d no. is:\n",n);
    printf("%d,%d,",a,b);
    fib(a,b,n);
    return 0;
}