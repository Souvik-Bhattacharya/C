#include<stdio.h>
#include<stdbool.h>

int maxsize;
int front = 0, rear = 0;

bool qEmpty = true, qFull = false;

void display(int q[]){
    int i;
    printf("The updated queue is: ");
    for(i = 0;i < maxsize;i++) printf("%d ",q[i]);
    printf("\n");
    return;
}

void insert(int q[]){
    if(qFull == true) printf("The queue is full!\n");
    else{
        printf("Enter the new data:");
        scanf("%d",&q[rear]);
        rear = (rear + 1) % maxsize;
        qEmpty = false;
        if(rear == front) qFull = true;
        display(q);
    }
    return;
}

void delete(int q[]){
    if(qEmpty == true) printf("The queue is empty!\n");
    else{
        printf("%d is deleted from the queue\n",q[front]);
        q[front] = 0;
        front = (front + 1) % maxsize;
        qFull = false;
        if(front != rear) display(q);
        else{
            printf("Now queue is empty!\n");
            qEmpty = true;
        }
    }
    return;
}

int main(){
    int queue[100],c;
    printf("Enter the maxsize:");
    scanf("%d",&maxsize);
    for(int i = 0;i < maxsize;i ++) queue[i] = 0;
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