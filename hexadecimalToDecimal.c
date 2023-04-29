#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int n,i;
    long int sum=0;
    char hex[10000];
    printf("Enter the HEX. no.");
    scanf("%s",hex);
    n = strlen(hex);
    for(i=0;i<n;i++)
    {
        if(hex[i]=='0') sum+=(0*(pow(16,(n-1-i))));
        if(hex[i]=='1') sum+=(1*(pow(16,(n-1-i))));
        if(hex[i]=='2') sum+=(2*(pow(16,(n-1-i))));
        if(hex[i]=='3') sum+=(3*(pow(16,(n-1-i))));
        if(hex[i]=='4') sum+=(4*(pow(16,(n-1-i))));
        if(hex[i]=='5') sum+=(5*(pow(16,(n-1-i))));
        if(hex[i]=='6') sum+=(6*(pow(16,(n-1-i))));
        if(hex[i]=='7') sum+=(7*(pow(16,(n-1-i))));
        if(hex[i]=='8') sum+=(8*(pow(16,(n-1-i))));
        if(hex[i]=='9') sum+=(9*(pow(16,(n-1-i))));
        if(hex[i]=='A') sum+=(10*(pow(16,(n-1-i))));
        if(hex[i]=='B') sum+=(11*(pow(16,(n-1-i))));
        if(hex[i]=='C') sum+=(12*(pow(16,(n-1-i))));
        if(hex[i]=='D') sum+=(13*(pow(16,(n-1-i))));
        if(hex[i]=='E') sum+=(14*(pow(16,(n-1-i))));
        if(hex[i]=='F') sum+=(15*(pow(16,(n-1-i))));
    }
    printf("The decimal no. is: %ld",sum);
    return 0;
}