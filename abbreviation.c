#include<stdio.h>
int main(){
    char name[100];
    int i,j,p=0,c=0,d=0;
    printf("Enter the name: ");
    scanf("%[^\n]",name);
    for(i=0;name[i]!='\0';i++){
        if(name[i]==' ') p++;
    }
    for(i=0;name[i]!='\0';i++){
        if(name[i]=='.') d=1;
    }
    if(d==0){
        printf("%c. ",name[0]);
        for(i=0;name[i]!='\0';i++){
            if(name[i]==' '){
                if(p==1){
                    for(j=i+1;name[j]!='\0';j++){
                        printf("%c",name[j]);
                    }
                }
                else{
                c++;
                if(c<p){
                    printf("%c. ",name[i+1]);
                }
                else if(c==p){
                    for(j=i+1;name[j]!='\0';j++) printf("%c",name[j]);
                }
                }
            }
        }
    }
    else
    {
    if(p==1) printf("%s",name);
    else{
    for(i=0;name[i]!='\0';i++){
        if(name[i]==' '){
            c++;
            if(name[i-1]=='.'){
                for(j=0;j<=i+1;j++){
                    if(j<=i) printf("%c",name[j]);
                    else printf("%c. ",name[j]);
                }
            }
            else if(c<p){
                printf("%c. ",name[i+1]);
            }
            else if(c==p){
                for(j=i+1;name[j]!='\0';j++) printf("%c",name[j]);
            }
        }
    }
    }
    }
    return 0;
}