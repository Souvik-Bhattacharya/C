#include <stdio.h>
int main()
{
    int questionsNo = 3 , studentsNo = 5;
    int actual[questionsNo] , answers[studentsNo][questionsNo] , c , ch;
    int i,j;
    printf("Enter the correct option no:\n");
    for(i=0;i<questionsNo;i++)
    {
        scanf("%d",&actual[i]);
    }
    printf("\n");
    printf("Enter the answers:\n");
    for(i=0;i<studentsNo;i++)
    {
        for(j=0;j<questionsNo;j++)
        {
            scanf("%d",&answers[i][j]);
        }
    }
    printf("| ");
    printf("qNo/roll");
    printf(" |");
    for(i=1;i<=questionsNo;i++)
    {
        printf(" %d |",i);
    }
    printf("\n");
    printf("________________________");
    printf("\n");
    for(i=0;i<studentsNo;i++)
    {
        printf("|  Roll:%d  |",i+1);
        for(j=0;j<questionsNo;j++)
        {
            printf(" %d |",answers[i][j]); 
        }
        printf("\n");
        printf("________________________\n");
    }
    return 0;
}