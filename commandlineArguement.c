#include<stdio.h>
int main(int argc, char* argv[])
{
    int i,n;
    char word[100];
    FILE *f;
    printf("Total no. of arguements is %d\n",argc);
    f=fopen(argv[1],"w");
    for(i=2;i<argc;i++){
        fprintf(f,"%s",argv[i]);
    }
    n=ftell(f);
    fclose(f);
    printf("The file %s contains:\n",argv[1]);
    f=fopen(argv[1],"r");
    for(i=0;i<argc;i++){
        fscanf(f,"%s",word);
        fprintf(stdout,"%.*s\n",i*3,word);
    }
    return 0;
}