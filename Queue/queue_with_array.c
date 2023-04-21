#include<stdio.h>
#include<stdbool.h>

int maxsize;
int front = 0, rear = 0;

void display(int q[]){
    int i;
    printf("The updated queue is: ");
    for(i = front;i < rear;i++) printf("%d ",q[i]);
    printf("\n");
    return;
}

bool qFull(){
    if(rear == maxsize) return true;
    else return false;
}

bool qEmpty(){
    if(rear == front) return true;
    else return false;
}

void insert(int q[]){
    if(qFull()) printf("The queue is full!\n");
    else{
        printf("Enter the new data:");
        scanf("%d",&q[rear]);
        rear++;
        display(q);
    }
    return;
}

void delete(int q[]){
    if(qEmpty()) printf("The queue is empty!\n");
    else{
        printf("%d is deleted from the queue\n",q[front]);
        front++;
        if(front != rear) display(q);
        else printf("Now queue is empty!\n");
    }
    return;
}

int main(){
    int queue[100],c;
    printf("Enter the maxsize:");
    scanf("%d",&maxsize);
    L:
    printf("Enter 1 for insert, 2 for delete, 3 for exit:");
    scanf("%d",&c);
    switch (c){
    case 1:
        insert(queue);
        goto L;
    case 2:
        delete(queue);
        goto L;
    case 3: break;}
    return 0;
}