#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#include<stdlib.h>

struct message{
    char buffer[50];
    int count;
    sem_t mutex;
};

void *counter(void *arg){
    struct message *msg = (struct message*)arg;
    sem_wait(&msg->mutex);
    msg->count = 0;
    for(int i = 0; msg->buffer[i] != '\0'; i++){
        if(msg->buffer[i] != '\n') msg->count++;
    }
}

int main(){
    struct message msg;
    pthread_t tid;
    sem_init(&msg.mutex, 0, 0);
    pthread_create(&tid, NULL, counter, &msg);
    printf("\nString: ");
    scanf("%s", msg.buffer);
    sem_post(&msg.mutex);
    pthread_join(tid, NULL);
    printf("\nCharacter count: %d", msg.count);
    sem_destroy(&msg.mutex);
    return 0;
}
