#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
typedef struct stack node;

node *top = NULL;

void display(){
    node *temp;
    temp = top;
    printf("The updated stack is: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void push(){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Enter the new data:");
    scanf("%d",&temp->data);
    temp->next = top;
    top = temp;
    display();
    return;
}

void pop(){
    node *temp;
    if(top == NULL) printf("Stack is empty\n");
    else{
        temp = top;
        printf("%d is popped from the stack\n",top->data);
        top = top->next;
        free(temp);
        if(top == NULL) printf("The stack is now empty\n");
        else display();
    }
    return;
}

int main(){
    int c;
    L:
    printf("Enter 1 for push, 2 for pop & 3 for exit:");
    scanf("%d",&c);
    switch(c){
        case 1:
        push();
        goto L;
        case 2:
        pop(); 
        goto L;
        case 3: break;
    }
    return 0;
}