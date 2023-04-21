#include<stdio.h>
#define student 4
#define question 10
int main()
{
    char answers[question + 1] , response[question + 1];
    int i,j,k,l,m,o,p,q,count,n,C[question];
    printf("Enter the correct string of options:\n");
    for(i=0;i<question;++i)
    {
        scanf("%c",&answers[i]);
    }
    answers[i]='\0';
    for(j=1;j<=student;++j)
    {
        printf("\n");
        printf("Enter the response of student-%d:\n",j);
        for(k=0;k<question;++k)
        {
            scanf(" %c",&response[k]);
        }
        response[k]='\0';
        for(l=0;l<question;++l)
        {
            C[l]=0;
        }
        count=0;
        for(m=0;m<question;++m)
        {
            if(answers[m]==response[m])
            {
                count+=1;
                C[m]=1;
            }
        }
        printf("\n");
        printf("The correct answers are:\n");
        for(o=0;o<question;++o)
        {
            printf(" %c ",answers[o]);
        }
        printf("\n");
        printf("The responses of student-%d:\n",j);
        for(p=0;p<question;++p)
        {
            printf(" %c ",response[p]);
        }
        printf("\n");
        printf("For student-%d\n",j);
        printf("The score is %d/%d\n",count,question);
        printf("The incorrect questions' no,s are:\n");
        n=0;
        for(q=0;q<question;++q)
        {
            if(C[q]==0)
            {
                printf("%d",q+1);
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