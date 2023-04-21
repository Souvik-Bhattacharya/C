#include<stdio.h>
#include<stdbool.h>

struct priority_queue
{
    int data;
    int priority;
}queue[5];

int front = 0, rear = 0;

bool isEmpty(){
    if(rear == front) return true;
    else return false;
}

bool isFull(){
    if(rear == 5) return true;
    else return false;
}

void insert(){
    int data, priority;
    if(isFull()) printf("\n Queue is full");
    else{
        printf("\n Enter the element to insert:");
        scanf("%d",&data);
        printf("\n Enter the priority of the element:");
        scanf("%d",&priority);
        queue[rear].data = data;
        queue[rear].priority = priority;
        rear++;
        printf("\n %d is inserted...", data);
    }
    return;
}

int getHighestPriority(){
    int priority = -1, i;
    for(i = front; i < rear; i++){
        if(queue[i].priority > priority) priority =  queue[i].priority;
    }
    return priority;
}

int delete(){
    int highestpriority, data, i, j;
    highestpriority = getHighestPriority();
    for(i = front;i < rear; i++){
        if(queue[i].priority == highestpriority){
            data = queue[i].data;
            break;
        }
    }
    if(i > front){
        for(j = i; j > front; j--){
            queue[j].data = queue[j - 1].data;
            queue[j].priority = queue[j - 1].priority;
        }
    }
    front++;
    return data;
}

void display(){
    int i;
    if(isEmpty()) printf("\n The queue is empty");
    else{
        printf("\n The priority queue is: ");
        for(i = front; i < rear; i++) printf("( data = %d - priority = %d )", queue[i].data, queue[i].priority);
    }
    return;
}

int main(){
    int c, data;
    L:
    printf("\n Enter 1 for insert, 2 for delete, 3 for display, 4 exit:");
    scanf("%d",&c);
    switch (c)
    {
    case 1:
        insert();
        goto L;
    case 2:
        if(isEmpty()) printf("\n The queue is empty");
        else{
            data = delete();
            printf("\n %d is deleted from the queue", data);
        }
        goto L;
    case 3:
        display();
        goto L;
    case 4:
        printf("\n Program ended...");
        break;
    default:
        printf("\n Invalid choice...");
        goto L;
    }
    return 0;
}