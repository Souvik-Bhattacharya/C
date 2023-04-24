#include<stdio.h>

float totalProfit = 0.0;
int jobSequence[25] = {0};

typedef struct job{
    int id;
    float profit;
    int deadline;
} job;

void display(int maxDeadline){
    printf("\nMaximum profit is %f", totalProfit);
    printf("\nThe final optimal job sequence is:");
    for(int i = 1; i <= maxDeadline; i++) printf(" J%d", jobSequence[i]);
}

void sort(int n, job jobs[]){
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(jobs[j].profit > jobs[i].profit){
                job temp = jobs[j];
                jobs[j] = jobs[i];
                jobs[i] = temp;
            }
        }
    }
}

void jobSchedulingWithDeadline(int n, job jobs[]){
    int maxDeadline = 0, jobCount = 0, deadline;
    for(int i = 1; i <= n; i++){
        if(jobs[i].deadline > maxDeadline) maxDeadline = jobs[i].deadline;
    }
    sort(n, jobs);
    for(int i = 1; i <= n; i++){
        deadline = jobs[i].deadline;
        while(deadline >= 1){
            if(jobSequence[deadline] == 0){
                jobSequence[deadline] = jobs[i].id;
                totalProfit += jobs[i].profit;
                jobCount++;
                break;
            }
            deadline--;
        }
        if(jobCount == maxDeadline) break;
    }
    display(maxDeadline);
}

int main(){
    job jobs[25];
    int n;
    printf("\nEnter the no of jobs:");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        printf("\nEnter the profit and deadline of job %d:", i);
        scanf("%f %d", &jobs[i].profit, &jobs[i].deadline);
        jobs[i].id = i;
    }
    jobSchedulingWithDeadline(n, jobs);
    return 0;
}