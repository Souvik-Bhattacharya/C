#include<stdio.h>
#include<stdlib.h>

int top = -1;
int maxsize = 10;

int stackFull(){
    if(top == maxsize-1) return 1;
    else return 0;
}

int stackEmpty(){
    if(top == -1) return 1;
    else return 0;
}

void display(int stack[]){
    int i;
    printf("The updated stack is: ");
    for(i=0;i<=top;i++) printf("%d ",stack[i]);
    printf("\n");
    return;
}

void push(int stack[]){
    if(stackFull()==1){
        printf("Stack is full\n");
    }
    else{
        top += 1;
        printf("Enter the new value:");
        scanf("%d",&stack[top]);
        display(stack);
    }
    return;
}

void pop(int stack[]){
    if(stackEmpty()==1){
        printf("Stack is empty\n");
    }
    else{
        printf("%d is popped from the stack!\n",stack[top]);
        top -= 1;
        if(top == -1) printf("Stack is now empty\n");
        else display(stack);
    }
    return;
}

int main(){
    int stack[maxsize], c;
    L:
    printf("Enter 1 for push, 2 for pop & 3 for exit:");
    scanf("%d",&c);
    switch(c){
        case 1:
        push(stack);
        goto L;
        case 2:
        pop(stack); 
        goto L;
        case 3: break;
    }
    return 0;
}