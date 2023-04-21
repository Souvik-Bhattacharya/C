#include<stdio.h>
struct dict{
    char name[100];
    float marks;
};

void append(struct dict *s,FILE *p){
    printf("Enter the name of student:\n");
    scanf("%s",s->name);
    printf("Enter the mark's of student:\n");
    scanf("%f",&s->marks);
    fprintf(p,"%s %f",s->name,s->marks);
}
int main()
{
    int i,d,n;
    char filename[100];
    struct dict student;
    FILE *f;
    printf("Enter filename: ");
    scanf("%s",filename);
    f=fopen(filename,"a+");
    do{
        append(&student,f);
        printf("%s has been inserted\n",student.name);
        printf("Do you want to append more? 0/1:");
        scanf("%d",&d);
    }while(d==1);
    n=ftell(f);
    fclose(f);
    f=fopen(filename,"r");
    printf("This file %s contains:\n",filename);
    while(ftell(f)<n){
        fscanf(f,"%s %f",student.name,&student.marks);
        fprintf(stdout,"name:%s  mark's:%f\n",student.name,student.marks);
    }
    return 0;
}