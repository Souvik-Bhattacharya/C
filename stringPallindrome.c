#include<stdio.h>
int main(){
    char st[100],c;
    int i=0,j,n,flag=0;
    printf("Enter the string: ");
    while(c!='\n'){
        c=getchar();
        st[i]=c;
        i++;
    }
    i--;
    st[i]='\0';
    n=i;
    for(i=0,j=n-1;i<n,j>=0;i++,j--){
        if(st[i]!=st[j]){
            flag=1;
            break;
        }
    }
    if(flag==0) printf("That is pallindrome!\n");
    else printf("That is not pallindrome!");
    return 0;
}