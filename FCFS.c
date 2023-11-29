#include<stdio.h>
#include<limits.h>

int main(){
    int p, arrival[50], burst[50], turnaround[50], waiting[50], clock = 0, bt[50];
    float avgta, avgwt;

    printf("\nEnter no of process: ");
    scanf("%d", &p);

    printf("\nEnter arrival times: ");
    for(int i = 0; i < p; i++) scanf("%d", &arrival[i]);

    printf("\nEnter burst time: ");
    for(int i = 0; i < p; i++){
        scanf("%d", &burst[i]);
        bt[i] = burst[i];
    }

    int flag = 0;
    while(flag < p){
        for(int i = 0; i < p; i++){
            if(arrival[i] <= clock && bt[i] != 0){
                clock = clock + bt[i];
                bt[i] = 0;
                turnaround[i] = clock - arrival[i];
                waiting[i] = turnaround[i] - burst[i];
                flag++;
                break;
            }
        }

    }

    int totaltt = 0;
    int totalwt = 0;
    for(int i = 0; i < p; i++){
        totaltt += turnaround[i];
        totalwt += waiting[i];
    }

    avgta = totaltt * 1.0/p;
    avgwt = totalwt * 1.0/p;

    printf("\nProcess\tArrival\tBurst\tTurnaround\tWaiting\n");
    for(int i = 0; i < p; i++) printf("%d\t%d\t%d\t%d\t\t%d\n", i, arrival[i], burst[i], turnaround[i], waiting[i]);

    printf("\nAverage turn around time: %.2f", avgta);
    printf("\nAverage waiting time: %.2f", avgwt);

    return 0;
}