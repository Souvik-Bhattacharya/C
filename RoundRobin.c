#include<stdio.h>

int readyq[50];
int front = 0, rear = 0;

void enqueue(int pid){
    readyq[rear] = pid;
    rear++;
}

int dequeue(){
    int pid = readyq[front];
    front++;
    return pid;
}

int main(){
    int p, arrival[50], burst[50], turnaround[50], waiting[50], arrived[50] = {0}, clock = 0, tq, bt[50];
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

    printf("\nEnter time quantum: ");
    scanf("%d", &tq);

    for(int i = 0; i < p; i++){
        if(!arrived[i] && arrival[i] <= clock){
            enqueue(i);
            arrived[i] = 1;
        }
    }

    int flag = 0;
    while(flag < p){
        int pid = dequeue();

        if(bt[pid] > tq){
            bt[pid] = bt[pid] - tq;
            clock = clock + tq;
        }
        else{
            clock = clock + bt[pid];
            bt[pid] = 0;
            turnaround[pid] = clock - arrival[pid];
            waiting[pid] = turnaround[pid] - burst[pid];
            flag++;
        }

        for(int i = 0; i < p; i++){
            if(!arrived[i] && arrival[i] <= clock){
                enqueue(i);
                arrived[i] = 1;
            }
        }

        if(bt[pid] != 0) enqueue(pid);
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