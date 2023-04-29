#include<stdio.h>
#include<stdbool.h>

int stack1[10], stack2[10];
int top1 = -1, top2 = -1;
int size = 10;

bool Empty1(){
    if(top1 == -1) return true;
    else return false;
}

bool Empty2(){
    if(top2 == -1) return true;
    else return false;
}

bool Full1(){
    if(top1 == size-1) return true;
    else return false;
}

bool Full2(){
    if(top2 == size-1) return true;
    else return false;
}

void push1(int data){
    top1++;
    stack1[top1] = data;
    return;
}

void push2(int data){
    top2++;
    stack2[top2] = data;
    return;
}

int pop1(){
    int data;
    data = stack1[top1];
    top1--;
    return data;
}

int pop2(){
    int data;
    data = stack2[top2];
    top2--;
    return data;
}

void enqueue(){
    int data;
    while(!Empty1()){
        data = pop1();
        push2(data);
    }
    if(Full2()) printf("\nQueue is full.");
    else{
        printf("\nGive the data for enqueue:");
        scanf("%d",&data);
        push2(data);
    }
    while(!Empty2()){
        data = pop2();
        push1(data);
    }
    return;
}

void dequeue(){
    int data;
    if(Empty1()) printf("\nQueue is empty.");
    else{
        data = pop1();
        printf("\n%d is deleted from queue.",data);
    }
    return;
}

void display(){
    if(Empty1()) printf("\nQueue is empty.");
    else{
        printf("\nQueue is: ");
        for(int i = 0;i <= top1;i++) printf("%d ",stack1[i]);
    }
    return;
}

int main(){
    int choice,flag = 1;
    printf("\nGive 1 for enqueue.");
    printf("\nGive 2 for dequeue.");
    printf("\nGive 3 for display.");
    printf("\nGive 4 for exit.");
    while(flag == 1){
        printf("\n\nGive your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: enqueue();
            break;
        case 2: dequeue();
            break;
        case 3: display();
            break;
        case 4: flag = 0;
            break;
        }
    }
    printf("\nProgram ended...");
}