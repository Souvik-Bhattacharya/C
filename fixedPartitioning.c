#include<stdio.h>

int p, n;
int allocation[50];

struct block{
    int size;
    int allocated;
};

void initialize(struct block partitions[]){
    for(int i = 0; i < p; i++){
        partitions[i].allocated = 0;
    }
}

void show(){
    printf("\nProcess no\t\tBlock no\n");
    for(int i = 0; i < n; i++){
        if(allocation[i] != -1) printf("%d\t\t\t%d\n", i, allocation[i]);
        else printf("%d\t\t\t%s\n", i, "Not allocated");
    }
}

void firstFit(struct block partitions[], int processes[]){
    initialize(partitions);

    for(int i = 0; i < n; i++){
        int allocated = 0;
        for(int j = 0; j < p; j++){
            if(!partitions[j].allocated && processes[i] <= partitions[j].size){
                partitions[j].allocated = 1;
                allocation[i] = j;
                allocated = 1;
                break;
            }
        }
        if(!allocated){
            allocation[i] = -1;
        }
    }

    printf("\nFirst fit table:\n");
    show();
}

void bestFit(struct block partitions[], int processes[]){
    initialize(partitions);

    for(int i = 0; i < n; i++){
        int diff = __INT_MAX__;
        int index = -1;
        for(int j = 0; j < p; j++){
            if(!partitions[j].allocated && processes[i] <= partitions[j].size){
                if(partitions[j].size - processes[i] < diff){
                    diff = partitions[j].size;
                    index = j;
                } 
            }
        }
        if(index == -1){
            allocation[i] = -1;
        }
        else{
            partitions[index].allocated = 1;
            allocation[i] = index;
        }
    }

    printf("\nBest fit table:\n");
    show();
}

void worstFit(struct block partitions[], int processes[]){
    initialize(partitions);

    for(int i = 0; i < n; i++){
        int diff = -1;
        int index = -1;
        for(int j = 0; j < p; j++){
            if(!partitions[j].allocated && processes[i] <= partitions[j].size){
                if(partitions[j].size - processes[i] > diff){
                    diff = partitions[j].size;
                    index = j;
                } 
            }
        }
        if(index == -1){
            allocation[i] = -1;
        }
        else{
            partitions[index].allocated = 1;
            allocation[i] = index;
        }
    }

    printf("\nWorst fit table:\n");
    show();
}

int main(){
    struct block partitions[50];
    int processes[50];

    printf("\nEnter no of partitions: ");
    scanf("%d", &p);

    printf("\nGive size of the partitions:\n");
    for(int i = 0; i < p; i++){
        scanf("%d", &partitions[i].size);
        partitions[i].allocated = 0;
    }

    printf("\nEnter no of process: ");
    scanf("%d", &n);

    printf("\nGive size of the processes:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &processes[i]);
    }

    firstFit(partitions, processes);
    bestFit(partitions, processes);
    worstFit(partitions, processes);
}