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
    if(front == NULL) return true;
    else return false;
}

void display(){
    node *temp;
    if(qEmpty()) printf("The queue is empty!\n");
    else{
        printf("The updated queue is: ");
        temp = front;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    return;
}

void insert(){
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

void delete(){
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

int main(){
    int c;
    L:
    printf("Enter 1 for insert, 2 for delete & 3 for exit:");
    scanf("%d",&c);
    switch(c){
        case 1:
        insert();
        goto L;
        case 2:
        delete(); 
        goto L;
        case 3: break;
    }
    return 0;
}