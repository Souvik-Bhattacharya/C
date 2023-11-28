#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define SIZE 10

void sender(int pipeDes1[], int pipeDes2[]){
    int randomArray[SIZE];
    int highestNumber;
    srand(time(0));
    for(int i = 0; i < SIZE; i++){
        randomArray[i] = rand() % 100;
    }
    
    write(pipeDes1[1], randomArray, sizeof(randomArray));
    
    read(pipeDes2[0], &highestNumber, sizeof(highestNumber));
    printf("\nThe highest number is %d", highestNumber);
}

void receiver(int pipeDes1[], int pipeDes2[]){
    int randomArray[SIZE];
    int highestNumber;

    read(pipeDes1[0], randomArray, sizeof(randomArray));

    highestNumber = randomArray[0];
    for(int i = 1; i < SIZE; i++){
        if(randomArray[i] > highestNumber){
            highestNumber = randomArray[i];
        }
    }

    write(pipeDes2[1], &highestNumber, sizeof(highestNumber));
}

int main(){
    int pipeDes1[2], pipeDes2[2];
    int status1, status2;
    int pid;

    status1 = pipe(pipeDes1);
    if(status1 == -1){
        printf("\nPipe 1 creation failed");
        return 1;
    }

    status2 = pipe(pipeDes2);
    if(status2 == -1){
        printf("\nPipe 2 creation failed");
        return 1;
    }

    pid = fork();

    if(pid > 0){
        close(pipeDes1[0]);
        close(pipeDes2[1]);
        sender(pipeDes1, pipeDes2);
        close(pipeDes1[1]);
        close(pipeDes2[0]);
    }
    else if(pid == 0){
        close(pipeDes1[1]);
        close(pipeDes2[0]);
        receiver(pipeDes1, pipeDes2);
        close(pipeDes1[0]);
        close(pipeDes2[1]);
    }
    else printf("\nFork failed");
    return 0;
}