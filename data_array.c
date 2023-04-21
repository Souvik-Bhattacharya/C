#include <stdio.h>
int main()
{
    int questionsNo = 3 , studentsNo = 5;
    char actual[questionsNo+1] , answers[studentsNo+1][questionsNo+1];
    int i,j;
    printf("Enter the correct options:\n");
    for(i=0;i<questionsNo;i++)
    {
        scanf("%c",&actual[i]);
    }
    actual[i] = '\0';
    printf("\n");
    printf("Enter the answers:\n");
    for(i=0;i<studentsNo;i++)
    {
        for(j=0;j<questionsNo;j++)
        {
            scanf(" %c",&answers[i][j]);
        }
        answers[i][j] = '\0';
    }
    printf("\nThe correct answers are:\n");
    for(i=0;i<questionsNo;++i)
    {
        printf(" %c",actual[i]);
    }
    printf("\n");
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
            printf(" %c |",answers[i][j]); 
        }
        printf("\n");
        printf("________________________\n");
    }
    return 0;
}