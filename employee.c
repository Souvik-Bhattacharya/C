#include<stdio.h>
#include<string.h>
struct directory{
    char name[100];
    int id;
    char designation[100];
    float salary;
};
int main()
{
    struct directory employee[100];
    int n,i,c=0,d;
    char name[100];
    printf("Enter the no. of employees to be considered: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the name of employee %d:\n",i+1);
        scanf("%s",employee[i].name);
        printf("Enter the id of employee %d:\n",i+1);
        scanf("%d",&employee[i].id);
        printf("Enter the designation of employee %d:\n",i+1);
        scanf("%s",employee[i].designation);
        printf("Enter the salary of employee %d:\n",i+1);
        scanf("%f",&employee[i].salary);
    }
    printf("Name   id    designation       salary\n");
    for(i=0;i<n;i++){
        printf("%s   %d     %s        %.1f\n",employee[i].name,employee[i].id,employee[i].designation,employee[i].salary);
    }
    R:
    printf("Enter the name you want to know about: ");
    scanf("%s",name);
    for(i=0;i<n;i++){
        c=0;
        if(strcmp(name,employee[i].name)==0){
            printf("The salary is:%.1f\n",employee[i].salary);
            c=1;
            break;
        }
    }
    if(c==0)
    printf("Name do not exist\n");
    printf("Do you want to search more? 0/1 :");
    scanf("%d",&d);
    if(d==1) goto R;
    else printf("Thank you!!");
    return 0;
}