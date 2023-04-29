#include<stdio.h>
#include<ctype.h>

int main(){
    char st[100],c;
    int vc=0,cc=0,i=0,n;
    printf("Enter the sentence: ");
    scanf("%[^\n]",st);
    for(i=0;st[i]!='\0';i++){
        if(isalpha(st[i])){
            if(st[i]=='A'||st[i]=='E'||st[i]=='I'||st[i]=='O'||st[i]=='U') vc++;
            else if(st[i]=='a'||st[i]=='e'||st[i]=='i'||st[i]=='o'||st[i]=='u') vc++;
            else cc++;
        }
    }
    printf("vowels:%d consonant:%d",vc,cc);
    return 0;
}