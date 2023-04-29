#include<stdio.h>
#define student 5
#define question 10
int main()
{
    /*          declaring variables         */
    char answers[question+1] , responses[student+1][question+1];
    int i,j,count,n,C[question];
    /*             taking inputs            */
    printf("Enter the correct options:\n");
    for(i=0;i<question;++i)
    {
        scanf("%c",&answers[i]);
    }
    answers[i]='\0';
    for(i=0;i<student;++i)
    {
        printf("\nEnter the response of student-%d:\n",i+1);
        for(j=0;j<question;++j)
        {
            scanf(" %c",&responses[i][j]);
        }
        responses[i][j]='\0';
    }
    /*      printing the tabulation     */
    printf("\n  TABLE OF CORRECT ANSWERS");
    printf("\n______________________________\n");
    printf("|  qNo  |");
    for(i=1;i<=question;++i)
    {
        printf("%d|",i);
    }
    printf("\n______________________________\n");
    printf("|corrAns|");
    for(i=0;i<question;++i)
    {
        printf("%c|",answers[i]);
    }
    printf("\n______________________________\n");
    printf("     TABLE OF RESPONSES");
    printf("\n______________________________\n");
    printf("|sNo\\qNo|");
    for(i=1;i<=question;++i)
    {
        printf("%d|",i);
    }
    printf("\n_____________________________\n");
    for(i=0;i<student;++i)
    {
        printf("|   %d   |",i+1);
        for(j=0;j<question;++j)
        {
           printf("%c|",responses[i][j]); 
        }
        printf("\n_____________________________\n");
    }
    /*      printing indivisual results     */
    for(i=0;i<student;++i)
    {
        for(j=0;j<question;++j)
        {
            C[j]=0;
        }
        count=0;
        for(j=0;j<question;++j)
        {
            if(answers[j]==responses[i][j])
            {
                count+=1;
                C[j]=1;
            }
        }
        printf("\nFor student-%d\n",i+1);
        printf("The score is %d/%d\n",count,question);
        printf("The incorrect questions' no,s are:\n");
        n=0;
        for(j=0;j<question;++j)
        {
            if(C[j]==0)
            {
                printf("%d,",j+1);
                n+=1;
            }
        }
        if(n==0)
        {
            printf(" NIL");
        }
    }
    return 0;
}