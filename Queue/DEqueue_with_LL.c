#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue{
    int data;
    struct queue *next;
};
typedef struct queue node;

node *front = NULL, *rear = NULL;

bool qEmpty(){
    if(front == NULL || rear == NULL) return true;
    else return false;
}

void display(){
    node *temp;
    if(qEmpty()) printf("The queue is empty!\n");
    else{
        temp = front;
        printf("The updated queue is: ");
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    return;
}

void enqueueFront(){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the new data:");
    scanf("%d",&temp->data);
    if(qEmpty()){
        front = rear = temp;
        temp->next = NULL;
    }else{
        temp->next = front;
        front = temp;
    }
    display();
    return;
}

void enqueueRear(){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the new data:");
    scanf("%d",&temp->data);
    temp->next = NULL;
    if(qEmpty()) front = rear = temp;
    else{
        rear->next = temp;
        rear = rear->next;
    }
    display();
    return;
}

void dequeueFront(){
    node *temp;
    if(qEmpty()) printf("The queue is empty!\n");
    else{
        temp = front;
        printf("%d is deleted from the queue!\n",front->data);
        front = front->next;
        free(temp);
        display();
    }
    return;
}

void dequeueRear(){
    node *temp, *junk;
    if(qEmpty()) printf("The queue is empty!\n");
    else{
        printf("%d is deleted from the queue!\n",rear->data);
        if(front == rear){
            junk = rear;
            free(junk);
            rear = NULL;
        }else{
            temp = front;
            while(temp->next != rear) temp = temp->next;
            rear = temp;
            junk = temp->next;
            free(junk);
            temp->next = NULL;
        }
        display();
    }
    return;
}

int main(){
    int c;
    L:
    printf("Enter 1 for enqueue at front, 2 for enqueue at rear, 3 for dequeue at front, 4 for dequeue at rear & 5 for exit:");
    scanf("%d",&c);
    switch(c){
        case 1:
        enqueueFront();
        goto L;
        case 2:
        enqueueRear(); 
        goto L;
        case 3:
        dequeueFront();
        goto L;
        case 4:
        dequeueRear();
        goto L;
        case 5: break;
    }
    return 0;
}