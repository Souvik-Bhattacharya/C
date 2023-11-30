#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

struct message{
    int number;
    int factorial;
    int reverse;
};

void *factorial(void *arg){
    struct message *msg = (struct message*)arg;
    int factorial = 1;
    for(int i = 1; i <= msg->number; i++){
        factorial *= i;
    }
    msg->factorial = factorial;
}

void *reverse(void *arg){
    struct message *msg = (struct message*)arg;
    int number = msg->number;
    int reverse = 0;
    while(number > 0){
        reverse = (reverse * 10) + (number % 10);
        number = number / 10;
    }
    msg->reverse = reverse;
}

int main(){
    struct message msg;
    pthread_t tidf, tidr;
    printf("\nNumber: ");
    scanf("%d", &msg.number);
    pthread_create(&tidf, NULL, factorial, &msg);
    pthread_create(&tidr, NULL, reverse, &msg);
    pthread_join(tidf, NULL);
    pthread_join(tidr, NULL);
    printf("\nFactorial: %d, Reverse: %d", msg.factorial, msg.reverse);
    return 0;
}
