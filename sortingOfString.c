#include<stdio.h>
int main(){
    char n[100];
    char c,tmp;
    int i=0,j,l;
    printf("\nEnter the string: ");
    while(c!='\n'){
        c=getchar();
        n[i]=c;
        i++;
    }
    i--;
    l=i;
    n[i]='\0';
    for(i=1;i<l;i++){
        for(j=1;j<=l-i;j++){
            if(n[j]<n[j-1]){
                tmp=n[j];
                n[j]=n[j-1];
                n[j-1]=tmp;
            }
        }
    }
    printf("The sorted string is: %s",n);
    return 0;
}